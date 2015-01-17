/**

  Zadanie O: Kombinacje.
  Autor: Bartłomiej Szczepanik

  Rozwiązanie wzorcowe.
  Złożoność rozwiązania: O(test_cases * n * k)

**/

#include <cstdio>
#include <vector>

using namespace std;

typedef unsigned long long int uint64;

uint64 choose(int n, int k) {
  uint64 result = 1LL;

  for(int i=0; i<k; ++i) {
    result *= (uint64) (n - i);
    result /= (uint64) (i + 1);
  }

  return result;
}

vector<int> unrank_subset(int n, int k, uint64 rank) {
  vector<int> subset;

  for(int possible_element=1; possible_element <= n && k > 0; ++possible_element) {
    uint64 all_starting_with_current_element = choose(n - possible_element, k - 1);

    if(all_starting_with_current_element < rank) {
      rank -= all_starting_with_current_element;
    }
    else {
      subset.push_back(possible_element);
      k--;
    }
  }

  return subset;
}

void single_test_case() {
  int n, k;
  uint64 i;

  scanf("%d %d %lld", &n, &k, &i);
  vector<int> subset = unrank_subset(n, k, i);

  for(int i=0; i<subset.size(); ++i) {
    printf("%d ", subset[i]);
  }
  printf("\n");
}

int main() {
  int test_cases;
  scanf("%d", &test_cases);

  for(int i=0; i<test_cases; ++i) {
    single_test_case();
  }


  return 0;
}