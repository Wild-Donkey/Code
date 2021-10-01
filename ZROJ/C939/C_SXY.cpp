#include <bits/stdc++.h>
typedef long long ll;
const int N = 1e3 + 5;
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
int n, m, ans, g[N][N][27], f[N], a[N];
char s[N];
void solve(int x) {
	if (g[1][x][0] < m) {
		printf("-1\n");
		return;
	}
	if (g[1][x][0] == m) {
		printf("1\n");
		return;
	}
	for (int i = 1; i <= x; i++) {
		if (f[i]) {
			if (g[i + 1][x][0] == m) {
				if (f[x] == 0) f[x] = f[i] + 1;
				f[x] = f[x] < f[i] + 1 ? f[x] : f[i] + 1;
			}
		}
	}
	if (!f[x]) printf("-1\n");
	else printf("%d\n", f[x]);
}
int main() {
  freopen("C.in", "r", stdin);
  freopen("C.ans", "w", stdout);
	m = read();
	scanf("%s", s);
	n = strlen(s);
	for (int i = 1; i <= n; i++) a[i] = s[i - 1] - 'a' + 1;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (!g[i][n][a[j]]) g[i][n][0]++;
			g[i][n][a[j]]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = n - 1; j >= 1; j--) {
			for (int k = 1; k <= 26; k++) {
				g[i][j][k] = g[i][j + 1][k];
			}
			g[i][j][0] = g[i][j + 1][0];
			g[i][j][a[j + 1]]--;
			if (!g[i][j][a[j + 1]]) g[i][j][0]--;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (g[1][i][0] == m) f[i] = 1;
	}
	for (int i = 1; i <= n; i++) solve(i);
	return 0;
}
/*
1
abaaa
1
babaabcb
2
cbbaaacbaa
*/

