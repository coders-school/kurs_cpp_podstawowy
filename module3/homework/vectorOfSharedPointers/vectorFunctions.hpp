#pragma once
#include <vector>
#include <memory>

std::vector<std::shared_ptr<int>> generate(int count);

void print(const std::vector<std::shared_ptr<int>>& vectorToPrint);

//TODO 
//void add10() kt�ra przyjmie wektor i doda do ka�dej liczby 10
//void sub10() kt�ra przyjmie sta�y wska�nik na int i odejmie od tego elementu 10
//void sub10(); Kt�ra przyjmie wektor wsp�dzielonych wska�nik�w i wywo�a dla ka�dego elementu powy�sze przeci��enie funkcji sub10()