#pragma once
#include <string>

std::string calculate(const std::string& command, int first, int second) {

 std::string ret = "Invalid data";
 //jak zrobić warunek na int ?
  if(command=="add")
    {
     ret = std::to_string(first+second);
    }
  else if(command=="subtract")
    {
       ret = std::to_string(first-second);
    }
  else if(command=="multiply")
    {
      ret = std::to_string(first*second);
    }
  else if(command=="divide")
    {
      if(second == 0)
      { ret = "Division by 0"; }
      else
      { ret = std::to_string(first/second);}
    }
  return ret;
}
