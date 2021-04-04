#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
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
int n, a[5000005], s;
long long Ma, now, ans;
int main() {
	freopen("2_1.in", "r", stdin);
	//freopen("2.out", "w", stdout);
	n = RD();
	s = RD();
	for (register int i(1); i <= n; ++i) {
		a[i] = RD();
	}
	ans = a[1];
	// O(ns) 80'
	for (register int i(2); i <= n; ++i) {
		if(a[i] == 0) {
			ans = max(ans, (long long)0);
			continue;
		}
		now = 0;
		if(a[i] < 0) {
			for (register int j(i - 1); j >= max(1, i - s); --j) {
			  now += a[j];
			  Ma = min(Ma, now);
			}
			ans = max(ans, Ma  * a[i]);
			continue;
		}
		for (register int j(i - 1); j >= max(1, i - s); --j) {
		  now += a[j];
      Ma = max(Ma, now);
    }
    ans = max(ans, Ma * a[i]);
	}
	PR(ans,1);
	return 0;
}
