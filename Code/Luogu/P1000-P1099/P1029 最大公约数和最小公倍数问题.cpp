#include<cmath>
#include<cstdio>
#include<cstring>
//#include<minmax.h>
#include<iostream>
#include<algorithm>
using namespace std;
int t, a, b, p, q, ans = 1;
int gcd(int x, int y) {
	if (y == 0) {
		return x;
	}
	return gcd(y, x % y);
}
int main() {
	cin >> a >> b;
	if (b % a) {
		cout << 0 << endl;
		return 0;
	}
	if (b == a) {
		cout << 1 << endl;
		return 0;
	}
	b /= a;
	a = 1;
	t = sqrt(b);
	for (int i = 2; i <= t; i++) {
		if (b % i) {
			continue;
		}
		p = b / i;
		if (gcd(p, i) == 1) {
			ans++;
		}
	}
	ans *= 2;
	cout << ans << endl;
	return 0;
}