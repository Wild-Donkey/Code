#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n, V[55], w[55], f[55][1005];
int main()
{
	freopen("hxm.in", "r", stdin);
	freopen("hxm.out", "w", stdout);
	cin >> V[0] >> n;
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= n; i++) {
		cin >> V[i] >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = V[0]; j >= 0; j--) {
			if (j >= V[i]) {
				if (f[i - 1][j] > f[i - 1][j - V[i]] + w[i]) {//²»·Å
					f[i][j] = f[i - 1][j];
				}
				else {//·Å
					f[i][j] = f[i - 1][j - V[i]] + w[i];
				}
			}
			else {
				f[i][j] = f[i - 1][j];
			}
		}
	}
	cout << f[n][V[0]] << endl;
	return 0;
}