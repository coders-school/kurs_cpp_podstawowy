#include <iostream>

// Write your function here

int max(int x, int y, int z)
{
    if((x > y)&&(x > z))
    {
        return x;
    }
    else if((y > z)&&(y >x))
    {
        return y;
    }
    else if((z > y)&&(z > x))
    {
        return z;
    }
}

int main() {
    std::cout << "max (1, 2, 3): " << max(1, 2, 3) << "\n";
    std::cout << "max (2, 3, 1): " << max(2, 3, 1) << "\n";
    std::cout << "max (3, 2, 1): " << max(3, 2, 1) << "\n";

    return 0;
}
