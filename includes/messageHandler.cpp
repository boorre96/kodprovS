#include "messageHandler.hpp"

#define XSTART 150
#define YSTART 150

MessageHandler::MessageHandler(){
}

MessageHandler::~MessageHandler(){
}

int MessageHandler::calculateDistance(int xCord, int yCord)
{
    return distance = sqrt(pow((XSTART - xCord),2) + pow((YSTART - yCord), 2));
}

bool MessageHandler::checkIfValidId(char *message){
    
    int size = strlen(message);
    if(size < 31){
        return false;
    }
    else{
        char idCheck[] = "ID=";
        for (int i = 0; i < 3; i+=1){
            if(message[i] != idCheck[i])
                return false;
        }
        for (int i = 3; i <17 ; i+=1)
        {
            if (!isdigit(message[i]))
                return false;
        }
    }
    return true;    
}

void MessageHandler::splitMessageFromServer(char *message, Object &object){   

    char *stringFromServerId = strtok(message, "ID=;");
    long int Id = std::stoull(stringFromServerId);
                
    char *stringFromServerX = strtok(NULL, "X=;");
    int XCord = std::stoi(stringFromServerX);

    char *stringFromServerY = strtok(NULL, "Y=;");
    int YCord = std::stoi(stringFromServerY);
                
    char *stringFromServerType = strtok(NULL, "TYPE=;");
    int Type = std::stoi(stringFromServerType);

    object.setValuesObject(Id, XCord, YCord, Type);
}

void MessageHandler::setColorOfObject(int distance, Object &object){
    if (object.getType() == 1){
        if (distance >= 75){
            object.setColor('G');
        }
        else if (distance < 50){
            object.setColor('R');
        }
        else{
            object.setColor('Y');
        }
    }

    else if (object.getType() == 2){
        if (distance >= 50){
            object.setColor('G');
        }
        else{
            object.setColor('Y');
        }
    }

    else{
        if(distance >= 100){
            object.setColor('Y');
        }
        else{
            object.setColor('R');
        }
    }
}
