#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int ans[15], tans[10][2], ten[10], n, t, l, tmp;
string s;
int main() {
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
	ten[0] = 1;
	for (int i = 1; i <= 6; i++) {
		ten[i] = ten[i - 1] * 10;
	}
	memset(tans, 0, sizeof(tans));
	tans[1][0] = 1;
	for (int i = 1; i <= 6; i++) {
		tans[i][1] += 10 * tans[i - 1][1];
		tans[i][1] += ten[i - 1];
	}
	cout << tans[1][0] << endl;
	for (int i = 2; i <= 6; i++) {
		tans[i][0] += 9 * tans[i - 1][0];
		tans[i][0] += ten[i - 1] - ten[i - 2];
	}
	scanf("%d", &t);
	for (register int i = 1; i <= t; i++) {
		memset(ans, 0, sizeof(ans));
		cin >> s;
		l = s.length();
		n = 0;
		for (int j = 0; j < l; j++) {
			n *= 10;
			n += s[j] - '0';
		}
		for (int j = 0; j < l; j++) {
			tmp = s[j] - '0';
			ans[0] += tmp * tans[l - j - 1][0];
			for (int k = 1; k <= 9; k++) {
				ans[k] += tmp * tans[l - j - 1][1];
			}
			for (int k = 1; k < tmp; k++) {
				ans[k] += ten[l - j - 1];
			}
			n -= tmp * ten[l - j - 1];
			ans[tmp] += n + 1;
		}
		printf("%d %d %d %d %d %d %d %d %d %d\n", ans[0], ans[1], ans[2], ans[3], ans[4], ans[5], ans[6], ans[7], ans[8], ans[9]);
	}
	return 0;
}
