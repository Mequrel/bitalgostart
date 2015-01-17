/**

  Zadanie M: Dwie gry.
  Autor: Bartłomiej Szczepanik

  Rozwiązanie wzorcowe z użyciem binary search.

  Złożoność rozwiązania: O(n lg n)

**/

#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

bool check_for_two_items_of_sum(vector<int>& items, int sum) {
  std::sort(items.begin(), items.end());

  for(vector<int>::iterator first_value = items.begin(); first_value != items.end(); first_value++) {
    int wanted_price = sum - *first_value;

    if (binary_search(first_value + 1, items.end(), wanted_price)) {
      return true;
    }
  }

  return false;
}

int main() {
  int games, money;
  scanf("%d %d", &games, &money);

  vector<int> prices(games);

  for(int i=0; i<games; ++i) {
    scanf("%d", &prices[i]);
  }

  bool result = check_for_two_items_of_sum(prices, money);

  if(result) {
    printf("TAK");
  }
  else {
    printf("NIE");
  }

  return 0;
}