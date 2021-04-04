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
/*
((max - min) - (max - max)) - ((max - min) - (max - a[i]))
= (max - min) - (a[i] - min)
= max - a[i] 
//a[i] when k == 3

(max - min) - (max - a[i])
= a[i] - min
//a[i] when k == 2
*/
using namespace std;
int n, a[200005], ans = 0, t, Ma, Mi;
bool flg;
long long k;
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
  	cin >> k;
  	k %= 2;
  	memset(a, 0, sizeof(a));
  	Ma = -0x3f3f3f3f;
  	Mi = 0x3f3f3f3f;
  	for (register int i(1); i <= n; ++i) {
    	a[i] = In();
    	if (Ma < a[i]) {
    		Ma = a[i];
			}
			if (Mi > a[i]) {
				Mi = a[i];
			}
  	}
  	if (k) {
  		for (register int i(1); i <= n; ++i) {
  			printf("%d ", Ma - a[i]);
			}
		}
		else {
  		for (register int i(1); i <= n; ++i) {
  			printf("%d ", a[i] - Mi);
			}
		}
		printf("\n");
	}
	// fclose(stdin);
  // fclose(stdout);
  return 0;
}

