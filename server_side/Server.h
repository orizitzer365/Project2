//
// Created by ori on 1/8/19.
//

#ifndef PROJECT2_SERVER_H
#define PROJECT2_SERVER_H

#include "ClientHandler.h"

namespace server_side{
    class Server{
    public:
        virtual void open(int port,ClientHandler* c) = 0 ;
        virtual void stop() = 0 ;

    };
}
#endif //PROJECT2_SERVER_H
