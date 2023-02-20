#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H
#include <cmath>
#include <string.h>
#include "object.hpp"


class MessageHandler{
    private:
        int distance = 0;

    public:
        MessageHandler();
        ~MessageHandler();
        int calculateDistance(int xCord, int yCord);
        
        bool checkIfValidId(char *message);

        void splitMessageFromServer(char *message, Object &object);
        void setColorOfObject(int distance ,Object &object);
};

#endif