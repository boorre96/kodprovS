#ifndef OUTPUTTOCONSOLE_H
#define OUTPUTTOCONSOLE_H

#include "objectContainer.cpp"

class OutputToConsole{
    private:
    
    public:
        OutputToConsole();
        ~OutputToConsole();

        void outputObjectsToConsole(int preamble, int count, ObjectContainer &ObjectContainer);
};


#endif 