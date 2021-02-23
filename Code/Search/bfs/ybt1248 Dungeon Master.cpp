#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
int w, l, h, ans[55][55][55];
char ch;
bool a[55][55][55];
struct pst {
	int x, y, z;
} s, t, mv[6], at, Top;
queue <pst> q;
int main() {
	mv[0].x = 1;
	mv[0].y = 0;
	mv[0].z = 0;
	mv[1].x = -1;
	mv[1].y = 0;
	mv[1].z = 0;
	mv[2].x = 0;
	mv[2].y = 1;
	mv[2].z = 0;
	mv[3].x = 0;
	mv[3].y = -1;
	mv[3].z = 0;
	mv[4].x = 0;
	mv[4].y = 0;
	mv[4].z = 1;
	mv[5].x = 0;
	mv[5].y = 0;
	mv[5].z = -1;
	cin >> h >> l >> w;
	while ((h != 0) && (l != 0) && (w != 0)) {
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= l; j++) {
				for (int k = 1; k <= w; k++) {
					ans[i][j][k] = 0x3f3f3f3f;
					cin >> ch;
					if (ch == 'S') {
						s.x = i;
						s.y = j;
						s.z = k;
					}
					if (ch == 'E') {
						t.x = i;
						t.y = j;
						t.z = k;
						a[i][j][k] = 1;
					}
					if (ch == '.') {
						a[i][j][k] = 1;
					}
				}
			}
		}
		q.push(s);
		ans[s.x][s.y][s.z] = 0;
		while (!(q.empty())) {
			Top = q.front();
			for (int i = 0; i < 6; i++) {
				at.x = Top.x + mv[i].x;
				at.y = Top.y + mv[i].y;
				at.z = Top.z + mv[i].z;
				if ((at.x > 0) && (at.x <= h)) {
					if ((at.y > 0) && (at.y <= l)) {
						if ((at.z > 0) && (at.z <= w)) {
							if (a[at.x][at.y][at.z]) {
								if (ans[at.x][at.y][at.z] > ans[Top.x][Top.y][Top.z] + 1) {
									ans[at.x][at.y][at.z] = ans[Top.x][Top.y][Top.z] + 1;
								}
								q.push(at);
								a[at.x][at.y][at.z] = 0;
							}
						}
					}
				}
			}
			q.pop();
		}
		if (ans[t.x][t.y][t.z] >= 0x3f3f3f3f) {
			printf("Trapped!\n");
		}
		else {
			printf("Escaped in %d minute(s).\n", ans[t.x][t.y][t.z]);
		}
		cin >> h >> l >> w;
	}
	return 0;
}