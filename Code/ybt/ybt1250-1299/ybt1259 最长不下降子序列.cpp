#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
//#include<minmax.h>
using namespace std;
int ans = 0, n, a[1005], f[1005], nxt[1005], prt[1005];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f[i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[i] >= a[j]) {
				if (f[i] < f[j] + 1) {
					nxt[i] = j;
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
	n = f[ans];
	printf("max=%d\n", f[ans]);
	for (int i = n; i >= 1; i--) {
		prt[i] = a[ans];
		ans = nxt[ans];
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", prt[i]);
	}
	printf("\n");
	return 0;
}