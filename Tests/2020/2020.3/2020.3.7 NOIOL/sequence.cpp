#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int a[100005], b[100005], c[100001], ans, l, cnt = 0, T, n, m, act, fst, scd;
long long sum = 0;
vector<int> pic_1[100005], pic_2[100005];
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
bool judge() {
	for (int ji = 1; ji <= n; ji++) {
		if (c[ji]) {
			return false;
		}
	}
	return true;
}
int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	T = read();
	for (int faq = 1; faq <= T; faq++) {
		n = read();
		m = read();
		for (int i = 1; i < n; i++) {
			a[i] = read();
		}
		for (int i = 1; i < n; i++) {
			b[i] = read();
		}
		for (int i = 1; i < n; i++) {
			c[i] = b[i] - a[i];
			sum += c[i];
		}
		if (sum % 2 == 0) {
			cout << "NO" << endl;
			continue;
		}
		for (int i = 1; i < m; i++) {
			act = read();
			if (act == 1) {
				fst = read();
				scd = read();
				pic_1[fst].push_back(scd);
				pic_1[scd].push_back(fst);
			}
			else {
				fst = read();
				scd = read();
				pic_2[fst].push_back(scd);
				pic_2[scd].push_back(fst);
			}
		}
		cout << "YES" << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}