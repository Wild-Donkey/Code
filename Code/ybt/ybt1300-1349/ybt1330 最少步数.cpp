#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
int u = 1, d = 0, mvx[12] = { -2,-2,-1,1,2,2,2,2,1,-1,-2,-2 }, mvy[12] = { -1,-2,-2,-2,-2,-1,1,2,2,2,2,1 }, x_1, x_2, y_1, y_2, q[10005][3], s[105][105], x, y;
int main() {
	cin >> x_1 >> y_1 >> x_2 >> y_2;
	for (int i = 0; i <= 104; i++) {
		for (int j = 0; j <= 104; j++) {
			s[i][j] = 0x3fffffff;
		}
	}
	q[u][0] = 1;
	q[u][1] = 1;
	q[u][2] = 0;
	while (u >= d) {//队不空
		for (int i = 0; i < 12; i++) {
			x = q[d][0] + mvx[i];
			y = q[d][1] + mvy[i];
			if ((x >= 1) && (y >= 1) && (x <= 100) && (y <= 100)) {
				if (s[x][y] > (q[d][2] + 1)) {
					s[x][y] = q[d][2] + 1;
					u++;
					q[u][0] = x;
					q[u][1] = y;
					q[u][2] = s[x][y];
					if ((s[x_1][y_1] < 0x3fff) && (s[x_2][y_2] < 0x3fff)) {
						printf("%d\n%d\n", s[x_1][y_1], s[x_2][y_2]);
						return 0;
					}
				}
			}
		}
		d++;
	}
	return 0;
}