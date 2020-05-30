#include "validation.hpp"

std::string getErrorMessage(ErrorCode error)
{
    switch(error)
    {
        case 1:
            return "Your password is correct.\n";
        case 2: 
            return "Your password needs at least nine characters.\n";
        case 3:
            return "Yout password needs at least one number.\n";
        case 4:
            return "Your password needs at least one special character.\n";
        case 5:
            return "Your password needs at least one upper case letter.\n";
        case 6:
            return "Passwords do not match.\n"; 
        default:
            return "Your password is incorrect.\n";
    }
}
