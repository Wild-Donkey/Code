#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int ans = 1, Ans = 1, n, a[1005], f[1005], ff[1005], t;
int main() {
	cin >> t;
	for (int k = 1; k <= t; k++) {
		cin >> n;
		ans = 1;
		Ans = 1;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			f[i] = 1;
			ff[i] = 1;
		}
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				if (a[i] < a[j]) {
					if (f[i] < f[j] + 1) {
						f[i] = f[j] + 1;
					}
				}
			}
		}
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				if (a[j] < a[i]) {
					if (ff[i] < ff[j] + 1) {
						ff[i] = ff[j] + 1;
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (f[ans] < f[i]) {
				ans = i;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (ff[Ans] < ff[i]) {
				Ans = i;
			}
		}
		if (f[ans] > ff[Ans]) {
			printf("%d\n", f[ans]);
		}
		else {
			printf("%d\n", ff[Ans]);
		}
	}
	return 0;
}