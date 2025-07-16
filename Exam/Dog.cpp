#include "Dog.h"

Dog::Dog():Dog(7,"Bowser","Pitbull"){

}

Dog::Dog(int age, std::string name, std::string breed): breed(breed){
    this->age = age;
    this->name = name;
}

int Dog::getAge(){
    return age;
}

int Dog::getAgeInDogYears(){
    return age*7;
}

std::string Dog::getName(){
    return name;
}

std::string Dog::getBreed(){
    return breed;
}

void Dog::setAge(int age){
    this->age=age;
}

void Dog::setName(std::string name){
    this->name=name;
}

std::string Dog::flip(){
    return name + " JUST DID A FLIP WOW\n";
}

std::string Dog::shake(){
    return name + " sticks out paw and shakes your hand :D\n";
}

std::string Dog::describe(){
    return "Your dog " + name + " is a "  + getBreed()  + " and is "
    + std::to_string(age) + " years old but they think they are " 
    + std::to_string(getAgeInDogYears()) + " years old\n";
}
