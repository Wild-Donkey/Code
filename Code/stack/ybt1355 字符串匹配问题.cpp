#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<string>
#include<stack>
using namespace std;
int n, l, s, r, t;
string a;
stack <int> b;
bool flg = 0;
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
	cin >> t;
	getchar();
	for (int ti = 1; ti <= t; ti++) {
		getline(cin, a);
		l = a.length();
		while (!b.empty()) {
			b.pop();
		}
		flg = 0;
		for (int i = 0; i < l; i++) {
			if (a[i] == '(') {
				if (!b.empty())
					if (b.top() < 2) {
						flg = 1;
						break;
					}
				b.push(2);
			}
			if (a[i] == ')') {
				if (b.empty()) {
					flg = 1;
					break;
				}
				if (b.top() == 2) {
					b.pop();
				}
				else {
					flg = 1;
					break;
				}
			}
			if (a[i] == '[') {
				if (!b.empty())
					if (b.top() < 3) {
						flg = 1;
						break;
					}
				b.push(3);
			}
			if (a[i] == ']') {
				if (b.empty()) {
					flg = 1;
					break;
				}
				if (b.top() == 3) {
					b.pop();
				}
				else {
					flg = 1;
					break;
				}
			}
			if (a[i] == '{') {
				if (!b.empty())
					if (b.top() < 4) {
						flg = 1;
						break;
					}
				b.push(4);
			}
			if (a[i] == '}') {
				if (b.empty()) {
					flg = 1;
					break;
				}
				if (b.top() == 4) {
					b.pop();
				}
				else {
					flg = 1;
					break;
				}
			}
			if (a[i] == '<') {
				b.push(1);
			}
			if (a[i] == '>') {
				if (b.empty()) {
					flg = 1;
					break;
				}
				if (b.top() == 1) {
					b.pop();
				}
				else {
					flg = 1;
					break;
				}
			}
		}
		if (flg) {
			cout << "NO" << endl;
			continue;
		}
		if (b.empty()) {
			cout << "YES" << endl;
			continue;
		}
		cout << "NO" << endl;
	}
	return 0;
}