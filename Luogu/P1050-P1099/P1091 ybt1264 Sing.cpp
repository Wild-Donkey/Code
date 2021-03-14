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
#define Wild_Donkey 0
using namespace std;
inline unsigned int RD() {
  unsigned int intmp = 0;
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') {
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) {
    rdch = getchar();
  }
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = rdtp * 10 + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned int a[1005], f[1005], g[2][1005], m, n, Cnt(0), A, B, C, D, len(0), Ans(0);
bool b[1005];
char s[1005];
inline void Clr() {
  n = RD();
  len = 0;
  memset(a, 0, sizeof(a));
  memset(f, 0, sizeof(f));
  memset(g, 0, sizeof(g));
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  Clr();
  for (register unsigned int i(1); i <= n; ++i) {
    a[i] = RD();
  }
  for (register unsigned int i(1); i <= n; ++i) {
    if(f[len] < a[i]) {
      f[++len] = a[i];
      g[0][i] = len;
      continue;
    }
    *(lower_bound(f + 1, f + len + 1, a[i])) = a[i];
    g[0][i] = len;
  }
  memset(f, 0, sizeof(f));
  len = 0;
  for (register unsigned int i(n); i >= 1; --i) {
    if(f[len] < a[i]) {
      f[++len] = a[i];
      g[1][i] = len;
      continue;
    }
    *(lower_bound(f + 1, f + len + 1, a[i])) = a[i];
    g[1][i] = len;
  }
  for (register unsigned int i(1); i <= n; ++i) {
//    printf("%u %u %u\n", i, g[0][i], g[1][i]);
    Ans = max(g[0][i] + g[1][i] - 1, Ans);
  }
  printf("%u\n", n - Ans);
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
/*
8
186 186 150 200 160 130 197 220
*/

/*
We had a competition today, I made the First in our school...  I'm happy. 
*/
