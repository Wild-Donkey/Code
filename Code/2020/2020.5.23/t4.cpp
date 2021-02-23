#include<cstdio>
#include<cstring>
#include<cstdlib>
//#include<minmax.h>
#include<iostream>
using namespace std;
int t, n, mn, yr, ans, a[15], b[15], f[100005];
int main() {
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> mn >> yr >> n;
		for (int j = 1; j <= n; j++) {
			cin >> a[j] >> b[j];
		}
		for (int faq = 1; faq <= yr; faq++) {
			memset(f, 0, sizeof(f));
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= mn; k++) {
					if (a[j] <= k) {
						f[k] = max(f[k], f[k - a[j]] + b[j]);
					}
				}
			}
			mn += f[mn];
		}
		cout << f[mn] + mn << endl;
	}
	return 0;
}