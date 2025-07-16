#ifndef CAR
#define CAR
#include<iostream>
#include<string>

class Car{
private:
    std::string make;
    std::string model;
    int year;
    int speed;
public:
    Car();
    Car(std::string ma, std::string mo, int year);
    std::string getMake();
    std::string getModel();
    int getYear();
    void setMake(std::string ma);
    void setModel(std::string mo);
    void setYear(int year);
    int getSpeedInMPH();
    int getSpeedInKPH();
    void accelerate();
    void brake();
};


#endif