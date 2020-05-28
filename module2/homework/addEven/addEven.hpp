#include <vector>

int addEven(const std::vector<int> & numbers) {

    int result = 0;

    for(const int& element : numbers) {
        result += element % 2 == 0 ? element : 0;
    }
    return numbers.size() <= 0 ? 0 : result;
}
