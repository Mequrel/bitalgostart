/**

  Zadanie B: NWD i NWW.
  Autor: Jakub Czarnowicz.

  Rozwiązanie wzorcowe.

  Złożoność rozwiązania: O(lg max(a,b))

**/

#include <cstdio>
#include <algorithm>
using namespace std;

long long NWD(long long a, long long b) {
	if(a > b) swap(a, b);
	if(a == 0LL) return b;
	return NWD(b % a, a);
}

int main() {
	int z;
	scanf("%d", &z);
	while(z--) {
		long long a, b;
		scanf("%lld%lld", &a, &b);
		long long nwd = NWD(a, b);
		long long nww = (a * b) / nwd;
		printf("%lld %lld\n", nwd, nww);
	}
	return 0;
}
