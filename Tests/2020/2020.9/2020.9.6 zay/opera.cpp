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
int n, m, ans = 0, T;
long long val1, val2, d1, d2, da1, da2, w;
bool flg;
char ch;
string s;
struct Obj {
	int k, p;
}O[100005];
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
int main() {
  freopen("opera.in","r",stdin);
  freopen("opera.out","w",stdout);
  T = In();
  n = In();
  m = In();
  w = In();
  for (register int i(1); i <= m; ++i) {
    O[i].k = In();
  }
  for (register int i(1); i <= m; ++i) {
  	O[i].p = In();
	}
	da1 = In();
	da2 = In();
	d1 = In();
	d2 = In();
	if (T == 1) {
		printf("0\n");
		return 0;
	}
	if (T == 2) {
		for (register int i(1); i <= n; ++i) {
			if (d1 <= d2) {
				val1 += da1;
				d1 += w;
			}
			else {
				val2 += da2;
				d2 += w;
			}
		}
		printf("%lld\n", val1 - val2	);
		return 0;
	}
  return 0;
}
/*
0
3 2 1
50 1
20 100
100000 200000 2 3
*/
