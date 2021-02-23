#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int a[2], n, ans = 0x3ffffff, pri;
int main() {
	cin >> n;
	for (int i = 1; i <= 3; i++) {
		cin >> a[0] >> a[1];
		if (n % a[0]) {
			pri = a[1] * (n / a[0] + 1);
		}
		else {
			pri = a[1] * n / a[0];
		}
		if (ans >= pri) {
			ans = pri;
		}
	}
	cout << ans << endl;
	return 0;
}