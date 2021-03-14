#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int ans = 1, n, a[1005], f[1005];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f[i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i]) {
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