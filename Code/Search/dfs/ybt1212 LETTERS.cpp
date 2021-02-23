#include<iostream>
#include<cstring>
using namespace std;
int xr[4] = { 0,1,0,-1 };
int yr[4] = { -1,0,1,0 };//操作记录
int T, n, m, ans = 0, a[100][100];
char ch;
bool lt[30];
int dfs(int x, int y) {//深搜
	//cout << x << " " << y << "	";
	if ((x < 0) || (y < 0)) {
		return 0;
	}
	if ((x >= n) || (y >= m)) {
		return 0;
	}
	if (lt[a[x][y]]) {
		return 0;
	}
	int t = 0;
	lt[a[x][y]] = 1;
	for (int i = 0; i < 4; i++) {
		ans = dfs(x + xr[i], y + yr[i]);
		if (t < ans) {
			t = ans;
		}
	}
	lt[a[x][y]] = 0;
	return t + 1;
}
int main() {
	cin >> n >> m;//输入矩阵大小
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ch;
			a[i][j] = ch - 'A';
		}
	}
	ans = dfs(0, 0);//从0,0的位置开始搜
	cout << ans << endl;
	return 0;
}