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
int m, n, a[200005], ans = 0, t, Ma1 = 0, Ma2 = 0;
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
  	memset(a, 0, sizeof(a));
  	Ma2 = Ma1 = 0;
  	for (register int i(1); i <= n; ++i) {
    	a[i] = In();
    	if (a[Ma1] < a[i]) {
    		Ma1 = i;
			}
			if (a[Ma2] <= a[i]) {
				Ma2 = i;
			}
  	}
		if (Ma1 == 1 && Ma2 == n) {
			printf("%d\n", n);
		}
		else {
			printf("1\n");
		}
	}
	// fclose(stdin);
  // fclose(stdout);
  return 0;
}

