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
unsigned a[100005], Odd[2], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char Flg(0);
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= m; ++i) {
    a[i] = RD();
    if (a[i] & 1) {
      if (Cnt == 2) {
        Flg = 1;
        break;
      }
      Odd[Cnt++] = i;
    }
  }
  if (Flg) {
    printf("Impossible\n");
    return 0;
  }
  if (m == 1) {
    if (a[1] == 1)
      printf("1\n1\n1\n");
    else
      printf("%u\n2\n%u 1\n", a[1], a[1] - 1);
    return 0;
  }
  if (Cnt >= 1) swap(a[Odd[0]], a[1]);
  if (Cnt == 2) swap(a[Odd[1]], a[m]);
  for (unsigned i(1); i <= m; ++i) printf("%u ", a[i]);
  ++a[1], m -= (!(--a[m])), printf("\n%u\n", m);
  for (unsigned i(1); i <= m; ++i) printf("%u ", a[i]);
  putchar(0x0A);
  return Wild_Donkey;
}