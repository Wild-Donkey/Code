#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int a[200005], b[200005], Tmp[200005], ans = 0, n, m, act, Do;
int read() {//快读模块
	int ra = 0, rf = 0;
	char ch = getchar();
	while (!isdigit(ch)) {//isdigit()函数判断ch是否是数字字符
		rf |= ch == '-0';//有"-"号就记录
		ch = getchar();//跳过非数值字符
	}
	while (isdigit(ch)) {
		ra = (ra << 3) + (ra << 1) + (ch ^ 48);//这是快速乘10并加数值的写法
		ch = getchar();//继续读入
	}
	return rf ? -ra : ra;
}
void Merge(int l, int r) {
	if (l == r)
		return;
	int mm = (l + r) / 2, mi = l, mj = mm + 1, mk = l;
	Merge(l, mm);
	Merge(mm + 1, r);
	while (mi <= mm && mj <= r) {
		if (b[mi] <= b[mj]) {
			Tmp[mk++] = b[mi++];
		}
		else {
			Tmp[mk++] = b[mj++];
			ans += mm - mi + 1;
		}
	}
	while (mi <= mm) {
		Tmp[mk++] = b[mi++];
	}
	while (mj <= r) {
		Tmp[mk++] = b[mj++];
	}
	for (int mb = l; mb <= r; mb++) {
		b[mb] = Tmp[mb];
	}
	return;
}
int main() {
	freopen("bubble.in", "r", stdin);
	freopen("bubble.out", "w", stdout);
	n = read();
	m = read();
	for (int i = 1; i <= n; i++) {
		b[i] = read();
		a[i] = b[i];
	}
	Merge(1, n);
	for (int i = 1; i <= m; i++) {
		act = read();
		Do = read();
		if (act == 1) {
			if (a[Do] > a[Do + 1]) {
				ans--;
			}
			else {
				ans++;
			}
			swap(a[Do], a[Do + 1]);
		}
		else {
			while (Do > 0) {
				for (int j = n; j > 1; j--) {
					if (a[j] < a[j - 1]) {
						ans--;
						swap(a[j], a[j - 1]);
						Do--;
						if (!(Do)) {
							break;
						}
					}
				}
				if (ans == 0) {
					break;
				}
			}
			cout << ans << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}