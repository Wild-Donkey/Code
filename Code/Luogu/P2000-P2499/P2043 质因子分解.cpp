#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int n, ans[10005] = { 0 }, zh[5005], cnt = 1;
bool zs[10005];
void recorde(int x) {
	int i = 1;
	while (x > 1) {
		if (x % zh[i] == 0) {
			ans[i]++;
			x /= zh[i];
		}
		else {
			i++;
		}
	}
}
int main() {
	cin >> n;
	for (int i = 2; i <= n; i++) {
		if (!(zs[i])) {
			zh[cnt++] = i;
			int t = i * 2;
			while (t <= n) {
				zs[t] = 1;
				t += i;
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		recorde(i);
	}
	for (int i = 1; i <= cnt; i++) {
		if (ans[i]) {
			cout << zh[i] << " " << ans[i] << endl;
		}
	}
	return 0;
}