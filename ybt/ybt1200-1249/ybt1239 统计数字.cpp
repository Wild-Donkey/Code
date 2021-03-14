#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[200005], t[200005], ans = 1, n, k;
void Merge(int l, int r) {
	if (l == r)
		return;
	int m = (l + r) / 2, i = l, j = m + 1, k = l;
	Merge(l, m);
	Merge(m + 1, r);
	while (i <= m && j <= r) {
		if (a[i] < a[j]) {
			t[k++] = a[i++];
		}
		else {
			t[k++] = a[j++];
		}
	}
	while (i <= m) {
		t[k++] = a[i++];
	}
	while (j <= r) {
		t[k++] = a[j++];
	}
	for (int b = l; b <= r; b++) {
		a[b] = t[b];
	}
	return;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	Merge(1, n);
	printf("%d ", a[1]);
	for (int i = 2; i <= n; i++) {
		if (a[i] == a[i - 1]) {
			ans++;
		}
		else {
			printf("%d\n%d ", ans, a[i]);
			ans = 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}