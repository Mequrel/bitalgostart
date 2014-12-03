/**

  Zadanie C: Liczby pierwsze.
  Autor: Jakub Czarnowicz.

  Rozwiązanie wzorcowe.

  Złożoność rozwiązania: O(z sqrt(m)), gdzie m to największa możliwa liczba do sprawdzenia

**/

#include <cstdio>

bool prime(int n) {
	if(n == 1) return false;
	for(int i = 2; i*i <= n; ++i) { 
		if(n % i == 0) return false;
	}
	return true;
}

int main() {
	int z;
	scanf("%d", &z);
	while(z--) {
		int n;
		scanf("%d", &n);
		if(prime(n)) {
			printf("TAK\n");
		}
		else {
			printf("NIE\n");
		}
	}
	return 0;
}
