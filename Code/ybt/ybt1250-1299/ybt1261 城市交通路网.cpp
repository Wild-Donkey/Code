#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
//#include<minmax.h>
using namespace std;
int ans = 0, n = 1, a[205][205], f[205], nxt[205], cnt = 0, prt[205];
void DFS(int x) {
	if (x == n) {
		return;
	}
	int t = 0;
	for (int di = 1; di <= n; di++) {
		if (a[x][di]) {
			if (f[di] > f[x] + a[x][di]) {
				f[di] = f[x] + a[x][di];
				nxt[di] = x;
				DFS(di);
			}
		}
	}
	return;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
		f[i] = 0x3fffffff;
	}
	f[1] = 0;
	DFS(1);
	printf("minlong=%d\n", f[n]);
	int j = n;
	while (j) {
		cnt++;
		prt[cnt] = j;
		j = nxt[j];
	}
	for (int i = cnt; i >= 1; i--) {
		printf("%d ", prt[i]);
	}
	return 0;
}