#include <iostream>
#include <vector>

auto concatenateVector(std::vector<int>& first_vector, std::vector<int>& second_vector){
    std::vector<int> result_vector;
    for (size_t i = 0; i < first_vector.size() || i < second_vector.size(); i++){
        if (i < first_vector.size()){
            result_vector.push_back((first_vector[i]));
        }
        if (i < second_vector.size()){
            result_vector.push_back((second_vector[i]));
        }
    }
    return result_vector;
}

int main() {
    std::vector<int> vec1 {1, 2, 3, 4};
    std::vector<int> vec2 {11};

    auto vec = concatenateVector(vec1, vec2);
    for (const auto& el : vec) {
        std::cout << el << " ";
    }
    return 0;
}
