#include"Dog.h"
#include"Car.h"

int main(){
    Car myCar;
    myCar.accelerate();
    myCar.accelerate();
    myCar.accelerate();
    myCar.accelerate();
    myCar.accelerate();
    myCar.accelerate();  
    std::cout << "Speed in MPH:" << myCar.getSpeedInMPH() << std::endl;
    std::cout << "Speed in KPH" << myCar.getSpeedInKPH() << std::endl;
    myCar.brake();
    myCar.brake();
    std::cout << "Speed in MPH: " << myCar.getSpeedInMPH() << std::endl;
    std::cout << "Speed in KPH: " << myCar.getSpeedInKPH() << std::endl;

    Dog myDog;
    Dog randomDog(3,"Chip","Great Dane");
    std::cout << myDog.describe();
    std::cout << randomDog.describe();
    std::cout << myDog.flip() << myDog.shake();
    std::cout << randomDog.flip() << randomDog.shake();

}