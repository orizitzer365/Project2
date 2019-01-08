//
// Created by ori on 1/8/19.
//

#ifndef PROJECT2_MYSERIALSERVER_H
#define PROJECT2_MYSERIALSERVER_H

#include "Server.h"

namespace server_side{
    class MySerialServer:Server {
        void open(int port) override;

        void stop() override;

    public:

    };
}


#endif //PROJECT2_MYSERIALSERVER_H
