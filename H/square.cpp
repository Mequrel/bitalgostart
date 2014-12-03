/**

  Zadanie H: Pierwiastki.
  Autor: Jakub Czarnowicz.

  Rozwiązanie wzorcowe.

  Złożoność rozwiązania: O(lg (x/EPSI))

**/

#include <cstdio>

#define EPSI 0.000000001

double root(double x) {
  double L = 0, R = x;
  while(R - L > EPSI) {
    double S = (L+R) / 2.0;
    if(S*S > x) {
      R = S;
    } else {
      L = S;
    }
  }
  return L;
}

int main() {
  int z;
  scanf("%d", &z);
  while(z--) {
    int x;
    scanf("%d", &x);
    printf("%lf\n", root(x));
  }
}
