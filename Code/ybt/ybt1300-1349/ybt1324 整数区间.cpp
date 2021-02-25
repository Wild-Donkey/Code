#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int n, ans = 0, at;
struct ms {
	int l, r;
}a[10005];
bool cmp(ms x, ms y) {
	if (x.l == y.l) {
		return (x.r < y.r);
	}
	return (x.l < y.l);
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].l >> a[i].r;
	}
	sort(a + 0, a + n, cmp);
	int i = 1;
	while (i <= n) {
		at = a[i].r;
		ans++;
		i++;
		while ((a[i].l <= at) && (i <= n)) {
			i++;
			continue;
		}
	}
	cout << ans << endl;
	return 0;
}