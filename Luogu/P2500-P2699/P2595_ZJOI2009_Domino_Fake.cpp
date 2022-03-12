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
unsigned f[16][1000][1000], a[16], Origin[30005][16], m, n, Cnt(0), A, B, C, D, t, N, M;
char s[17];
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
  n = RD();
  m = RD();
  M = (1 << M) - 1;
  N = M >> 1;
  for (register unsigned i(1); i <= n; ++i) {
    cin.getline(s, 16);
    a[i] <<= 1;
    for (register unsigned j(1); j <= m; ++j) {//init
      if (s[j - 1] != '.') {
        a[i] += 1;
      } 
    }
  }
  for (register unsigned i(1); i <= n; ++i) {//line
    printf("%u %u\n", i, a[i]);
  }
  for (register unsigned i(0); i <= N; ++i) {
    for (register unsigned j(0); j + 1 < m; ++j) {
      if(i & (1 << j)) {
        Origin[i][++Origin[i][0]] = i ^ (1 << j);
        printf("%u %u\n", i, Origin[i][Origin[i][0]]);
      }
    }
  }
  for (register unsigned i(1); i <= n; ++i) {
    for (register int j(0); j <= M; ++j) {
      for (register int k(1); k <= N; ++k) {
        
      }
    }
  }
  system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}
