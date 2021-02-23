#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[15], tmp, f[15], n, t, cnt = 0;
bool flag, vsd[15], flg = 0;
void dfs(int at) {
	for (int i = n; i >= 1; i--) {
		if (!(vsd[i])) {
			if (at == n) {//这是到了最后一位
				if (flag) {//这就是要输出的
					for (int i = 1; i < n; i++) {
						cout << f[i] << " ";
					}
					for (int i = 1; i <= n; i++) {
						if (!(vsd[i])) {
							cout << i << endl;
							flg = 1;
							return;
						}
					}
					flg = 1;
					return;
				}
				cnt++;
				f[at] = i;
				for (int j = 1; j <= n; j++) {//看看是不是所给序列
					if (a[j] != f[j]) {
						flag = 1;
						//cout << a[j]<<"	" << f[j]<<endl;
						break;
					}
				}
				if (!(flag)) {//就是本序列了
					//cout << cnt << endl;
					flag = 1;//已找到
				}
				else {
					flag = 0;
				}
				return;
			}
			f[at] = i;
			vsd[i] = 1;
			//cout << i << "	";
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
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f[i] = n - i + 1;
		if (a[i] != i) {
			flag = 1;
		}
	}
	if (!(flag)) {
		cout << "ERROR" << endl;
		return 0;
	}
	flag = 0;
	dfs(1);
	return 0;
}