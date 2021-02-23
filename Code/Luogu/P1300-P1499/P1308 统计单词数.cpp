#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
string a, b;
int ans = 0, fst = -1, la, lb;
bool flg;
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
bool judge(char x) {
	return ((x >= 'a') && (x <= 'z'));
}
int main() {
	getline(cin, a);
	getline(cin, b);
	la = a.length();
	lb = b.length();
	int j;
	for (int i = 0; i < la; i++) {
		if ((a[i] >= 'A') && (a[i] <= 'Z')) {
			a[i] -= 'A';
			a[i] += 'a';
		}
	}
	for (int i = 0; i < lb; i++) {
		if ((b[i] >= 'A') && (b[i] <= 'Z')) {
			b[i] -= 'A';
			b[i] += 'a';
		}
	}
	for (int i = 0; i < lb; i++) {
		j = 0;
		while ((b[i] == a[j]) && (i < lb)) {
			if (j >= la - 1) {
				if (i - la < 0) {
					if (!judge(b[i + 1])) {
						flg = 1;
					}
					else {
						if (i + 1 >= lb) {
							flg = 1;
						}
					}
				}
				if (i + 1 >= lb) {
					if (!judge(b[i - la])) {
						flg = 1;
					}
				}
				if (!(flg)) {
					if ((!judge(b[i - la])) && (!judge(b[i + 1]))) {
						flg = 1;
					}
				}
				if (flg) {
					ans++;
					if (fst == -1) {
						fst = i - la + 1;
					}
					flg = 0;
				}
			}
			i++;
			j++;
		}
	}
	if (ans == 0) {
		cout << -1 << endl;
	}
	else {
		cout << ans << " " << fst << endl;
	}
	return 0;
}