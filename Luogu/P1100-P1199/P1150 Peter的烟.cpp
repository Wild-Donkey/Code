#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int smk, di, k, t, ans;
int main() {
	cin >> smk >> k;
	ans = smk;
	while (smk >= k) {
		t = smk / k;
		smk %= k;
		smk += t;
		ans += t;
	}
	cout << ans << endl;
	return 0;
}