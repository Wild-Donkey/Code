#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n, L[1005], P[1005], at, sum;
bool flg[1005];
int dfs(int x, int dsum, int dans) {
	int dl = 0x3fffffff, dr = 0x3fffffff;
	//cout << dans << " " << x << endl;
	int di = x;
	while ((di > 0) && (flg[di])) {
		di--;
	}
	if (di > 0) {
		flg[di] = 1;
		dl = dfs(di, dsum - P[di], dans + (dsum * (L[x] - L[di])));
		flg[di] = 0;
	}
	di = x;
	while ((di <= n) && (flg[di])) {
		di++;
	}
	if (di <= n) {
		flg[di] = 1;
		//cout << di << endl;
		dr = dfs(di, dsum - P[di], dans + (dsum * (L[di] - L[x])));
		flg[di] = 0;
	}
	//cout << dsum << endl;
	if (!dsum) {
		//cout << di << endl;
		return dans;
	}
	if (dl < dr) {
		return dl;
	}
	return dr;
}
int main() {
	cin >> n >> at;
	for (int i = 1; i <= n; i++) {
		cin >> L[i] >> P[i];
		sum += P[i];
	}
	flg[at] = 1;
	sum -= P[at];
	cout << dfs(at, sum, 0) << endl;
	return 0;
}