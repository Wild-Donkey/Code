#include<bits/stdc++.h>
#define Mod 1000000000
using namespace std;
typedef long long ll;
int rd() {
	int res = 0, fl = 1; char c = getchar();
	while (!isdigit(c)) { if (c == '-') fl = -1; c = getchar(); }
	while (isdigit(c)) { res = (res << 3) + (res << 1) + c - '0'; c = getchar(); }
	return res * fl;
}
const int maxn = 500;
int n, a, b, A[maxn], top, B[maxn], P[maxn][maxn], Tot, Sta[maxn], Gol;
long long Table[25] = { 0, 0, 1, 5, 21, 441, 1465, 126093, 1946621, 131427473, 2007064545, }, ans;

void Dfs(int pos, int NowSta, int Set) {
	//	printf("Pos %u Now %u %u\n", pos, NowSta, Set);
	if (pos > top) {
		if (NowSta == Gol) {
			ans++;
			//			printf("%d is ok %u\n", NowSta, Set);
		}
		//		else printf("%d is wrong %u\n", NowSta, Set);
		return;
	}
	Dfs(pos + 1, NowSta, Set);
	Dfs(pos + 1, NowSta | Sta[pos], Set | (1 << (pos - 1)));
}
int main() {
	n = rd(); Gol = (1 << (n - 1)) - 1;

	printf("Top=%d\n", top);

	//	for(int x = 2; x <= n; ++x) printf("P[%d][0]=%d\n", x, P[x][0]);
	Dfs(1, 0, 0);
	printf("ans=%lld\n", ans);
	return 0;
}
