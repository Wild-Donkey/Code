#include <cstdio>
#include <iostream>
using namespace std;
inline int RD() {
	int intmp(0), insign(1);
	char rdch(getchar());
	while ((rdch != '-') && (rdch < '0' || rdch > '9')) {
		rdch = getchar();
	}
	if (rdch == '-') {
		insign = -1;
		rdch = getchar();
	}
	while (rdch >= '0' && rdch <= '9') {
		intmp *= 10;
		intmp += rdch - '0';
		rdch = getchar();
	}
	return intmp * insign;
}
int n, k;
int a[205];
int Ma[205][205];
void DFS(int Dep, int now[205]) {
	if(Dep > k) {
		return;
	}
	for (register int i(1); i <= n; ++i) {
		for (register int j(i + 1); j <= i; j++) {
		}
	}
	return;
}
int main() {
	n = RD();
	k = RD();
	for (register int i(1); i <= n; ++i) {
		a[i] = RD();
		Ma[i][i] = a[i];
	}
	for (register int i(1); i <= n; ++i) {
		for (register int j(i + 1); j <= n; ++j) {
			Ma[i][j] = max(Ma[i][j - 1], a[j]);
		}
	}
	if(k == 1) {
		int ans = ((n * (n - 1)) >> 1) +1;
		for (register int l(1); l < n; ++l) {
			for (register int i = 1; i + l <= n; ++i) {
				if(a[i]==a[l+i] && Ma[i][i+l]==a[i]) {
					//printf("%d,%d %d\n", a[i], a[l +i], Ma[i][l+i]);
					ans -= n - 1;
				}
			}
		}
		printf("%d\n",ans);
		return 0;
	}
	printf("%d\n", ((n * (n - 1)) >> 1) +1);
	return 0;
}
/*
3 2
3 1 2


3 1
2 1 2

2

3 1
1 2 1

3
*/
