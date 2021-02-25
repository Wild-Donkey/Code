#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int ans = 0, n, a[1005][1005], f[1005][1005];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> a[i][j];
		}
	}
	f[1][1] = a[1][1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			f[i][j] = max(f[i - 1][j] + a[i][j], f[i - 1][j - 1] + a[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		ans = max(ans, f[n][i]);
	}
	cout << ans << endl;
	return 0;
}