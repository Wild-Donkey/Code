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
int n, lst;
int L[3000005], R[3000005];
int ans[3000005];
int main() {
	freopen("ex_generator2.in", "r", stdin);
	n = RD();
	/*for (register int i(1); i <= n; ++i) {

	}*/
	for (register int i(1); i <= n; ++i) {
		L[i] = RD();
		R[i] = RD();
		if(L[i - 1] > R[i]) {
			ans[i] = 1;
			lst = L[i];
		} else {
			ans[i] = ans[i - 1] + 1;
			lst = max(lst,L[i]);
		}
		ans[0] = max(ans[0], ans[i]);
	}
	printf("%d\n", ans[0]);
	/*while (1) {
		printf("%d\n", RD());
	}*/
	return 0;
}
/*
6
6 10
1 5
4 8
2 5
6 8
3 5
*/
