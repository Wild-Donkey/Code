#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<string>
#include<stack>
using namespace std;
int zs[1000007], cnt, m, n, ans, phi[10000007], t;
bool shai[10000007];
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
int main() {
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);
	n = read();
	m = read();
	if (n > m) {
		t = n;
	}
	else {
		t = m;
	}
	phi[1] = 1;
	for (int i = 2; i <= t; i++)
	{
		if (!shai[i])//i为素数
		{
			zs[++cnt] = i;//将i加入素数数组p中
			phi[i] = i - 1;//i是素数    
		}
		for (int j = 1; (j <= cnt) && (zs[j] * i <= t); j++) { //用当前已得到的素数数组p筛,筛去p[j]*i
			shai[zs[j] * i] = 1;//可以确定i*p[j]不是素数 
			if (!(i % zs[j])) {//看p[j]是否是i的约数,因为素数p[j],等于判断i和p[j]是否互质 
				phi[zs[j] * i] = phi[i] * zs[j];
				break;
			}
			else {
				phi[zs[j] * i] = phi[i] * (zs[j] - 1); //互质
			}
		}
	}
	for (int i = 1; i < n; i++) {
		ans += phi[i];
		ans %= 19268017;
	}
	for (int i = 1; i < m; i++) {
		ans += phi[i];
		ans %= 19268017;
	}
	cout << ans << endl;
	return 0;
}