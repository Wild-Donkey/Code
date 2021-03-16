#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int  a[25][25], m, n, X, Y;
bool vsd[25][25];
string ch;
int DFS(int x, int y) {
	if (vsd[x][y]) {
		return 0;
	}
	vsd[x][y] = 1;
	if (!(a[x][y])) {
		return 0;
	}
	if ((x == 0) || (y == 0)) {
		return 0;
	}
	if ((x > n) || (y > m)) {
		return 0;
	}
	int ans = 1;//包括他本身
	ans += DFS(x + 1, y);
	ans += DFS(x - 1, y);
	ans += DFS(x, y + 1);
	ans += DFS(x, y - 1);
	return ans;
}
int main() {
	cin >> m >> n;
	while ((m != 0) && (n != 0)) {
		memset(a, 0, sizeof(a));
		memset(vsd, 0, sizeof(vsd));
		for (int i = 1; i <= n; i++) {
			cin >> ch;
			for (int j = 1; j <= m; j++) {
				if (ch[j - 1] == '.') {
					a[i][j] = 1;//第i行第j列
				}
				if (ch[j - 1] == '#') {
					a[i][j] = 0;
				}
				if (ch[j - 1] == '@') {
					a[i][j] = 1;
					X = i;
					Y = j;
				}
			}
		}
		cout << DFS(X, Y) << endl;
		cin >> m >> n;
	}
	return 0;
}