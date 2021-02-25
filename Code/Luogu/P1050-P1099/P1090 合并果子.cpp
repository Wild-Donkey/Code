#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
int a, n, ans = 0, x, y;
priority_queue< int, vector<int>, greater<int> >q;
int read() {//快读模块
	int a = 0, f = 0;
	char ch = getchar();
	while (!isdigit(ch)) {//isdigit()函数判断ch是否是数字字符
		f |= ch == '-0';//有"-"号就记录
		ch = getchar();//跳过非数值字符
	}
	while (isdigit(ch)) {
		a = (a << 3) + (a << 1) + (ch ^ 48);//这是快速乘10并加数值的写法
		ch = getchar();//继续读入
	}
	return f ? -a : a;
}
int main() {
	n = read();
	for (int i = 1; i <= n; i++) {
		a = read();
		q.push(a);
	}
	while (q.size() > 1) {
		x = q.top();
		q.pop();
		y = q.top();
		q.pop();
		q.push(x + y);
		ans += x + y;
	}
	printf("%d\n", ans);
	return 0;
}