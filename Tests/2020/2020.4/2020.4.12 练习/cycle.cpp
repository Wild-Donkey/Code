#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int a, b, rcd[3005], tmp, cnt = 0, c, l = 0;
bool flag = 0;
int main() {
	freopen("cycle.in", "r", stdin);
	freopen("cycle.out", "w", stdout);
	cin >> a >> b;
	cout << a << "/" << b << "=" << a / b << ".";
	a %= b;
	tmp = b;
	while (tmp % 5 == 0) {//judge
		tmp /= 5;
	}
	while (tmp % 2 == 0) {
		tmp /= 2;
	}
	if (tmp == 1) {
		flag = 1;
	}
	if (flag) {
		while (a) {
			a *= 10;
			cout << a / b;
			a %= b;
		}
		cout << "(" << 0 << ")" << endl << 1 << endl;
	}
	else {
		tmp = a;
		while (tmp) {
			if (!(rcd[tmp])) {
				rcd[tmp] = 1;
				tmp *= 10;
				tmp %= b;
			}
			else {
				c = tmp;
				break;
			}
		}
		while (a != c) {
			a *= 10;
			cout << a / b;
			a %= b;
		}
		cout << "(";
		while ((a != c) || (l == 0)) {
			a *= 10;
			if (l <= 50) {
				cout << a / b;
			}
			a %= b;
			l++;
		}
		if (l > 50) {
			cout << "...)";
		}
		else {
			cout << ")";
		}
		cout << endl << l << endl;
	}
	return 0;
}
