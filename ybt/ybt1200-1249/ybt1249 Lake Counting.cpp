#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
int m, n, ans;
char ch;
bool a[205][205];
struct pst {
	int x, y;
} s, t, mv[8], at, Top;
queue <pst> q;
int main() {
	mv[0].x = 1;
	mv[0].y = 1;
	mv[1].x = 1;
	mv[1].y = -1;
	mv[2].x = 1;
	mv[2].y = 0;
	mv[3].x = 0;
	mv[3].y = 1;
	mv[4].x = 0;
	mv[4].y = -1;
	mv[5].x = -1;
	mv[5].y = 1;
	mv[6].x = -1;
	mv[6].y = 0;
	mv[7].x = -1;
	mv[7].y = -1;
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> ch;
			if (ch == 'W') {
				a[i][j] = 1;
			}
		}
	}
	ans = 0;
	for (int j = 1; j <= m; j++) {
		for (int k = 1; k <= n; k++) {
			if (a[j][k]) {
				q.push(pst{ j, k });
				ans++;
				while (!(q.empty())) {
					Top = q.front();
					for (int i = 0; i < 8; i++) {
						at.x = Top.x + mv[i].x;
						at.y = Top.y + mv[i].y;
						if ((at.x > 0) && (at.x <= m)) {
							if ((at.y > 0) && (at.y <= n)) {
								if (a[at.x][at.y]) {
									q.push(at);
									a[at.x][at.y] = 0;
								}
							}
						}
					}
					q.pop();
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}