#include<cstdio>
//#include<minmax.h>
#include<iostream>
using namespace std;
int m, ans = 0, l, r, L;
bool a[10005];
int main() {
	cin >> L >> m;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &l, &r);
		for (int j = l; j <= r; j++) {
			a[j] = 1;
		}
	}
	for (int i = 0; i <= L; i++) {
		if (!a[i]) {
			ans++;
		}
	}
	cout << ans << endl;//Êä³ö´ð°¸
	return 0;
}
