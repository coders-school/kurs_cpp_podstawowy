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
         std::string mnozenie = std::to_string(first * second);
         return (mnozenie);
     }
             
     if (command == "divide" && second != 0){
         
           std::string divide = std::to_string(first / second);
           return (divide);
         }
     if (command == "divide" && second == 0){
                     return ("Division by 0");
                   }
     
             
     else {
         return ("Invalid data");
     }
    
    
}

