#include<cstdio>
#include<cstring>
//#include<minmax.h>
#include<iostream>
#include<algorithm>
using namespace std;
int n, a[50], v, f[20005][50];
bool flg[1005];
int main() {
	cin >> v >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = v; i >= 0; i--) {
		for (int j = 1; j <= n; j++) {
			if (a[j] <= v - i) {
				f[i][j] = max(f[i][j - 1], f[i + a[j]][j - 1] + a[j]);
			}
			else {
				f[i][j] = f[i][j - 1];
			}
		}
	}
	cout << v - f[0][n] << endl;
	return 0;
}