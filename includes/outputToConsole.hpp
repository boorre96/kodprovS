#ifndef OUTPUTTOCONSOLE_H
#define OUTPUTTOCONSOLE_H

#include "objectContainer.cpp"
#include <chrono>

class OutputToConsole{
    private:
    
    public:
        OutputToConsole();
        ~OutputToConsole();

        double calculateTimeDifference(const std::chrono::steady_clock::time_point currentTime,
                                       const std::chrono::steady_clock::time_point previousTime);

        void outputObjectsToConsole(int preamble, int count, ObjectContainer &ObjectContainer);
};


#endif 