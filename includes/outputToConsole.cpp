#include "outputToConsole.hpp"

OutputToConsole::OutputToConsole(){
}

OutputToConsole::~OutputToConsole(){
}

double OutputToConsole::calculateTimeDifference(const std::chrono::steady_clock::time_point currentTime, const std::chrono::steady_clock::time_point previousTime)
{
    std::chrono::duration<double> timeDifference = currentTime - previousTime;
    return timeDifference.count();
}

void OutputToConsole::outputObjectsToConsole(int preamble, int count, ObjectContainer &ObjectContainer){
    std::cout << preamble << " " << "Numbers of objects " << count << std::endl;
    ObjectContainer.outputObjects();
}