/**

  Zadanie N: Kolejna permutacja.
  Autor: Bartłomiej Szczepanik

  Rozwiązanie pokazowe z użyciem biblioteki standardowej.

**/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  vector<int> sequence(n);

  for(int i=0; i<n; ++i) {
    scanf("%d", &sequence[i]);
  }

  next_permutation(sequence.begin(), sequence.end());

  for(int i=0; i<n; ++i) {
    printf("%d ", sequence[i]);
  }

  return 0;
}