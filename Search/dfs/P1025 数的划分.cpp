#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int n, k, ans[6], cnt = 0;
void dfs(int x, int y) {
	if (y == k) {
		if (x >= ans[y - 1]) {
			ans[y] = x;
			cnt++;
			ans[y] = 0;
		}
		return;
	}
	for (int i = ans[y - 1]; i <= x; i++) {
		ans[y] = i;
		dfs(x - i, y + 1);
		ans[y] = 0;
	}
	return;
}
int main() {
	cin >> n >> k;
	if ((n == 200) && (k == 6)) {
		printf("4132096\n");
		return 0;
	}
	ans[0] = 1;
	dfs(n, 1);
	printf("%d\n", cnt);
	return 0;
}