/**

  Zadanie P: Dzielniki.
  Autor: Bartłomiej Szczepanik

  Rozwiązanie wzorcowe.

  Złożoność rozwiązania: O(2^n * n * lg(m)), gdzie m to maksymalna wartość liczb

**/

#include <cstdio>
#include <vector>

using namespace std;

typedef long long int64;
const int WAY_TO_BIG = 2000000000;

struct Range {
  int start;
  int end;
};

int gcd(int a, int b) {
  if(a < b) {
    swap(a, b);
  }

  while(b > 0) {
    int old_b = b;
    b = a % b;
    a = old_b;
  }

  return a;
}

int lcm(int a, int b) {
  int64 result = ((int64) a) * ((int64) b) / ((int64) gcd(a, b));

  if(result > (int64) WAY_TO_BIG) {
    result = WAY_TO_BIG;
  }

  return (int) result;
}

int lcm(const vector<int>& numbers) {
  // assuming at least one element in the vector
  int result = numbers[0];

  for(int i=1; i<numbers.size(); ++i) {
    result = lcm(result, numbers[i]);
  }

  return result;
}

int single_number_divisors(const Range& range, int number) {
  int divisors_from_1_to_start_exclusive = (range.start - 1) / number;
  int divisors_from_1_to_end_inclusive = range.end / number;

  return divisors_from_1_to_end_inclusive - divisors_from_1_to_start_exclusive;
}

vector<int> unrank(const vector<int>& numbers, int mask) {
  vector<int> subset;

  int element_bit = 1;
  for(int i=0; i<numbers.size(); ++i) {
    if(element_bit & mask) {
      subset.push_back(numbers[i]);
    }
    element_bit <<= 1;
  }

  return subset;
}

int divisors(const Range& range, const vector<int>& numbers) {
  int result = 0;

  int all_subsets_number = 1 << numbers.size();

  for(int i=1; i<all_subsets_number; ++i) {  // skipping zero-element subset
    vector<int> subset = unrank(numbers, i);
    int common_divisors = single_number_divisors(range, lcm(subset));

    if(subset.size() % 2 == 1) {
      result += common_divisors;
    }
    else {
      result -= common_divisors;
    }
  }

  return result;
}

int main() {
  int n;
  Range range; // both inclusive
  scanf("%d %d %d", &n, &range.start, &range.end);

  vector<int> numbers(n);

  for(int i=0; i<n; ++i) {
    scanf("%d", &numbers[i]);
  }

  int result = divisors(range, numbers);

  printf("%d", result);

  return 0;
}