#include<cstdio>
#include<iostream>
using namespace std;
int x[1005], t[1005], num[1005], tnum[1005], sum[1005];
double ans = 0;
void Merge(int l, int r) {
	if (l == r) {
		return;
	}
	int m = (l + r) / 2, i = l, j = m + 1, k = l;
	Merge(l, m);
	Merge(m + 1, r);
	while (i <= m && j <= r) {
		if (x[i] <= x[j]) {
			tnum[k] = num[i];
			t[k++] = x[i++];
		}
		else {
			tnum[k] = num[j];
			t[k++] = x[j++];
		}
	}
	while (i <= m) {
		tnum[k] = num[i];
		t[k++] = x[i++];
	}
	while (j <= r) {
		tnum[k] = num[j];
		t[k++] = x[j++];
	}
	for (int b = l; b <= r; b++) {
		x[b] = t[b];
		num[b] = tnum[b];
	}
	return;
}
int main() {
	cin >> x[0];
	for (int i = 1; i <= x[0]; i++) {
		cin >> x[i];
		num[i] = i;
	}
	Merge(1, x[0]);
	for (int i = 1; i <= x[0]; i++) {
		cout << num[i] << " ";
	}
	for (int i = 2; i <= x[0]; i++) {
		sum[i] = sum[i - 1] + x[i - 1];
		ans += sum[i];
	}
	ans /= x[0];
	printf("\n%.2lf\n", ans);
	return 0;
}