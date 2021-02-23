#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[7], ans = 0, t;
bool flag = 0;
int main() {
	for (int i = 1; i <= 6; i++) {
		scanf("%d", &a[i]);
		if (a[i]) {
			flag = 1;
		}
	}
	while (flag) {
		flag = 0;
		ans = 0;
		ans += a[6];
		if (a[5] > 0) {
			a[1] -= 11 * a[5];
			ans += a[5];
		}
		if (a[4] > 0) {
			ans += a[4];
			t = a[2] - (a[4] * 5);
			if (t <= 0) {//2*2的格子给放完
				a[1] -= (a[4] * 20) - a[2] * 4;
				a[2] = 0;
			}//结束后保证t和a[4]有一个为零
			else {//空隙填满2*2的格子
				a[2] -= a[4] * 5;
			}
		}
		if (a[3] > 0) {
			ans += a[3] / 4;
			a[3] %= 4;
			if (a[3]) {
				ans++;
				t = (4 - a[3]) * 2 - 1;
				if (a[2] > t) {//放满2*2
					a[2] -= t;
					a[1] -= 36 - 9 * a[3] - t * 4;
				}
				else {//放完2*2
					a[2] = 0;
					a[1] -= 36 - 9 * a[3] - a[2] * 4;
				}
			}
		}
		if (a[2] > 0) {
			ans += a[2] / 9;
			if (a[2] % 9) {
				ans++;
				a[1] -= 36 - ((a[2] % 9) * 4);
			}
		}
		if (a[1] > 0) {
			ans += a[1] / 36;
			if (a[1] % 36) {
				ans++;
			}
		}
		printf("%d\n", ans);
		for (int i = 1; i <= 6; i++) {
			scanf("%d", &a[i]);
			if (a[i]) {
				flag = 1;
			}
		}
	}
	return 0;
}