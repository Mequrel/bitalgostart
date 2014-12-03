/**

  Zadanie D: Bubble sort.
  Autor: Jakub Czarnowicz.

  Rozwiązanie wzorcowe.

  Złożoność rozwiązania: O(n^2)

**/


#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

void bubbleSort(int n, int *T) {
	for(int i = n; i > 0; --i) {
		for(int j = 0; j < i-1; ++j) {
			if(T[j] > T[j+1]) swap(T[j], T[j+1]);
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int *T = new int[n];
	for(int i = 0; i < n; ++i) {
		scanf("%d", &T[i]);
	}
	bubbleSort(n, T);
	for(int i = 0; i < n; ++i) printf("%d ", T[i]);
	printf("\n");
	delete[] T;
	return 0;
}
