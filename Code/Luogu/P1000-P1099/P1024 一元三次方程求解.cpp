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
double a, b, c, d, pref, nowf, delta = 1, ans[10];
int cnt = 0;
bool flg;
char ch;
string s;
inline int In() {
  char ich = getchar();
  int intmp = 0, insign = 1;
  while (((ich < '0') || (ich > '9')) && ((ich != '-'))) {
    ich = getchar();
  }
  if (ich == '-') {
    insign = -1;
    ich = getchar();
  }
  while ((ich <= '9') && (ich >= '0')) {
    intmp *= 10;
    intmp += ich - '0';
    ich = getchar();
  }
  return intmp * insign;
}
double f (double x) {
	double sq = x * x, cu = sq * x;
	//printf ("%lf	%lf\n", x, cu * a + sq * b + x * c + d);
	return cu * a + sq * b + x * c + d;
}
void Find (double x, double y, double fx, double fy) {
//	printf("%lf %lf\n", x, y);
	double m = (x + y) / 2, fm = f(m);
	if (y - x <= 0.0001) {
		ans[++cnt] = x;
		return;
	} 
	if (fm == 0) {
		ans[++cnt] = m;
		return;
	}
	if (fm * fx < 0) {
		return Find (x, m, fx, fm);
	}
	return Find (m, y, fm, fy);
}
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
  scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
  pref = f(-100);
  if (pref == 0) {
  	ans[++cnt] = -100;
	}
  for (register double i(-100 + delta); i <= 100 && cnt <= 3; i += delta) {
  	nowf = f(i);
  	if (nowf * pref < 0) {
  		Find (i - delta, i, pref, nowf);
		}
  	if (nowf == 0) {
  		ans[++cnt] = i;
		}
		pref = nowf;
	}
	printf("%.2lf %.2lf %.2lf\n", ans[1], ans[2], ans[3]);
	// fclose(stdin);
  // fclose(stdout);
  return 0;
}

