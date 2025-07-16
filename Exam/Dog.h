#ifndef DOG
#define DOG
#include<iostream>
#include<string>

class Dog{
private:
    int age;
    std::string name;
    const std::string breed;
public:
    Dog();
    Dog(int age, std::string name, std::string breed);
    int getAge();
    int getAgeInDogYears();
    std::string getName();
    std::string getBreed();
    void setAge(int age);
    void setName(std::string name);
    std::string describe();
    std::string flip();
    std::string shake();
};

#endif