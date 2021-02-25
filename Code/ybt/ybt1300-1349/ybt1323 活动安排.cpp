#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int n, l[1005], r[1005], ans = 1, at;
struct ms {
	int l, r;
}a[10005];
bool cmp(ms x, ms y) {
	if (x.r == y.r) {
		return (x.l > y.l);
	}
	return (x.r < y.r);
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].l >> a[i].r;
	}
	sort(a + 1, a + n + 1, cmp);
	at = a[1].r;
	int i = 2;
	while (i <= n) {
		if (a[i].l >= at) {
			ans++;
			at = a[i].r;
		}
		i++;
	}
	cout << ans << endl;
	return 0;
}