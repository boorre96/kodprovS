#ifndef OBJECT_H
#define OBJECT_H

#include <cstdint>
#include <iostream>

class Object
{
private:
    long int Id;
    int XCord,YCord,Type;
    uint8_t Color[4] = {0x00,0x00,0x00,0x00};

public:
    Object();
    ~Object();

    void setValuesObject(long int id, int X, int Y, int type);
    void setColor(char color);
    void setXYCord(int xCord, int yCord);

    int getId();
    int getType();
    int getXCord();
    int getYCord();

    void outputInfo();
    void outputID();
    void outputXCord();
    void outputYCord();
    void outputType();
    
};


#endif