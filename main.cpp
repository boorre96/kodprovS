#include "includes/clientSocket.cpp"
#include "includes/outputToConsole.cpp"

#include <chrono>
#include <ctime>

int main(){
    int distance;
    OutputToConsole OutputToConsole;
    ObjectContainer objectContainer;
    MessageHandler messageHandle;
    ClientSocketWindows client;

    if(client.connectSocketToServerWIN())
    {   
        while (true)
        {
            client.recieveMessageFromServerWIN();
        }
        
        
    }
    
    
    
    //linux
    // ClientSocket client(5463);
    // if(client.connectToServer()){
    //     auto timeStart = std::chrono::steady_clock::now();
    //     while (true){

    //         char* message = client.recieveMessageFromServer();

    //         if(messageHandle.checkIfValidId(message)){
            
    //             Object object;
    //             messageHandle.splitMessageFromServer(message, object);
    //             distance = messageHandle.calculateDistance(object.getXCord(), object.getYCord());
    //             messageHandle.setColorOfObject(distance ,object);
                
    //             if (objectContainer.checkIdIdExists(object)){
    //                 objectContainer.updateObjectInContainer(object, distance);
    //             }
    //             else{
    //                 objectContainer.addObjectToContainer(object);
    //             }
    //         }
    //         auto end = std::chrono::steady_clock::now();
    //         std::chrono::duration<double> diff = end - timeStart;
            
    //         if(diff.count() >= 0.5){
    //             OutputToConsole.outputObjectsToConsole(0xFEFF, objectContainer.sizeOfContainers() ,objectContainer);
    //             timeStart = std::chrono::steady_clock::now();
    //         }
    //     }
    // }
    return 0;
}         
       
