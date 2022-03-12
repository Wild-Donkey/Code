#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[15], f[15], n, t, cnt = 0;
bool flag, vsd[15], flg = 0;
string tmp;
void dfs(int at) {
	for (int i = 1; i <= n; i++) {
		if (!(vsd[i])) {
			if (at == n) {//这是到了最后一位
				cnt++;
				f[at] = i;
				for (int j = 1; j <= n; j++) {//看看是不是所给序列
					if (a[j] != f[j]) {
						flag = 1;
						break;
					}
				}
				if (!(flag)) {//就是本序列了
					cout << cnt << endl;
					flag = 1;//已找到
					return;
				}
				else {
					flag = 0;
				}
				return;
			}
			f[at] = i;
			vsd[i] = 1;
			dfs(at + 1);
			if (flg) {
				return;
			}
			f[at] = 0;
			vsd[i] = 0;
		}
		if (flg) {
			return;
		}
	}
	return;
}
int main() {
	cin >> n;
	cin >> tmp;
	for (int i = 1; i <= n; i++) {
		a[i] = tmp[i - 1] - '0';
	}
	dfs(1);
	return 0;
}