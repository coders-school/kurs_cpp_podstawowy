#include <iostream>
#include <string>
#include "vectorFunctions.hpp"

int main() {
    auto vec = generate(10);
    print(vec);
    add10(vec);
    print(vec);
    sub10(vec);
    print(vec);
    sub10(vec[vec.size() -2].get());
    print(vec);

    return 0;
}
