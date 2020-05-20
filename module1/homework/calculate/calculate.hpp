#pragma once
#include <string>

std::string calculate(const std::string& command, int first, int second) {
    
      if (command == "add"){
         std::string add = std::to_string(first + second);
         return (add);
     }
             
             
     if (command == "subtract"){
         std::string substract = std::to_string(first - second);
         return (substract);
     }
             
             
     if (command == "multiply"){
         std::string multiply = std::to_string(first * second);
         return (multiply);
     }
             
     if (command == "divide"){
         if (second == 0){
                     return ("Division by 0");
                   }
         else {
           std::string divide = std::to_string(first / second);
           return (divide);
         }
     }       
     else {
         return ("Invalid data");
     }
}

