#include<cstdio>
#include<cstring>
#include<cstdlib>
//#include<minmax.h>
#include<iostream>
using namespace std;
int t, n, mn, yr, ans, a[15], b[15], f[1005];
int main() {
	cin >> n >> mn;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = mn; j >= 0; j--) {
			if (j >= a[i]) {
				f[j] = (f[a[i]] + 1) * f[j - a[i]];
				cout << i << " " << j << " " << f[j] << endl;
			}
		}
	}
	cout << f[mn] << endl;
	return 0;
}