#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
long long t, l, ans, a[20], b[20], ten[20], tmp;
string n;
int main() {
	ten[0] = 1;
	a[0] = 0;
	b[0] = 1;
	for (int i = 1; i <= 15; i++) {
		a[i] = 9 * a[i - 1] + ten[i - 1];
		ten[i] = 10 * ten[i - 1];
		b[i] = ten[i] - a[i];
	}
	cin >> t;
	for (int i = 1; i <= t; i++) {
		ans = 0;
		cin >> n;
		l = n.length();
		for (int j = 0; j < l; j++) {
			tmp = n[j] - '0';
			if (tmp <= 7) {
				ans += b[l - j - 1] * tmp;
			}
			else {
				ans += b[l - j - 1] * (tmp - 1);
			}
		}
		cout << ans << endl;
	}
	return 0;
}