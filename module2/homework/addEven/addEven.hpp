#include <vector>

int addEven(const std::vector<int>& numbers) {
    // TODO: Your implementation goes here
    // Below return is only to make this function compile now
    //return std::accumulate(numbers.begin(), numbers.end(), 0, [](int i){i % 2 == 0;});
     int result = 0; 
    for(const int& elem : numbers)
    {
        int Even_number  = elem % 2 == 0 ? elem : 0;
        result += Even_number;
    }
    return result;
}
