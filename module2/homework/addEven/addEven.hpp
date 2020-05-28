#include <vector>

int addEven(const std::vector<int>& numbers) {
    // TODO: Your implementation goes here
    // Below return is only to make this function compile now
    int result = 0; 
    for(const int& element : numbers)
    {
        result += element % 2 == 0 ? element : 0;
    }
    return numbers.size() <= 0 ? 0 : result;
}
