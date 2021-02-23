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
int t, n, m, a[105][105], f[100005], ans = 0;
bool flg;
char ch;
string s;
inline int IN() {
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
	t = IN();
	n = IN();
	m = IN();
	for (register int T(1); T <= t; ++T) {
		for (register int i(1); i <= n; ++i) {
			a[T][i] = IN();
		}
	}
	for (register int T(2); T <= t; ++T) {
		memset(f, 0, sizeof(f));
		for (register int i(1); i <= n; ++i) {	
			for (register int j(a[T - 1][i]); j <= m; ++j) {
				f[j] = max(f[j], f[j - a[T - 1][i]] + a[T][i] - a[T - 1][i]);
			}
		}
		m += max (f[m], 0);
	}
    printf("%d\n", m);
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}

