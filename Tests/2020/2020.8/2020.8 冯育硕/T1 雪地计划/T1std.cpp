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
int A, B, C, D, E, F, m, n, a[105][105][105], dif[105][105][105];
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
void Add (int x1, int y1, int z1, int x2, int y2, int z2) {
	++x2;
	++y2;
	++z2;
	++dif[x1][y1][z1];
	--dif[x2][y1][z1];
	--dif[x1][y2][z1];
	--dif[x1][y1][z2];
	++dif[x2][y2][z1];
	++dif[x2][y1][z2];
	++dif[x1][y2][z2];
	--dif[x2][y2][z2];
	return;
}
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
  n = In();
  m = In();
  memset(a, 0, sizeof(a));
  memset(dif, 0, sizeof(dif));
  for (register int i(1); i <= m; ++i) {
		A = In();
		B = In();
		C = In();
		D = In();
		E = In();
		F = In();
		Add (A, B, C, D, E, F);
	}
	for (register int i(1); i <= n; ++i) {
		printf("%d\n", i);
		for (register int j(1); j <= n; ++j) {
			for (register int k(1); k <= n; ++k) {
				a[i][j][k] = dif[i][j][k] + a[i - 1][j][k] + a[i][j - 1][k] + a[i][j][k - 1] - a[i - 1][j - 1][k] - a[i - 1][j][k - 1] - a[i][j - 1][k - 1] + a[i - 1][j - 1][k - 1];
				printf("%d ", a[i][j][k]);
			}
			printf("\n");
		}
	}
	// fclose(stdin);
  // fclose(stdout);
  return 0;
}
/*
3
1
2 2 2 2 2 3

1
0 0 0
0 0 0
0 0 0
2
0 0 0
0 1 1
0 0 0
3
0 0 0
0 0 0
0 0 0


5
2
1 1 1 3 3 3
3 3 3 5 5 5

1
1 1 1 0 0
1 1 1 0 0
1 1 1 0 0
0 0 0 0 0
0 0 0 0 0
2
1 1 1 0 0
1 1 1 0 0
1 1 1 0 0
0 0 0 0 0
0 0 0 0 0
3
1 1 1 0 0
1 1 1 0 0
1 1 2 1 1
0 0 1 1 1
0 0 1 1 1
4
0 0 0 0 0
0 0 0 0 0
0 0 1 1 1
0 0 1 1 1
0 0 1 1 1
5
0 0 0 0 0
0 0 0 0 0
0 0 1 1 1
0 0 1 1 1
0 0 1 1 1
*/
