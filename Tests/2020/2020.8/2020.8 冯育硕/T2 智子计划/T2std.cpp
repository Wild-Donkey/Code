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
long long A, B, C, D, E, m, n, a[1005][1005], dif[1005][1005], b[1005][1005], Mi, Ma, Do;
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
void Add (long long x1, long long y1, long long x2, long long y2, long long val) {
	++x2;
	++y2; 
	dif[x1][y1] += val;
	dif[x2][y2] += val;
	dif[x1][y2] -= val;
	dif[x2][y1] -= val;
	return;
}
void Polish () {
	Mi = 0x3f3f3f3f3f3f3f3f;
	Ma = 0;
	for (register int i(1); i <= n; ++i) {
		for (register int j(1); j <= n; ++j) {
			a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + dif[i][j];
			b[i][j] += a[i][j];
			b[i][j] = max(b[i][j], (long long)0); 
			Mi = min(Mi, b[i][j]);
			Ma = max(Ma, b[i][j]); 
		}
	}
	Mi = (Mi + Ma) >> 1;
	for (register int i(1); i <= n; ++i) {
		for (register int j(1); j <= n; ++j) {
			b[i][j] = Mi;
		}
	}
	return; 
}
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
  n = In();
  m = In();
  memset(a, 0, sizeof(a));
  memset(dif, 0, sizeof(dif));
  for (register int i(1); i <= n; ++i) {
  	for (register int j(1); j <= n; ++j) {
  		b[i][j] = In();
		}
	}
  for (register int i(1); i <= m; ++i) {
  	Do = In();
		if (Do == 2) {
			Polish ();
			memset(a, 0, sizeof(a));
			memset(dif, 0, sizeof(dif));
		}
		else {
			A = In();
			B = In();
			C = In();
			D = In();
			E = In();
			if (Do) {
				Add (A, B, C, D, -E);
			}
			else {
				Add (A, B, C, D, E);
			}
		}
	}
	for (register int i(1); i <= n; ++i) {
		for (register int j(1); j <= n; ++j) {
			a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + dif[i][j];
			b[i][j] += a[i][j];
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
	// fclose(stdin);
  // fclose(stdout);
  return 0;
}
/*
3 3
1 2 3
3 3 3 
2 2 2
0 1 1 3 3 1
2
1 1 2 3 3 2
*/
