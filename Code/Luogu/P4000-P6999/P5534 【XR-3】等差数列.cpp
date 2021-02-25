#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
long long n, a[5], d, ans;
int main() {
	cin >> a[1] >> a[2] >> n;
	d = a[2] - a[1];
	ans = a[1] * n;
	ans += (n * (n - 1) * d) / 2;
	cout << ans << endl;
	return 0;
}