#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int  m, n, X, Y, T;
bool vsd[25][25];
string ch;
int DFS(int x, int y, int lst) {
	if ((x < 0) || (y < 0)) {
		return 0;
	}
	if ((x >= n) || (y >= m)) {
		return 0;
	}//先进行这两步判断，防止数组超限
	if (vsd[x][y]) {
		return 0;
	}
	if (lst == 1) {
		return 1;//边界
	}
	vsd[x][y] = 1;
	int ans = 0;
	ans += DFS(x + 1, y + 2, lst - 1);
	ans += DFS(x + 1, y - 2, lst - 1);
	ans += DFS(x - 1, y + 2, lst - 1);
	ans += DFS(x - 1, y - 2, lst - 1);
	ans += DFS(x + 2, y + 1, lst - 1);
	ans += DFS(x - 2, y + 1, lst - 1);
	ans += DFS(x + 2, y - 1, lst - 1);
	ans += DFS(x - 2, y - 1, lst - 1);
	vsd[x][y] = 0;
	return ans;
}
int main() {
	cin >> T;
	for (int k = 1; k <= T; k++) {
		memset(vsd, 0, sizeof(vsd));
		cin >> n >> m >> X >> Y;
		cout << DFS(X, Y, (m * n)) << endl;
	}
	return 0;
}