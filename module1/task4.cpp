#include <iostream>

constexpr size_t tab_size = 100;

int main()
{
    int tab[tab_size];

    for (size_t i = 1; i < tab_size+1; ++i)
    {
    
           tab[i] = 2 * i - 1;
    
    }

    for (size_t i = 1; i < tab_size +1; ++i)
    {
        std::cout << tab[i] << "\n";
    }

    return 0;
}
