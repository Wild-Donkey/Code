#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[7], t, two[25], m, ans[1005][1005];
bool flag = 0;
void f(int n, int x, int y, int num) {
	if (n <= 0) {
		ans[x][y] = num;
		return;
	}
	f(n - 1, x, y, num);
	f(n - 1, x + two[n - 1], y, num + two[n - 1]);
	f(n - 1, x, y + two[n - 1], num + two[n - 1]);
	f(n - 1, x + two[n - 1], y + two[n - 1], num);
	return;
}
int main() {
	two[0] = 1;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		two[i] = 2 * two[i - 1];
	}
	f(m, 1, 1, 1);
	for (int i = 1; i <= two[m]; i++) {
		for (int j = 1; j <= two[m]; j++) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}