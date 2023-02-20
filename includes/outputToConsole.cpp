#include "outputToConsole.hpp"

OutputToConsole::OutputToConsole(){
}

OutputToConsole::~OutputToConsole(){
}

void OutputToConsole::outputObjectsToConsole(int preamble, int count, ObjectContainer &ObjectContainer){
    std::cout << preamble << " " << "Numbers of objects " << count << std::endl;
    ObjectContainer.outputObjects();
}