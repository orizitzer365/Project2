//
// Created by ori on 1/14/19.
//
#include "MyParallelServer.h"
void worker(TasksQueue* queue){
    while (!queue->stop()) {
        queue->wait();

        Task* task = queue->pop();
        if (task) {
            task->execute();
            delete task;
        }
    }
}
void server_side::MyParallelServer::open(int port, ClientHandler *c) {
    std::queue<std::thread> workers;
    TasksQueue tasks_queue;

    for (int i = 0; i < THREAD_POOL_SIZE; ++i) {
        workers.push(std::thread(worker, &tasks_queue));
    }
    int s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(port);
    serv.sin_family = AF_INET;
    if (bind(s, (sockaddr *)&serv, sizeof(serv)) < 0)	{
        std::cerr << "Bad!" << std::endl;
    }

    int new_sock;
    listen(s, 5);
    struct sockaddr_in client;
    socklen_t clilen = sizeof(client);

    timeval timeout;
    while (true){
        timeout.tv_sec = 10;
        timeout.tv_usec = 0;

        setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
        new_sock = accept(s, (struct sockaddr*)&client, &clilen);
        if (new_sock < 0)	{
            if (errno == EWOULDBLOCK)	{
                std::cout << "timeout!" << std::endl;
                break;
            }	else	{
                perror("other error");
                exit(3);
            }
        }
        tasks_queue.push(new TaskHandleClient(c,new_sock));
    }

    tasks_queue.exit();
    while (!workers.empty()) {
        workers.front().join();
        workers.pop();
    }

}

