//
// Created by ori on 1/14/19.
//

#ifndef PROJECT2_MYPARALLELSERVER_H
#define PROJECT2_MYPARALLELSERVER_H

#include <atomic>
#include <condition_variable>
#include <mutex>
#include <queue>
#include <thread>
#include <bits/socket.h>
#include <bits/socket_type.h>
#include "Server.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <cstdlib>
#include <iostream>
#include <thread>

#define THREAD_POOL_SIZE 5

namespace server_side{

    class MyParallelServer:Server{
    public:
        void open(int port, ClientHandler *c) override;

        void stop() override {

        }
    };

}
class Task
{
public:
    virtual void execute() = 0;
};

class TasksQueue
{
    std::atomic<bool> stop_queue;
    std::queue<Task* > tasks;
    mutable std::condition_variable queue_cond_var;
    mutable std::mutex mut;
public:
    TasksQueue() {
        stop_queue = false;
    }
    Task* pop() {
        std::lock_guard<std::mutex> g(mut);
        if (tasks.empty()) {
            return nullptr;
        }
        auto task = tasks.front();
        tasks.pop();
        return task;
    }

    bool empty() const {
        std::lock_guard<std::mutex> g(mut);
        return tasks.empty();
    }

    void push(Task* task) {
        if (task == nullptr) {
            throw std::invalid_argument("Task should not be null");
        }
        std::lock_guard<std::mutex> g(mut);
        tasks.push(task);
        queue_cond_var.notify_one();
    }

    void wait() const {
        std::unique_lock<std::mutex> ul(mut);
        if (stop_queue) return;
        queue_cond_var.wait(ul);
    }

    bool stop() const {
        return stop_queue;
    }

    void exit() {
        std::lock_guard<std::mutex> g(mut);
        stop_queue = true;
        queue_cond_var.notify_all();
    }
};

class TaskHandleClient:public Task{
private:
    ClientHandler* clientHandler;
    int port;
public:
    TaskHandleClient(ClientHandler* &clientHandler,int port) : clientHandler(clientHandler) ,port(port){}
    void execute(){
       clientHandler->handleClient(port);
    }
    ~TaskHandleClient(){}
};

#endif //PROJECT2_MYPARALLELSERVER_H
