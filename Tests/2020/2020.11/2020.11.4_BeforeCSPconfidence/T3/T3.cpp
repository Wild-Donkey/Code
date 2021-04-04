#include <algorithm>
#include <cmath> 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;
inline int RD() {
	int Itmp(0), Isig(1);
	char Ichr(getchar());
	while ((Ichr != '-') && ((Ichr > '9') || (Ichr < '0'))) {
		Ichr = getchar();
	}
	if (Ichr == '-') {
		Isig = -1;
		Ichr = getchar();
	}
	while ((Ichr >= '0') && (Ichr <= '9')) {
		Itmp = Itmp * 10 + Ichr - '0';
		Ichr = getchar();
	}
	return Itmp * Isig;
}
inline void PR(long long Prtmp, bool SoE) {
	long long Prstk(0), Prlen(0);
	if (Prtmp < 0) {
		putchar('-');
		Prtmp = -Prtmp;
	}
	do {
		Prstk = Prstk * 10 + Prtmp % 10;
		Prtmp /= 10;
		++Prlen;
	} while (Prtmp);
	//printf("%d", Prtmp);
	do {
		putchar(Prstk % 10 + '0');
		Prstk /= 10;
		--Prlen;
	} while (Prlen);
	if (SoE) {
		putchar('\n');
	} else {
		putchar(' ');
	}
	return;
}
int n;
long long ans, k, a[100005], f[100005];
void DFS(int x, long long now) {
	ans = max(ans, now);
	if(x == 1) {
		return;
	}
	DFS(x - 1, now);//no x - 1
	if(a[x - 1] <= k - now) {//yes x - 1
  	DFS(x - 1, now + a[x - 1]);
	}
	return; 
}
int main() {
	//freopen("3.in", "r", stdin);
	//freopen("3.out", "w", stdout);
	k = RD();
	n = RD();
	for (register int i(1); i <= n; ++i) {
		a[i] = RD();
	}
	ans = a[n];
	DFS(n + 1, 0);
	printf("%lld\n", ans);
	return 0;
}
