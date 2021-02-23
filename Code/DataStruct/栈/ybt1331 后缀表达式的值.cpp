#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
string a;
int l, cnt = 0;
long long b[150], ans;
/*int read() {//快读模块
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
}*/
int main() {
	getline(cin, a);
	l = a.length();
	int ii = 0;
	while (isdigit(a[ii])) {
		cnt++;
		while (isdigit(a[ii])) {
			b[cnt] *= 10;
			b[cnt] += a[ii] - '0';
			ii++;
		}
		ii++;
	}
	ans = b[cnt];
	cnt--;
	while (a[ii] != '@') {
		if (a[ii] == '+') {
			ans = b[cnt] + ans;
		}
		if (a[ii] == '-') {
			ans = b[cnt] - ans;
		}
		if (a[ii] == '*') {
			ans = b[cnt] * ans;
		}
		if (a[ii] == '/') {
			ans = b[cnt] / ans;
		}
		ii++;
		cnt--;
	}
	printf("%lld\n", ans);
	return 0;
}