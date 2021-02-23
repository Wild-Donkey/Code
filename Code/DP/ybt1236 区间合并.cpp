#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int at, ans = 0, n, t;
bool flag = 0;
struct qj {
	int l, r;
}a[50005];
bool cmp(qj x, qj y) {
	if (x.l == y.l) {
		return (x.r > y.r);
	}
	return (x.l < y.l);
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].l >> a[i].r;
	}
	sort(a + 1, a + n + 1, cmp);
	at = a[1].r;
	int i = 1;
	while (i <= n) {
		if (a[i].l == a[i].r) {
			i++;
			continue;
		}
		if (a[i].l == a[i - 1].l) {
			i++;
			continue;
		}
		if (at < a[i].l) {
			flag = 1;
			break;
		}
		else {
			if (a[i].r > at) {
				at = a[i].r;
			}
			i++;
		}
	}
	if (flag) {
		printf("no\n");
		return 0;
	}
	printf("%d %d\n", a[1].l, at);
	return 0;
}