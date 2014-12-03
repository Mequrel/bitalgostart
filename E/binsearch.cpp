/**

  Zadanie E: Binsearch.
  Autor: Jakub Czarnowicz.

  Rozwiązanie wzorcowe.

  Złożoność rozwiązania: O(lg n)

**/

#include <cstdio>
#include <vector>
using namespace std;

int binsearch(int q, const vector<int> &v) {
  int L = 0, P = v.size();
  while(P > L) {
    int S = (P+L)/2;
    if(v[S] < q) {
      L = S+1;
    }
    else P = S;
  }
  return L;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> v;
  for(int i = 0; i < n; ++i) {
    int tmp;
    scanf("%d", &tmp);
    v.push_back(tmp);
  }
  while(k--) {
    int q;
    scanf("%d", &q);
    int ind = binsearch(q, v);
    if(ind < 0 || ind >= n || v[ind] != q) printf("-1 ");
    else printf("%d ", ind+1);
  }
}