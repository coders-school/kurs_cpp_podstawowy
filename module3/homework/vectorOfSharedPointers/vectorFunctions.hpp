#pragma once
#include <vector>
#include <memory>

std::vector<std::shared_ptr<int>> generate(int count);

void print(const std::vector<std::shared_ptr<int>>& vectorToPrint);

//TODO 
//void add10() która przyjmie wektor i doda do ka¿dej liczby 10
//void sub10() która przyjmie sta³y wskaŸnik na int i odejmie od tego elementu 10
//void sub10(); Która przyjmie wektor wspó³dzielonych wskaŸników i wywo³a dla ka¿dego elementu powy¿sze przeci¹¿enie funkcji sub10()