#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <bitset>
#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
#include <string>
#include <set>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
	unsigned intmp(0);
	char rdch(getchar());
	while (rdch < '0' || rdch > '9') rdch = getchar();
	while (rdch >= '0' && rdch <= '9')
		intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
	return intmp;
}
inline int RDsg() {
	int rdtp(0), rdsg(1);
	char rdch(getchar());
	while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
	if (rdch == '-') rdsg = -1, rdch = getchar();
	while (rdch >= '0' && rdch <= '9')
		rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0', rdch = getchar();
	return rdtp * rdsg;
}
unordered_map<unsigned, char> Sqr;
unsigned a[100005], Sum, Pre[10005][10005], m, n, Size(1);
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
struct Qry {

};
inline void Clr() {
	n = RD(), m = RD();
}
signed main() {
//  freopen("D.in", "r", stdin);
//	freopen("D.out", "w", stdout);
	for (unsigned i(0); i <= 32768; ++i) Sqr[i * i] = 1;
	t = RD();
	for (unsigned T(1); T <= t; ++T) {
		Clr();
		for (unsigned i(1); i <= n; ++i) a[i] = RD();
		for (unsigned i(1); i <= n; ++i) {
			Pre[i][i + 1] = 0, Sum = 0xffffffff;
			for (unsigned j(i); j; --j) {
				Sum &= a[j], Pre[i][j] = Pre[i][j + 1];
				if(Sqr[Sum]) ++Pre[i][j];
			}
		}
		for (unsigned i(1); i <= m; ++i) {
			Cnt = 0, A = RD(), B = RD();
			for (unsigned j(A); j <= B; ++j) {
				Cnt += Pre[j][A];
			}
			printf("%u\n", Cnt);
		}
	}
	//  system("pause");
	return Wild_Donkey;
}
/*
1073741824
*/
