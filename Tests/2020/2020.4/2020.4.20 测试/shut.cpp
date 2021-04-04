#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n, L[1005], P[1005], at, sum[1005], f[1005][1005];
bool flg[1005];
int main() {
	cin >> n >> at;
	memset(f, 0x3f, sizeof(f));
	for (int i = 1; i <= n; i++) {
		cin >> L[i] >> P[i];
		sum[i] = sum[i - 1] + P[i];
	}
	f[at][at] = 0;
	for (int l = 2; l <= n; l++) {
		for (int i = 1; i + l - 1 <= n; i++) {
			int j = i + l - 1;
			f[i][j] = min(f[i + 1][j] + (L[i + 1] - L[i]) * (sum[i] + sum[n] - sum[j]), f[j][i + 1] + (L[j] - L[i]) * (sum[i] + sum[n] - sum[j]));
			f[j][i] = min(f[i][j - 1] + (L[j] - L[i]) * (sum[i - 1] + sum[n] - sum[j - 1]), f[j - 1][i] + (L[j] - L[j - 1]) * (sum[i - 1] + sum[n] - sum[j - 1]));
		}
	}
	cout << min(f[1][n], f[n][1]) << endl;
	return 0;
}