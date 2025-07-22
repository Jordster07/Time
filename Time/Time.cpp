#include "Time.h"
using namespace std;

Time::Time(): Time(0,0,0,0){

}

Time::Time(int day, int hour,int  minute, int second){
    this->day = day;
    this->hour = hour;
    this->minute= minute;
    this->second=second;
}

Time::Time(int hour, int minute, int second) {
    day = 0;
    this->hour = hour;
    this->minute = minute;
    this->second = second;
}

Time::Time(int hour, int minute) {
    day = 0;
    this->hour = hour;
    this->minute = minute;
    second = 0;
}

int Time::getDay() const {
    return day;
}

int Time::getHour() const {
    return hour;
}

int Time::getMinute() const {
    return minute;
}

int Time::getSecond() const {
    return second;
}

Time Time::operator+(const Time& other) const {
    Time result;

    result.second = this->second + other.second;
    result.minute = this->minute + other.minute;
    result.hour = this->hour + other.hour;
    result.day = this->day + other.day;

    if (result.second >= 60) {
        result.second -= 60;
        result.minute += 1;
    }

    if (result.minute >= 60) {
        result.minute -= 60;
        result.hour += 1;
    }

    if (result.hour >= 24) {
        result.hour -= 24;
        result.day += 1;
    }

    return result;
}

Time Time::operator-(const Time& other) const {
    Time result;

    result.second = this->second - other.second;
    result.minute = this->minute - other.minute;
    result.hour = this->hour - other.hour;
    result.day = this->day - other.day;

    if (result.second < 0) {
        result.second += 60;
        result.minute -= 1;
    }

    if (result.minute < 0) {
        result.minute += 60;
        result.hour -= 1;
    }

    if (result.hour < 0) {
        result.hour += 24;
        result.day -= 1;
    }

    return result;
}

bool Time::operator==(const Time& other) const {
    if (day == other.day &&
        hour == other.hour &&
        minute == other.minute &&
        second == other.second) {
        return true;
    } else {
        return false;
    }

}

bool Time::operator!=(const Time& other) const {
    return !(*this == other);
}

bool Time::operator<(const Time& other) const {
    if (day != other.day) return day < other.day;
    if (hour != other.hour) return hour < other.hour;
    if (minute != other.minute) return minute < other.minute;
    return second < other.second;
}

bool Time::operator>(const Time& other) const {
    return other < *this;
}

bool Time::operator<=(const Time& other) const {
    return !(other < *this);
}

bool Time::operator>=(const Time& other) const {
    return !(*this < other);
}

ostream& operator<<(ostream& os, const Time& time) {
    os << time.day << " days, "
       << time.hour << " hours, "
       << time.minute << " minutes, "
       << time.second << " seconds";
       return os;
}

int Time::toSeconds() const {
    return day * 86400 + hour * 3600 + minute * 60 + second;
}
