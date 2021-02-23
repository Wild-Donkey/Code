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
int n, m, a[10005], ans = 0;
bool flg[100005] = {0};
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
  n = In();
  for (register int i(1); i <= n; ++i) {
    a[i] = In();
  }
  for (register int i(1); i <= n; ++i) {
  	for (register int j(i + 1); j <= n; ++j) {
  		flg[a[i] + a[j]] = 1;
		}
	}
	for (register int i(1); i <= n; ++i) {
		if (flg[a[i]]) {
			ans++;
		}
	}
	printf("%d\n", ans);
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}

