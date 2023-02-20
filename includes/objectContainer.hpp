#ifndef OBJECTCONTAINER_H
#define OBJECTCONTAINER_H

#include "object.cpp"
#include "messageHandler.cpp"

#include <vector>
#include <iostream>

class ObjectContainer{
    
    private:
        std::vector<Object> objectCategori2;
        std::vector<Object> objectCategori1;
        MessageHandler messageHandler;


    public:
        ObjectContainer();
        ~ObjectContainer();
        
        bool checkIdIdExists(Object &object);
        void addObjectToContainer(Object &object);
        void updateObjectInContainer(Object &object, int distance);

        int sizeOfContainers();
        int sizeOfContainerCat1();
        int sizeOfContainerCat2();

        void outputObjects();
};


#endif