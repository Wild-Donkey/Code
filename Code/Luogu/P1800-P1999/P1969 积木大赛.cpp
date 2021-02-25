#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
int a[100005], n, x, y;
long long ans = 0;
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
void f(int l, int r) {
	if (l == r) {
		ans += a[l];
		a[l] = 0;
		return;
	}
	if (l > r) {
		return;
	}
	int t = l, tmp;
	for (int fi = l; fi <= r; fi++) {
		if (a[fi] <= a[t]) {
			t = fi;
		}
	}
	ans += a[t];
	tmp = a[t];
	for (int fi = l; fi <= r; fi++) {
		a[fi] -= tmp;
	}
	f(l, t - 1);
	f(t + 1, r);
	return;
}
int main() {
	n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	f(1, n);
	printf("%d\n", ans);
	return 0;
}