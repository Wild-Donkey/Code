#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n, a1, a2, b1, b2, a, b, c;
char ch;
int gcd(int x, int y) {
	if (y == 0) {
		return x;
	}
	else {
		return gcd(y, x % y);
	}
}
int main() {
	cin >> a1 >> ch >> b1 >> a2 >> ch >> b2;
	a = a1 * a2;
	b = b1 * b2;
	c = gcd(a, b);
	a = a / c;
	b = b / c;
	cout << b << " " << a << endl;
	return 0;
}