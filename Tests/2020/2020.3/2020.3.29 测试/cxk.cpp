#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char t;
int n, m, tmp;
long long a, two[105];
int main() {
	freopen("cxk.in", "r", stdin);
	freopen("cxk.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> t;
		tmp = t - '0';
		a *= 2;
		a += tmp;
	}
	for (int i = 1; i <= m; i++) {
		cin >> t;
		if (t == '+') {
			a += 1;
		}
		if (t == '-') {
			a -= 1;
		}
		if (t == '*') {
			a = a << 1;
		}
		if (t == '/') {
			a = a >> 1;
		}
	}
	two[0] = 1;
	int j = 0;
	while (a > two[j]) {
		j++;
		two[j] = two[j - 1] * 2;
	}
	for (int i = j - 1; i >= 0; i--) {
		if (a >= two[i]) {
			a -= two[i];
			cout << 1;
		}
		else {
			cout << 0;
		}
	}
	cout << endl;
	return 0;
}
