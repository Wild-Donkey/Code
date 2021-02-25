#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
//#include<minmax.h>
using namespace std;
int ans = 0, n = 1, a[205], f[205], nxt[205], x, y, cnt = 0, prt[205];
bool cntd[205][205];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f[i] = a[i];
	}
	cin >> x >> y;
	while ((x != 0) && (y != 0)) {
		cntd[x][y] = 1;
		cin >> x >> y;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (cntd[j][i]) {
				if (f[i] < f[j] + a[i]) {
					f[i] = f[j] + a[i];
					nxt[i] = j;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (f[ans] < f[i]) {
			ans = i;
		}
	}
	int i = ans;
	while (nxt[i]) {
		cnt++;
		prt[cnt] = i;
		i = nxt[i];
	}
	printf("%d", i);
	for (int j = cnt; j >= 1; j--) {
		printf("-%d", prt[j]);
	}
	printf("\n%d\n", f[ans]);
	return 0;
}