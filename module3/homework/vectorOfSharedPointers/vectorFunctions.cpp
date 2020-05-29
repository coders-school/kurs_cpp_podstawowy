#include "vectorFunctions.hpp"
#include <vector>

std::vector<std::shared_ptr<int>> generate(int count){

    std::vector <std::shared_ptr<int>> SPvec;

    for(int i=0; i<count; i++){
        SPvec.push_back(std::make_shared<int>(i));
    }

    return SPvec;

}