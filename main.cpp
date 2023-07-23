#include "includes/clientSocket.cpp"
#include "includes/outputToConsole.cpp"

#include <chrono>
#include <ctime>
#include <thread>
#include <mutex>


std::mutex criticalLock;
int distance;
OutputToConsole outputToConsole;
ObjectContainer objectContainer;
MessageHandler messageHandle;
ClientSocketWindows client;

void consolePrintThread(){
    auto previousTime = std::chrono::steady_clock::now();
    auto currentTime = std::chrono::steady_clock::now();
    while(true){
        double intervall = outputToConsole.calculateTimeDifference(currentTime, previousTime);
        if(intervall >= 1.5){
            std::cout << intervall << std::endl;
            outputToConsole.outputObjectsToConsole(0xFEFF, objectContainer.sizeOfContainers() ,objectContainer);
            previousTime = std::chrono::steady_clock::now();
        }
        currentTime = std::chrono::steady_clock::now();
    }
}
void messageProcessThread(){
    while (true){
        char* message = client.recieveMessageFromServerWIN();
            
        if(messageHandle.checkIfValidId(message)){
            Object object;
            messageHandle.splitMessageFromServer(message, object);
            distance = messageHandle.calculateDistance(object.getXCord(), object.getYCord());
            messageHandle.setColorOfObject(distance ,object);

            /* have to lock the objectContainer somehow */
            if (objectContainer.checkIdIdExists(object)){
                objectContainer.updateObjectInContainer(object, distance);
            }
            else{
                objectContainer.addObjectToContainer(object);
            }
        }
    }
}

int main(){


    if(client.connectSocketToServerWIN())
    {
        std::thread consoleThread(consolePrintThread);   
        std::thread messageThread(messageProcessThread);
        
        messageThread.join();
        consoleThread.detach();

        // while (true){
        //     char* message = client.recieveMessageFromServerWIN();
            
        //     if(messageHandle.checkIfValidId(message)){
            
        //         Object object;
        //         messageHandle.splitMessageFromServer(message, object);
        //         distance = messageHandle.calculateDistance(object.getXCord(), object.getYCord());
        //         messageHandle.setColorOfObject(distance ,object);
                
        //         if (objectContainer.checkIdIdExists(object)){
        //             objectContainer.updateObjectInContainer(object, distance);
        //         }
        //         else{
        //             objectContainer.addObjectToContainer(object);
        //         }
        //     }
        // }
    }
    return 0;

    
    
    /*
    Linux
    ClientSocket client(5463);
    if(client.connectToServer()){
        auto timeStart = std::chrono::steady_clock::now();
        while (true){

            char* message = client.recieveMessageFromServer();

            if(messageHandle.checkIfValidId(message)){
            
                Object object;
                messageHandle.splitMessageFromServer(message, object);
                distance = messageHandle.calculateDistance(object.getXCord(), object.getYCord());
                messageHandle.setColorOfObject(distance ,object);
                
                if (objectContainer.checkIdIdExists(object)){
                    objectContainer.updateObjectInContainer(object, distance);
                }
                else{
                    objectContainer.addObjectToContainer(object);
                }
            }
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> diff = end - timeStart;
            
            if(diff.count() >= 0.5){
                OutputToConsole.outputObjectsToConsole(0xFEFF, objectContainer.sizeOfContainers() ,objectContainer);
                timeStart = std::chrono::steady_clock::now();
            }
        }
    }
    */
}         
       
