#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
int n;
double now, disp = 0, c = 0, ans = 0;
bool flg;
char ch;
string s;
struct Point {
	double adr, pri, oil;
}P[105];
struct Oil {
	double pri[105], wei[105], tot;
	int r;
	bool yes[105];
	inline int Findb () {
		int tmp = 0;
		pri[0] = -0x3f3f3f3f;
		for (register int i(1); i <= r; ++i) {
			if(yes[i]) {
				if (wei[i] <= 0) {
					yes[i] = 0;
				}
				if(pri[i] > pri[tmp]) {
					tmp = i;
				}
			}
		}
		return tmp;
	}
	inline int Finds () {
		int tmp = 0;
		pri[tmp] = 0x3f3f3f3f;
		for (register int i(1); i <= r; ++i) {
			if (yes[i]) {
				if (wei[i] <= 0) {
					yes[i] = 0;
				}
				if (pri[i] < pri[tmp]) {
					tmp = i;
				}
			}
		}
		return tmp;
	}
}O;
bool cmp (Point x, Point y) {
	return x.adr < y.adr;
}
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
  scanf("%lf %lf %lf %lf %d", &P[1].adr, &c, &disp, &P[1].pri, &n);
  //printf("%lf %lf %lf %lf %d\n", P[1].adr, c, disp, P[1].pri, n);
  n += 2;
  P[n].adr = P[1].adr;
  P[0].adr = P[1].adr = 0;
  P[0].oil = 0;
  //printf("%lf %lf %lf %lf %d\n", P[0].adr, c, disp, P[1].pri, n);
  for (register int i(2); i < n; ++i) {
    scanf("%lf%lf", &P[i].adr, &P[i].pri);
	}
	sort(P + 2, P + n, cmp);
	for (register int i(1); i <= n; ++i) {
		P[i].oil = (P[i].adr - P[i - 1].adr) / disp;
		//printf("%d %lf %lf %lf\n", i, P[i].oil, P[i].adr, P[i - 1].adr); 
		if (P[i].oil > c) {
			printf("No Solution\n");
			return 0; 
		}
	}
	O.tot = c;
	O.r = 1;
	O.wei[1] = c;
	O.pri[1] = P[1].pri;
	O.yes[1] = 1;
	O.pri[n] = 0x3f3f3f3f;
	//printf("faq\n");
	for (register int i(2); i <= n; ++i) {
		//printf("Arv %d\n", i); 
		int now = O.Finds();
		while (P[i].oil) {//烧便宜油
			//printf("Burn %d\n",now);
			if(O.wei[now] <= P[i].oil) {//这个价位的油烧完 
				ans += O.wei[now] * O.pri[now];
			//	printf("Shaowan %d %lf %lf %lf\n", i, ans, P[i].oil, O.wei[now]); 
				P[i].oil -= O.wei[now];
				O.tot -= O.wei[now];
				O.yes[now] = 0;
			}
			else {//这个价位的烧不完 
				O.wei[now] -= P[i].oil;
				O.tot -= P[i].oil;
				ans += P[i].oil * O.pri[now];
				//printf("Buwan %d %lf += %lf * %lf\n", i, ans, P[i].oil, O.pri[now]); 
				P[i].oil = 0;
			}
			now = O.Finds();
		}
		O.pri[++O.r] = P[i].pri;//买 
		O.wei[O.r] = (c - O.tot);
		O.tot = c;
		O.yes[O.r] = 1;
		now = O.Findb();
		while (P[i].pri < O.pri[now]) {//退了贵油
			O.wei[O.r] += O.wei[now];
			O.yes[now] = 0;
			now = O.Findb();
		}
	}
	printf("%.2lf\n", ans);
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}
/*
87.75 13.03 5.75 7.29 3
22.10 7.38
24.21 6.81
82.08 6.96
*/
