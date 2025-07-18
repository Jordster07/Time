#ifndef HIGHLANDER
#define HIGHLANDER
#include<string>
#include<iostream>

class Highlander{
private:
std::string name;
static int count;
public:
Highlander();
Highlander(std::string name);
~Highlander();
static std::string speak(); // "There can be only one.  But now there are " + count
std::string status();          // if count == 1 "Immortal"  if count > 1 "Murderous"
};

#endif