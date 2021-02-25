#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int n, m, u = 0, d = 0, cnt = 0, mvx[4] = { 1,0,-1,0 }, mvy[4] = { 0,1,0,-1 };
string a[1005];
bool vst[1005][1005] = { 0 };
struct pnt {
	int line, row;
} q[1000005];
void bfs(int x, int y) {
	int xx = 0, yy = 0;
	vst[x][y] = 1;
	for (int k = 0; k <= 3; k++) {
		xx = x + mvx[k];
		yy = y + mvy[k];
		if ((xx >= 0) && (yy >= 0)) {
			if ((xx < m) && (yy < n)) {
				if (!(vst[xx][yy])) {
					q[u].line = xx;
					q[u].row = yy;
					u++;
				}
			}
		}
	}
	return;
}
int main() {
	memset(vst, 1, sizeof(vst));
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if ((a[i][j] > '0') && (a[i][j] <= '9')) {
				vst[i][j] = 0;
			}
			else {
				vst[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!vst[i][j]) {
				cnt++;
				q[u].line = i;
				q[u].row = j;
				u++;
				while (u >= d) {
					bfs(q[d].line, q[d].row);
					d++;
				}
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}