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
int t, n, m, a[10005], ans = 0, Ma, Mi;
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
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
  t = In();
  for (register int T(1); T <= t; ++T) {
	  n = In();
	  ans = 1;
  	for (register int i(1); i <= n; ++i) {
    	a[i] = In();
  	}
  	for (register int i(1); i <= n; ++i) {
  		Ma = Mi = a[i];
  		for (register int len(2); len + i <= n + 1; ++len) {
  			Ma = max (a[len + i - 1], Ma);
  			Mi = min (a[len + i - 1], Mi);
  			if (Ma == a[len + i - 1] && Mi == a[i]) {
  				ans = max(ans, len);
				}
			}
		}
		printf("%d\n", ans - 1);
  }
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}

