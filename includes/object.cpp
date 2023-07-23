#include "object.hpp"

Object::Object(){
}

/**
 * The function sets the values of the object's id, x-coordinate, y-coordinate, and type.
 * 
 * @param id The id parameter is a long integer that represents the unique identifier of the object.
 * @param X The X parameter represents the X coordinate of the object's position.
 * @param Y The parameter "Y" represents the Y-coordinate of the object.
 * @param type The "type" parameter is an integer that represents the type of the object. It could be
 * used to differentiate between different types of objects in your program.
 */
void Object::setValuesObject(long int id, int X, int Y, int type){
     this->Id = id;
     this->XCord = X;
     this->YCord = Y;
     this->Type = type;

}

/**
 * The function sets the color of an object based on the input character.
 * 
 * @param color The parameter "color" is a character that represents the desired color. It can be 'R'
 * for red, 'Y' for yellow, or 'G' for green.
 */
void Object::setColor(char color){
    if (color == 'R'){
        this->Color[0] = 0x1B; 
        this->Color[1] = 0x5B; 
        this->Color[2] = 0x31;
        this->Color[3] = 0x6D;
    }
    else if(color == 'Y'){
        this->Color[0] = 0x1B; 
        this->Color[1] = 0x5B; 
        this->Color[2] = 0x33;
        this->Color[3] = 0x6D;
    }
    else if(color == 'G'){
        this->Color[0] = 0x1B; 
        this->Color[1] = 0x5B; 
        this->Color[2] = 0x32;
        this->Color[3] = 0x6D;
    }
}


void Object::setXYCord(int xCord, int yCord){
    this->XCord = xCord;
    this->YCord = yCord;
}

int Object::getId()
{
    return this->Id;
}

int Object::getType()
{
    return this->Type;
}

int Object::getXCord()
{
    return this->XCord;
}

int Object::getYCord()
{
    return this->YCord;
}

void Object::outputID(){
    std::cout << "ID=" << this->Id << std::endl;
}

void Object::outputXCord(){
    std::cout << "X=" << this->XCord << std::endl;
}

void Object::outputYCord(){
    std::cout << "Y=" << this->YCord << std::endl;
}

void Object::outputType(){
    std::cout << "Type=" << this->Type << std::endl;
}

/**
 * The function "outputInfo" prints information about an object, with different colors based on the
 * value of the "Color" variable.
 */
void Object::outputInfo(){
    
    if(this->Color[2] == '1'){
        std::cout << "\033[31m" << "ID="<< this->Id << " X=" << this->XCord << " Y=" 
        << this->YCord << " Type=" << this->Type << "\33[0m" << std::endl;
    }
    else if(this->Color[2] == '2'){
        std::cout << "\033[32m" << "ID="<< this->Id << " X=" << this->XCord << " Y=" 
        << this->YCord << " Type=" << this->Type << "\33[0m" << std::endl;
    }
    else if(this->Color[2] == '3'){
        std::cout << "\033[33m" << "ID="<< this->Id << " X=" << this->XCord << " Y=" 
        << this->YCord << " Type=" << this->Type << "\33[0m" << std::endl;
    }
}

Object::~Object(){
}
