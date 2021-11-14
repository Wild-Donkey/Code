#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned m, n, Now[5], Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
char a[105], Flg(0);
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  fread(a + 1, 1, 35, stdin);
  n = strlen(a + 1);
  for (register unsigned i(1); i <= n; ++i) {
    if (a[i] <= 32) continue;
    if (((a[i - 1] >= '0') && (a[i - 1] <= '9')) && ((a[i] < '0') || (a[i] > '9'))) ++Cnt;
    if ((a[i] == '0') && ((a[i - 1] < '0') || (a[i - 1] > '9'))) Flg = 1;
    if (((a[i] < '0') || (a[i] > '9')) && (a[i] ^ '.')) Flg = 1;
    else if (a[i] ^ '.') Now[Cnt] *= 10, Now[Cnt] += a[i] - '0';
    if ((a[i] == '.') && (!(((a[i - 1] >= '0') && (a[i - 1] <= '9')) && ((a[i + 1] >= '0') && (a[i + 1] <= '9'))))) Flg = 1;
  }
  if (Now[0] > 255) Now[0] = 255, Flg = 1;
  if (Now[1] > 255) Now[1] = 255, Flg = 1;
  if (Now[2] > 255) Now[2] = 255, Flg = 1;
  if (Now[3] > 255) Now[3] = 255, Flg = 1;
  printf(Flg ? "NO\n" : "YES\n");
  if (Flg) printf("%u.%u.%u.%u\n", Now[0], Now[1], Now[2], Now[3]);
  // system("pause");
  return Wild_Donkey;
}
/*
00,1234,999>255
192.168.25.226

*/