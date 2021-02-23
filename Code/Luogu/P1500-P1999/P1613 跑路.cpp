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
int A, B, n, m, a[10005], ans = 0, cntse = 0, jz[55][55];
bool dist[55][55][55];
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
int Cnt (int x) {
	if (x > 1000000) {
		return 0x3f3f3f3f;
	}
	int cans = 0;
	for (register int i(0); i < 20; ++i) {
		if ((1 << i) & x) {
			++cans;
		}
	}
	return cans;
}
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
  n = In();
  m = In();
  memset (jz, 0x3f, sizeof(jz));
  memset (dist, 0, sizeof(dist));
	for (register int i(1); i <= m; ++i) {
    A = In();
    B = In();
    jz[A][B] = 1;
    dist[A][B][0] = 1;
    if(A == B) {
    	for (register int j(1); j <= 50; ++j) {
    		dist[A][B][j] = 1;
			}
		}
  }
  for (register int t(0); t < 50; ++t) {
  	for (register int k(1); k <= n; ++k) {
  		for (register int i(1); i <= n; ++i) {
  			for (register int j(1); j <= n; ++j) {
  				if (dist[i][k][t] && dist[k][j][t]) {
  					dist[i][j][t + 1] = 1;
  					jz[i][j] = 1;
					}
				}
			}
		}
	}
	/*for (register int i(1); i <= n; ++i) {
		printf("\n%d	", i);
		for (register int j(1); j <= n; ++j) {
			printf("%d %d	", j, jz[i][j]);
		}
	}*/
  for (register int k(1); k <= n; ++k) {
  	for (register int i(1); i <= n; ++i) {
  		for (register int j(1); j <= n; ++j) {
  			jz[i][j] = min (jz[i][j], jz[i][k]+jz[k][j]);
			}
		}
	}
	/*for (register int i(1); i <= n; ++i) {
		printf("\n%d	", i);
		for (register int j(1); j <= n; ++j) {
			printf("%d %d	", j, jz[i][j]);
		}
	}*/
	if (jz[1][n] <= 1000000) {
		printf("%d\n", jz[1][n]);
	}
	else {
		printf("-1\n");
	}
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}

