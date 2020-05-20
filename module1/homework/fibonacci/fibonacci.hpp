#pragma once

int fibonacci_iterative(int sequence) {
  int tab[sequence];
    tab[0] = 0;
    tab[1] = 1;
      for (int i=2;i<=sequence;i++){
        tab[i] = tab[i-1] + tab[i-2];
      }
  return tab[sequence];
}

int fibonacci_recursive(int sequence) {
  if (sequence == 1 or sequence == 0)
    return sequence;
  else
    return (fibonacci_recursive(sequence - 1) + fibonacci_recursive(sequence - 2));
}
