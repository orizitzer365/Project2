//
// Created by ori on 1/8/19.
//

#ifndef PROJECT2_MYCLIENTHANDLER_H
#define PROJECT2_MYCLIENTHANDLER_H

#include "ClientHandler.h"

class MyClientHandler :ClientHandler{
public:
private:
    void handleClient(int port) override;
};


#endif //PROJECT2_MYCLIENTHANDLER_H
