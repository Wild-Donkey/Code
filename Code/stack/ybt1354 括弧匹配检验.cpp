#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<string>
#include<stack>
using namespace std;
int n, l, s, r;
string a;
stack <int> b;
char lst;
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
	b.push(0);
	for (int i = 0; i < l; i++) {
		if (a[i] == '(') {
			b.push(1);
		}
		if (a[i] == ')') {
			if (b.top() == 1) {
				b.pop();
			}
			else {
				cout << "Wrong" << endl;
				return 0;
			}
		}
		if (a[i] == '[') {
			b.push(2);
		}
		if (a[i] == ']') {
			if (b.top() == 2) {
				b.pop();
			}
			else {
				cout << "Wrong" << endl;
				return 0;
			}
		}
	}
	b.pop();
	if (b.empty()) {
		cout << "OK" << endl;
		return 0;
	}
	cout << "Wrong" << endl;
	return 0;
}