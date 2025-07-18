#include"Highlander.h"

int Highlander::count = 0;

Highlander::Highlander(){
    name = " ";
    count ++;
}

Highlander::Highlander(std::string name){
    this->name = name;
    count++;
}

Highlander::~Highlander(){
    --count;
}

std::string Highlander::speak() {
        return "There can be only one. But now there are " + std::to_string(count);
    }


std::string Highlander::status() {
        if (count == 1) return "Immortal";
        else return "Murderous";
    }