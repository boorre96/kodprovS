#include "outputToConsole.hpp"

OutputToConsole::OutputToConsole(){
}

OutputToConsole::~OutputToConsole(){
}

/**
 * The function calculates the time difference between two given time points.
 * 
 * @param currentTime A std::chrono::steady_clock::time_point representing the current time.
 * @param previousTime The previous time point that you want to calculate the time difference from.
 * 
 * @return the time difference between the current time and the previous time as a double value.
 */
double OutputToConsole::calculateTimeDifference(const std::chrono::steady_clock::time_point currentTime, const std::chrono::steady_clock::time_point previousTime)
{
    std::chrono::duration<double> timeDifference = currentTime - previousTime;
    return timeDifference.count();
}

/**
 * The function outputs the number of objects in an ObjectContainer to the console, along with a
 * preamble.
 * 
 * @param preamble The preamble is an integer value that represents some additional information or
 * context that you want to display before outputting the objects to the console. It could be any value
 * that you want to include in the output.
 * @param count The count parameter represents the number of objects in the ObjectContainer.
 * @param ObjectContainer ObjectContainer is a reference to an ObjectContainer object. It is used to
 * access the objects stored in the container and call the outputObjects() function on it.
 */
void OutputToConsole::outputObjectsToConsole(int preamble, int count, ObjectContainer &ObjectContainer){
    std::cout << preamble << " " << "Numbers of objects " << count << std::endl;
    ObjectContainer.outputObjects();
}