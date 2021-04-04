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
int n, t, ans, cp;
bool flg, a[200005];
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
  	cin >> s;
  	cp = 0;
  	for (register int i(0); i < n; ++i) {
  		a[i + 1] = (s[i] == 'L' ? 0 : 1);
  		if (a[i + 1]) {
  			if (a[(i + n - 1) % n] + 1) {
  				cp++;
				}
			}
		}
  	for (register int i(1); i <= n; ++i) {
  		if (a[i]) {
  			
			}
  	}
		printf("%d\n", ans);
	}
	// fclose(stdin);
  // fclose(stdout);
  return 0;
}

