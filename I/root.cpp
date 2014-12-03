/**

  Zadanie I: Rozwiązywanie równań.
  Autor: Bartłomiej Szczepanik

  Rozwiązanie wzorcowe.

  Złożoność rozwiązania: O(lg((end-start)/PRECISION))

**/

#include <cstdio>
#include <cmath>

using namespace std;

const double PRECISION = 1e-9;

struct Function {
  double A,B,C,D,E,F,G,H,I,J;  

  double value(double x) {
    double result = 0.0;

    result += A * sin(B * x + C);
    result += D * exp(E * x + F);
    result += G * fabs(H * x + I);
    result += J;

    return result;
  }
};

double root(Function func, double start, double end) {
  if(fabs(start-end) < PRECISION) {
    return start;
  }

  double mid = (start + end) / 2.0;

  if(func.value(start) * func.value(mid) <= 0) {
    return root(func, start, mid);
  }
  else {
    return root(func, mid, end);
  }
}

int main() {
  double p, q;
  scanf("%lf %lf", &p, &q);

  Function func;
  scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", 
        &func.A, &func.B, &func.C, &func.D, &func.E, &func.F, &func.G, &func.H, &func.I, &func.J);

  double x = root(func, p, q);

  printf("%0.7lf\n", x);

  return 0;
}