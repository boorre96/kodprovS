
#include "messageHandler.hpp"

#define XSTART 150
#define YSTART 150

MessageHandler::MessageHandler(){
}

MessageHandler::~MessageHandler(){
}

/**
 * The calculateDistance function calculates the distance between two points using the Pythagorean
 * theorem.
 * 
 * @param xCord The x-coordinate of the point you want to calculate the distance to.
 * @param yCord The y-coordinate of the point for which you want to calculate the distance.
 * 
 * @return The distance calculated between the given coordinates (xCord, yCord) and the starting
 * coordinates (XSTART, YSTART).
 */
int MessageHandler::calculateDistance(int xCord, int yCord)
{
    return distance = sqrt(pow((XSTART - xCord),2) + pow((YSTART - yCord), 2));
}

/**
 * The function checks if a given message has a valid ID format.
 * 
 * @param message A character array representing a message.
 * 
 * @return a boolean value.
 */
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

/**
 * The function `splitMessageFromServer` takes a message from the server and splits it into different
 * parts to set the values of an object.
 * 
 * @param message A character array containing the message received from the server. The message is
 * expected to be in the format "ID=;X=;Y=;TYPE=;", where each value is separated by a semicolon (;).
 * @param object The "object" parameter is a reference to an instance of the Object class. It is used
 * to set the values of the object based on the data extracted from the "message" parameter.
 */
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

/**
 * The function sets the color of an object based on its type and the distance provided.
 * 
 * @param distance The distance parameter represents the distance of the object from a reference point.
 * @param object The "object" parameter is of type "Object", which is a user-defined class.
 */
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
