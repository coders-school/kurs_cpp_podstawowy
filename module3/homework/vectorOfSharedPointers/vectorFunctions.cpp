#include "vectorFunctions.hpp"

std::vector<std::shared_ptr<int>> generate(int count){
    std::vector<std::shared_ptr<int>> tempVector{};
    
    if(count > 0){
        tempVector.reserve(count);
    }

    for(std::size_t i = 0; i < count; i++){
        tempVector.emplace_back(std::make_shared<int>(i));
    }

    return tempVector;
}


void print(const std::vector<std::shared_ptr<int>>& vecOfSharedPtr){
    for (const auto& element : vecOfSharedPtr){
        std::cout << *(element) << " ";
    }

    std::cout << "\n";
}

void add10(std::vector<std::shared_ptr<int>>& vecOfSharedPtr){
    for(auto& element : vecOfSharedPtr){
        if(element){
            *element += 10;
        }
    }
}

void sub10(int * const ptrToIntValue){
    if(ptrToIntValue){
        *ptrToIntValue -= 10;
    }
}

void sub10(std::vector<std::shared_ptr<int>>& vecOfSharedPtr){
    for(auto& element : vecOfSharedPtr){
        sub10(element.get());
    }

    std::cout << "\n";
}
