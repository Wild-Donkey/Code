#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int t, ans, r, b, c, d, e;
int main() {
	cin >> r >> b >> c >> d >> e;
	ans = r * c;
	ans += b * d;
	if (c + d < 2 * e) {
		t = min(r, b);
		ans += (2 * t * e) - (t * (c + d));
	}
	printf("%d\n", ans);
	return 0;
}