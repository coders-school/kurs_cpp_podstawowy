#pragma once

int fibonacci_iterative(int sequence) {
if(sequence==0)
    return 0;
int currentResults[3]{0,1,1};

int swap;
for (size_t i = 1; i < sequence; i++)
{
    currentResults[2]=currentResults[0]+currentResults[1];
    currentResults[0]=currentResults[1];
    currentResults[1]=currentResults[2];
}

return currentResults[2];
    }

int fibonacci_recursive(int sequence) {
    if(sequence==1)
        return 1;
    if(sequence==0)
        return 0;
    else
    {
       return fibonacci_recursive(sequence-1)+fibonacci_recursive(sequence-2);
    }
}
