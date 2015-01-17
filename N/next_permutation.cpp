/**

  Zadanie N: Kolejna permutacja.
  Autor: Bartłomiej Szczepanik

  Rozwiązanie wzorcowe.

  Złożoność rozwiązania: O(n)

**/

#include <cstdio>
#include <algorithm>

using namespace std;

void next_permutation(int* sequence, int size) {
  int last_ascending = size - 1;
  while(last_ascending > 0 && sequence[last_ascending-1] >= sequence[last_ascending]) {
    last_ascending--;
  }

  if(last_ascending > 0) {
    int first_bigger = last_ascending;
    while(first_bigger < size && sequence[first_bigger] > sequence[last_ascending-1]) {
      first_bigger++;
    }

    first_bigger--;

    swap(sequence[last_ascending-1], sequence[first_bigger]);
  }
  reverse(sequence + last_ascending, sequence + size);
}

int main() {
  int n;
  scanf("%d", &n);

  int* sequence = new int[n];

  for(int i=0; i<n; ++i) {
    scanf("%d", &sequence[i]);
  }

  next_permutation(sequence, n);

  for(int i=0; i<n; ++i) {
    printf("%d ", sequence[i]);
  }

  return 0;
}