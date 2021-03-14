#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int T, w, s;
double ans = 0.0000;
struct mt {
	double pr, wt, vl;
}mtl[105];
bool cmp(mt x, mt y) {
	return (x.pr > y.pr);
}
int main() {
	cin >> T;
	for (int h = 1; h <= T; h++) {
		cin >> w >> s;
		for (int i = 1; i <= s; i++) {
			cin >> mtl[i].wt >> mtl[i].vl;
			mtl[i].pr = mtl[i].vl / mtl[i].wt * 1.0000;
		}
		sort(mtl + 1, mtl + s + 1, cmp);
		for (int i = 1; i <= s; i++) {
			if (mtl[i].wt <= w) {
				w -= mtl[i].wt;
				ans += mtl[i].vl;
			}
			else {
				ans += mtl[i].pr * w;
				break;
			}
		}
		printf("%.2lf\n", ans);
		ans = 0.0000;
	}
	return 0;
}