#include "Car.h"

Car::Car() : Car("Toyota", "Camry", 2000)
{

}

Car::Car(std::string ma, std::string mo, int year){
    make = ma;
    model = mo;
    this->year=year;
    speed = 0;
}

std::string Car::getMake(){
    return make;
}

std::string Car::getModel(){
    return model;
}

int Car::getYear(){
    return year;
}

void Car::setMake(std::string ma){
    make = ma;
}

void Car::setModel(std::string mo){
    model = mo;
}

void Car::setYear(int year){
    this->year = year;
}

int Car::getSpeedInMPH(){
    return speed;
}

int Car::getSpeedInKPH(){
    return speed*1.60934;
}

void Car::accelerate(){
    speed = speed +5;
}

void Car::brake(){
    speed = speed - 5;
}