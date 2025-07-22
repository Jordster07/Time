/*Make a class called Time
Time should have integer values for days, hours, minutes, seconds.
Time should have a constructor, and getters for each of these instance variables.
Default constructor would set all instance variables to 0;
Another constructor should take in days, hours, months, and seconds and a third to take in hours, minutes, seconds, and a final one to take in hours and minutes.*/

#ifndef TIME
#define TIME
#include<iostream>

class Time{
private:
    int day;
    int hour;
    int minute;
    int second;
public:
    int getDay() const;
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    Time();
    Time(int day, int hour,int  minute, int second);
    Time(int hour, int minute, int second);
    Time(int hour, int second);
    Time operator+(const Time& other) const;
    Time operator-(const Time& other) const;

    bool operator==(const Time& other) const;
    bool operator!=(const Time& other) const;
    bool operator<(const Time& other) const;
    bool operator>(const Time& other) const;
    bool operator<=(const Time& other) const;
    bool operator>=(const Time& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Time& time);

    int toSeconds() const;



};


#endif