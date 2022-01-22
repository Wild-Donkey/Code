#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#define Wild_Donkey 0
#define INFi 0x3f3f3f3f3f3f3f3f
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
unsigned a[100005], Ans[100005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
char f[100005][3][3], Flg(0);
inline void Clr() {
  memset(f, 0, (n + 3) * 9);
  n = RD() - 2, Flg = 0;
}
inline unsigned Calc(unsigned x, unsigned y, unsigned z) {
  if(x > 0x3f3f3f3f) return 0x3f3f3f3f;
  if(((a[x] <= a[y]) && (a[x] >= a[z])) || ((a[x] >= a[y]) && (a[x] <= a[z]))) return a[x];
  if(((a[y] <= a[x]) && (a[y] >= a[z])) || ((a[y] >= a[x]) && (a[y] <= a[z]))) return a[y];
  return a[z];
}
inline void Back(unsigned Pos, unsigned x, unsigned y) {
  if(!Pos) return;
  Ans[Pos - 1] = a[Pos + f[Pos][x][y] - 3];
  Back(Pos - 1, f[Pos][x][y] - 1, x);
}
signed main() {
//  freopen("A.in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    Clr();
    for (unsigned i(1); i <= n; ++i) a[i] = RD();
    for (unsigned char i(1); i < 3; ++i) for (unsigned char j(0); j < 3; ++j) f[0][i][j] = 1;
    a[0] = a[1], a[n + 1] = a[n];
    for (unsigned i(1); i <= n; ++i) for (unsigned char j(0); j < 3; ++j)
      for (unsigned char k(0); k < 3; ++k) for (unsigned char l(0); l < 3; ++l)
        if((Calc(i + l - 2, i + j - 1, i + k) == a[i]) && f[i - 1][l][j]) {f[i][j][k] = l + 1;break;}
//    for (unsigned i(1); i <= n; ++i) for (unsigned char j(0); j < 9; ++j)
//      printf("f %u %u %u = %u\n", i, j / 3, j % 3, f[i][j / 3][j % 3]);
    for (unsigned char i(0); i < 6; ++i) if(f[n][i % 3][i / 3])
      {Back(n, i % 3, i / 3), Ans[n + 1] = a[n + (i / 3)], Ans[n] = a[n + (i % 3) - 1], ++n, Flg = 1; break;}
    if(!Flg) printf("-1");
    else for (unsigned i(0); i <= n; ++i) printf("%u ", Ans[i]);
    putchar(0x0A);
  }
  //  system("pause");
  return Wild_Donkey;
}
/*
4
5
1 2 3
6
1 2 3 4
6
1 2 4 3
6
1 3 4 2
*/
