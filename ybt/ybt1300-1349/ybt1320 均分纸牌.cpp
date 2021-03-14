#include<iostream>
#include<cstring> 
#include<stack>
#include<algorithm>
#include<cstdio>
using namespace std;
int n, a[105], sum, mid, ans;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	mid = sum / n;
	for (int i = 1; i <= n; i++) {
		if (a[i] == mid) {
			continue;
		}
		if (a[i] > mid) {
			a[i + 1] += a[i] - mid;
			a[i] = mid;
			ans++;
			continue;
		}
		if (a[i] < mid) {
			a[i + 1] -= mid - a[i];
			a[i] = mid;
			ans++;
			continue;
		}
	}
	cout << ans << endl;
	return 0;
}