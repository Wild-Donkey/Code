#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long a[10005], t[10005], ans = 0, n, k;
void Merge(int l, int r) {
	if (l == r)
		return;
	int m = (l + r) / 2, i = l, j = m + 1, k = l;
	Merge(l, m);//排好左边
	Merge(m + 1, r);//排好右边
	while (i <= m && j <= r) {
		if (a[i] <= a[j]) {//左边的i比右边的j小(或等于),无需交换
			t[k++] = a[i++];
		}
		else {//右边的j比左边的i小(当然也比左区间内i右边的数小),需要交换
			t[k++] = a[j++];
			ans += m - i + 1;
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
	printf("%d\n", ans);
	return 0;
}