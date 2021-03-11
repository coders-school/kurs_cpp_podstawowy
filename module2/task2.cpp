#include <iostream>
#include <vector>

// Implement concatenateVector.
// It should take 2 vectors and return one which has alternately elements from the first and the other one.

std::vector<int> concatenateVector(std::vector <int>vec1, std::vector<int> vec2)
{
    std::vector<int> nowyVector (vec1.size() + vec2.size()) ;
    for (size_t i = 0, j = 0; i < std::min(vec1.size(),vec2.size()); i++, j +=2)
    {
       nowyVector[j] = vec1[i];
       nowyVector[j+1] = vec2[i];
    }
if (vec1.size() > vec2.size())
{
    int size = vec1.size() - vec2.size();
    while (size > 0)
    {
        nowyVector[]
    }
    
}
else
{

}

    return nowyVector;
    
}
int main() {
    std::vector<int> vec1 {1, 2, 3, 4, 5, 6,7,8};
    std::vector<int> vec2 {11, 12, 13, 14, 15};

    auto vec = concatenateVector(vec1, vec2);
    for (const auto& el : vec) {
        std::cout << el << " ";
    }
    return 0;
}
