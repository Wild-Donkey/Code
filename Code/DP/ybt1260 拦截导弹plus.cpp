#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
//#include<minmax.h>
using namespace std;
int ans = 0, n = 1, a[1005], f[1005], d[1005], u = 0;
int main() {
	while (cin >> a[n]) {
		f[n] = 1;
		n++;
	}
	n--;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[i] <= a[j]) {
				if (f[i] < f[j] + 1) {
					f[i] = f[j] + 1;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (f[ans] < f[i]) {
			ans = i;
		}
	}
	printf("%d\n", f[ans]);
	d[1] = a[1];
	for (int j = 1; j <= n; j++) {
		bool flag = 0;
		for (int k = 1; k <= u; k++) {
			if (d[k] >= a[j]) {
				d[k] = a[j];
				flag = 1;
				break;
			}
		}
		if (!(flag)) {
			d[++u] = a[j];
		}
	}
	cout << u << endl;
	return 0;
}