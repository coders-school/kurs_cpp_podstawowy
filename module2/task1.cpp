#include <iostream>
#include <vector>
#include <string>
#include <ostream>
using namespace std;
// Implement printVec to print the content of a given vector on screen.
// Each string in a new line.
void printVector(std::vector<std::string> a)
{
   for(auto i = a.begin() ; i != a.end(); ++i)
   {
       auto element = *i;
       cout<<element<<endl;

   }
       
    
}
int main() {
    std::vector<std::string> vec {
        "Hello Coders School!",
        "Welcome to the best C++ course ever",
        "Man, this is crazy :)"
    };
    printVector(vec);
    return 0;
}
