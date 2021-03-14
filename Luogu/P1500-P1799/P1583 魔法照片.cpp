#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int n, k, pls[15];
bool flg;
struct man {
	int w, num;
}a[20005];
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
bool cmp(man x, man y) {
	if (x.w == y.w) {
		return x.num < y.num;
	}
	return (x.w > y.w);
}
int main() {
	n = read();
	k = read();
	for (int i = 1; i <= 10; i++) {
		pls[i] = read();
	}
	for (int i = 1; i <= n; i++) {
		a[i].w = read();
		a[i].num = i;
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		a[i].w += pls[((i + 9) % 10) + 1];
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= k; i++) {
		cout << a[i].num << " ";
	}
	cout << endl;
	return 0;
}