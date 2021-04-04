#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int a[1005], n, ans = 0;
int main() {
	freopen("carry.in", "r", stdin);
	freopen("carry.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = n; j > i; j--) {
			if (a[j] < a[j - 1]) {
				swap(a[j], a[j - 1]);
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}