#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
//#include<minmax.h>
using namespace std;
int n = 1, a[200005], k;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cin >> k;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= k; i++) {
		printf("%d\n", a[n - i + 1]);
	}
	return 0;
}