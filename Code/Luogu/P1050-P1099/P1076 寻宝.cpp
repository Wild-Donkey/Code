#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
int a[10005][105], cnt[10005], n, m, at, wk, ans;
bool b[10005][105];
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
int main() {
	n = read();
	m = read();
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			b[i][j] = read();
			a[i][j] = read();
			if (b[i][j]) {
				cnt[i]++;
			}
		}
	}
	at = read();
	for (int i = 1; i <= n; i++) {
		wk = a[i][at];
		ans += wk;
		ans %= 20123;
		wk = (wk + 1) % cnt[i] - 1;
		wk += cnt[i];
		int ii = at;
		while (wk) {
			if (b[i][ii]) {
				wk--;
				at = ii;
			}
			ii++;
			ii = ii % m;
		}
	}
	printf("%d\n", ans);
	return 0;
}