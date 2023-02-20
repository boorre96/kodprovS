#include "objectContainer.hpp"

ObjectContainer::ObjectContainer(){

}

ObjectContainer::~ObjectContainer(){

}

bool ObjectContainer::checkIdIdExists(Object &object){
    if (object.getType() == 1 || object.getType() == 2 ){
        if (this->sizeOfContainerCat1() < 1)
            return false;

        else{
            for(auto objectFromContainerCat1 : this->objectCategori1){
                if(objectFromContainerCat1.getId() == object.getId())
                    return true;               
            }
            return false;
        }
        
    } 
    else{
        if(this->sizeOfContainerCat2() < 1)
            return false;
        
        else{
            for (auto objectFromContainerCat2 : this->objectCategori2){
                if(objectFromContainerCat2.getId() == object.getId())
                    return true;
            }
        }
    }
    return false;
    
}

void ObjectContainer::addObjectToContainer(Object &object){
    if (object.getType() == 1 || object.getType() == 2){
        this->objectCategori1.push_back(object);
    }
    else{
        this->objectCategori2.push_back(object);
    }
}

void ObjectContainer::updateObjectInContainer(Object &object, int distance){
    if(object.getType() == 1 || object.getType() == 2){
        for (int i = 0; i < this->objectCategori1.size(); i+=1){
            if(this->objectCategori1[i].getId() == object.getId()){
                this->objectCategori1[i].setXYCord(object.getXCord(), object.getYCord());
                messageHandler.setColorOfObject(distance, this->objectCategori1[i]);
            }
        }
    }
    else{
        for (int i = 0; i < this->objectCategori2.size(); i+=1){
            if(this->objectCategori2[i].getId() == object.getId()){
                this->objectCategori2[i].setXYCord(object.getXCord(), object.getYCord());
                messageHandler.setColorOfObject(distance, this->objectCategori2[i]);
            }
        }
    }
}


int ObjectContainer::sizeOfContainers(){
    return this->objectCategori1.size() + this->objectCategori2.size();
}

int ObjectContainer::sizeOfContainerCat1(){
    return this->objectCategori1.size();
}

int ObjectContainer::sizeOfContainerCat2(){
    return this->objectCategori2.size();
}

void ObjectContainer::outputObjects(){
    
    std::cout << "Categori 1" << std::endl;
    for(auto objectFromContainerCat1 : this->objectCategori1){
        objectFromContainerCat1.outputInfo();
    }
    std::cout << "*******************************************" << std::endl;
    std::cout << "Categori 2" << std::endl;
    for(auto objectFromContainerCat2 : this->objectCategori2){
        objectFromContainerCat2.outputInfo();
    }
    std::cout << "*******************************************" << std::endl;
    
}
