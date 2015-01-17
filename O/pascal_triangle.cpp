/**

  Zadanie O: Kombinacje.
  Autor: Bartłomiej Szczepanik

  Rozwiązanie wzorcowe z użyciem trójkąta Pascala.
  Złożoność rozwiązania: O(test_cases * n + n^2)

**/

#include <cstdio>
#include <vector>

using namespace std;

typedef unsigned long long int uint64;

const int MAX_N = 50;

uint64 pascal_triangle[MAX_N+1][MAX_N+1] = {0LL};

void precompute_pascal_triangle() {
  pascal_triangle[0][0] = 1LL;

  for(int n = 0; n <= MAX_N; ++n) {
    pascal_triangle[n][0] = 1LL;
    for(int k = 1; k <= n; ++k) {
      pascal_triangle[n][k] = pascal_triangle[n-1][k-1] + pascal_triangle[n-1][k];
    }
  }
}

uint64 choose(int n, int k) {
  return pascal_triangle[n][k];
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
  precompute_pascal_triangle();

  int test_cases;
  scanf("%d", &test_cases);

  for(int i=0; i<test_cases; ++i) {
    single_test_case();
  }

  return 0;
}