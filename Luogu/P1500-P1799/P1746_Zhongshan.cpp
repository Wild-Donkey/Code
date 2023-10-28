#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#define Wild_Donkey 0
#define foreplay for
#define wild while
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') rdsg = -1, rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0', rdch = getchar();
  return rdtp * rdsg;
}
char a[1005][1005];
unsigned f[1005][1005], Que[1000005], *Hd(Que), *Tl(Que);
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cur(0), Ans(0), Tmp(0);
inline void Udt(unsigned x, unsigned y) {
  if (a[x][y] == '0' && f[x][y] > Cur) f[x][y] = Cur, *(Tl++) = (x << 10) + y;
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) scanf("%s", a[i] + 1);
  for (unsigned i(0); i <= n; ++i) a[0][i] = a[n + 1][i] = '1';
  for (unsigned i(0); i <= n; ++i) a[i][0] = a[i][n + 1] = '1';
  A = RD(), B = RD(), C = RD(), D = RD();
  memset(f, 0x3f, sizeof(f));
  *(Tl++) = (A << 10) + B, f[A][B] = 0;
  while (Hd != Tl) {
    unsigned Curx((*Hd) >> 10), Cury((*(Hd++)) & 1023);
    Cur = f[Curx][Cury] + 1;
    // printf("(%u, %u) %u\n", Curx, Cury, Cur);
    Udt(Curx + 1, Cury), Udt(Curx - 1, Cury);
    Udt(Curx, Cury + 1), Udt(Curx, Cury - 1);
  }
  printf("%u\n", f[C][D]);
  //  }
  //  system("pause");
  return Wild_Donkey;
}