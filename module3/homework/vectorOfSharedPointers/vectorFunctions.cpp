#include "vectorFunctions.hpp"


std::vector<std::shared_ptr<int>> generate(int count) {
    std::vector<std::shared_ptr<int>> pointers;
    for(size_t i = 0; i < count; i++)
        pointers.push_back(std::make_shared<int>(i));
    
    return pointers;
}

void print(std::vector<std::shared_ptr<int>> numbers) {


}
void add10(std::vector<std::shared_ptr<int>> numbers) {
    for(auto& num: numbers){
        if(num)
            *num+=10;
    }
}
void sub10(int* const number) {

}
void sub10(std::vector<std::shared_ptr<int>> numbers) {

}