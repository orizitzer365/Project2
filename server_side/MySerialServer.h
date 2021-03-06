//
// Created by ori on 1/8/19.
//

#ifndef PROJECT2_MYSERIALSERVER_H
#define PROJECT2_MYSERIALSERVER_H

#include <thread>
#include "Server.h"

namespace server_side{
    class MySerialServer:public Server {
    private:
        int sock_id;
        bool stillRunning;
    public:
        MySerialServer();

        void open(int port,ClientHandler* c) override;

        void stop() override;


    };
}


#endif //PROJECT2_MYSERIALSERVER_H
