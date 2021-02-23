#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int a[205][205], ans[205], at, n;
bool flg;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
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
	for (int i = 1; i <= n; i++) {
		ans[i] = 0x3fffffff;
		for (int j = 1; j <= n; j++) {
			a[i][j] = 0x3fffffff;//初始化
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			a[i][j] = read();//有向图,只能顺流而下
		}
	}
	ans[1] = 0;
	q.push(make_pair(0, 1));//第一个节点到它本身距离为0
	while (!q.empty()) {
		at = q.top().second;//中转节点
		q.pop();
		for (int i = at + 1; i <= n; i++) {
			if (ans[i] > ans[at] + a[at][i]) {
				ans[i] = ans[at] + a[at][i];
				q.push(make_pair(ans[i], i));//更新答案,维护队列
			}
		}
	}
	cout << ans[n] << endl;
	return 0;
}