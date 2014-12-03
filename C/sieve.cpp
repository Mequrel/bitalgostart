/**

  Zadanie C: Liczby pierwsze.
  Autor: Bartłomiej Szczepanik.

  Rozwiązanie wzorcowe.

  Złożoność rozwiązania: O(m lg lg m + z), gdzie m to największa możliwa liczba do sprawdzenia

**/

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_NUMBER = 1e6;

bool is_prime[MAX_NUMBER+1];

void cross_out_all_multiples_of(int number) {
  for(int i = number * 2; i <= MAX_NUMBER; i += number) {
    is_prime[i] = false;
  }
}

int next_not_crossed_out(int start) {
  for(int i = start + 1; i <= MAX_NUMBER; ++i) {
    if (is_prime[i]) {
      return i;
    }
  }

  return MAX_NUMBER + 1;
}

void sieve() {
  fill(is_prime, is_prime+MAX_NUMBER+1, true);

  is_prime[0] = false;
  is_prime[1] = false;
  
  for(int current_prime = 2; current_prime <= MAX_NUMBER; current_prime = next_not_crossed_out(current_prime)) {
    cross_out_all_multiples_of(current_prime);
  }
}

int main() {
  sieve();

  int test_cases;
  scanf("%d", &test_cases);

  while(test_cases --> 0) {
    int n;
    scanf("%d", &n);
    if(is_prime[n]) {
      printf("TAK\n");
    }
    else {
      printf("NIE\n");
    }
  }
  return 0;
}
