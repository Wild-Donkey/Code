#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int a, b, l, d, A, B;
double ans[105][105], t, T = 9999999;
bool flag = 0;
int gcd(int x, int y) {
	if (y == 0) {
		return x;
	}
	x %= y;
	return gcd(y, x);
}
int main() {
	cin >> a >> b >> l;
	A = l;
	B = 1;
	if (a < b) {
		flag = 1;
		T = -T;
		swap(a, b);
		A = 1;
		B = l;
	}
	ans[0][0] = 1.000000000000 * a / b;
	if (a < l) {
		d = gcd(a, b);
		a /= d;
		b /= d;
		if (flag) {
			cout << b << " " << a << endl;
			return 0;
		}
		cout << a << " " << b << endl;
		return 0;
	}
	for (int i = 1; i <= l; i++) {
		for (int j = 1; j < i; j++) {
			ans[i][j] = 1.00000000000 * i / j;
			if (flag) {
				if (ans[i][j] < ans[0][0]) {
					t = ans[i][j] - ans[0][0];
					if (t > T) {
						T = t;
						A = i;
						B = j;
					}
				}
			}
			else {
				if (ans[i][j] > ans[0][0]) {
					t = ans[i][j] - ans[0][0];
					if (t < T) {
						T = t;
						A = i;
						B = j;
					}
				}
			}
		}
	}
	d = gcd(A, B);
	A /= d;
	B /= d;
	if (flag) {
		cout << B << " " << A << endl;
		return 0;
	}
	cout << A << " " << B << endl;
	return 0;
}