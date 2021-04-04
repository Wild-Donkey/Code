#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int a[6][2], b[3][2], c[12], t, tmp, cnt, x, y, z;
bool flag = 0;
int main() {
	freopen("box.in", "r", stdin);
	freopen("box.out", "w", stdout);
	cin >> t;
	for (register int i = 1; i <= t; i++) {
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		cnt = 0;
		flag = 0;
		for (int j = 0; j <= 5; j++) {
			scanf("%d%d", &a[j][0], &a[j][1]);
			c[2 * j] = a[j][0];
			c[2 * j + 1] = a[j][1];
			if (a[j][0] > a[j][1]) {//使第一个数小于第二个
				swap(a[j][0], a[j][1]);
			}
		}
		for (int j = 5; j >= 0; j--) {
			for (int k = 0; k < j; k++) {//排序a
				if (a[k][0] > a[k + 1][0]) {
					swap(a[k][0], a[k + 1][0]);
					swap(a[k][1], a[k + 1][1]);
				}
			}
		}
		for (int j = 11; j >= 0; j--) {
			for (int k = 0; k < j; k++) {//排序c
				if (c[k] > c[k + 1]) {
					swap(c[k], c[k + 1]);
				}
			}
		}
		for (int j = 0; j <= 11; j += 4) {//判断3*4
			if (!((c[j] == c[j + 1]) && (c[j + 1] == c[j + 2]) && (c[j + 2] == c[j + 3]))) {
				flag = 1;
				break;
			}
		}
		x = c[0];
		y = c[4];
		z = c[8];
		for (int j = 0; j <= 5; j += 2) {//判断2*3
			if (a[j][0] != a[j + 1][0]) {
				flag = 1;
				break;
			}
			b[cnt][0] = a[j][0];
			b[cnt][1] = a[j][1];
			cnt++;
		}
		if (b[0][0] != b[1][0]) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		if (b[1][1] < b[0][1]) {
			swap(b[0][1], b[1][1]);
		}
		if (b[0][1] != b[2][0]) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		if (b[1][1] != b[2][1]) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		if (flag) {
			flag = 0;
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		cout << "POSSIBLE" << endl;
	}
	return 0;
}
