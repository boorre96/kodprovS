#include "object.hpp"

Object::Object(){
}

void Object::setValuesObject(long int id, int X, int Y, int type){
     this->Id = id;
     this->XCord = X;
     this->YCord = Y;
     this->Type = type;

}

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
