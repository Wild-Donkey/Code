#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<string>
#include<stack>
using namespace std;
long long A, B, C, y, x, c, ans;
bool flg = 0;
long long read() {//快读模块
	long long ra = 0, rf = 0;
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
void exgcd(long long a, long long b, long long& x/*xa%b=1*/, long long& y/*yb%a=1*/) {
	if (b == 0) {
		x = 1;
		y = 0;
		c = a;
		return;
	}
	exgcd(b, a % b, y, x);
	long long m = a / b;
	y -= m * x;
	return;
}
int main() {
	freopen("folder.in", "r", stdin);
	freopen("folder.out", "w", stdout);
	A = read();
	B = read();
	C = read();
	if (B > A) {
		flg = 1;
	}
	x = 1;
	y = 0;
	if (flg) {
		exgcd(B, A, x, y);
	}
	else {
		exgcd(A, B, x, y);
	}
	if (C % c) {
		cout << "N0" << endl << "O" << endl;
	}
	else {
		ans = C / c;
		ans *= y;
		ans %= B;
		ans += B;
		ans %= B;
		cout << "YE5" << endl << ans;
	}
	return 0;
}