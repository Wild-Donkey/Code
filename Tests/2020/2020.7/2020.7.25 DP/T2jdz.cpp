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
int t, n, k, a[10005], miu[105][105], ans = 0, f[55][105][105];
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
void dfs (int cnt, int r, int sum, int root) {
	if (cnt == k) {
		sum += f[root][r];
		if (sum < ans) {
			ans = sum;
		}
		return;
	}
	for (register int i = r + 2; i <= root + n;++i) {
		dfs(cnt + 1, i, sum + miu[i][r]);
	}
	return;
}
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
  n = IN();
  k = IN();
  for (register int i(1); i <= n; ++i) {
  	a[i] = IN();
  }
  for (register int i(1); i <= n << 1; ++i) {
  	for (register int j(i + 1); j <= n << 1; ++j) {
  		miu[i][j] = miu[j][i] = abs(a[((i - 1) % n) + 1] - a[((j - 1) % n) + 1]);
	  }
  } 
  for (register int i(1); i < n << 1; ++i) {
  	miu[i][i + 1] = miu[i + 1][i] = 0x3f3f3f3f;
  }
  for (register int i(1); i <= n << 1; ++i) {
  	for (register int j(1); j <= n << 1; ++j) {
  		printf("%d	", miu[i][j]);
	  }
	printf("\n");
  }
  dfs(0,1,0);
  printf("%d\n", ans); 
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}

