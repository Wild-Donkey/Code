#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int  n, E[15], k;
struct fri {
	int D, C, num, W;
} s[20005];
bool cmp(fri x, fri y) {
	if (x.W == y.W)
		return (x.num < y.num);
	return (x.W > y.W);
}
int main() {
	cin >> n >> k;
	for (int i = 1; i <= 10; i++) {
		cin >> E[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> s[i].W;
		s[i].num = i;
	}
	sort(s + 1, s + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		s[i].D = i;
		s[i].W += E[((s[i].D - 1) % 10) + 1];
	}
	sort(s + 1, s + n + 1, cmp);
	for (int i = 1; i <= k; i++) {
		cout << s[i].num << " ";
	}
	return 0;
}