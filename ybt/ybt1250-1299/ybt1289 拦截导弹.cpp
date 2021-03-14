#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
//#include<minmax.h>
using namespace std;
int ans = 0, n, a[105], f[105];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f[i] = 1;
	}
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
	return 0;
}