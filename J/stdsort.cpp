/**

  Zadanie J: Szybkie sortowanie.
  Autor: Bartłomiej Szczepanik

  Rozwiązanie pokazowe z użyciem std::sort.

  Złożoność rozwiązania: O(n lg n)

**/

#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  vector<int> numbers(n);

  for(int i=0; i<n; ++i) {
    scanf("%d", &numbers[i]);
  }

  sort(numbers.begin(), numbers.end());

  for(int i=0; i<n; ++i) {
    printf("%d ", numbers[i]);
  }

  return 0;
}