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
unsigned long long Ans(0);
unsigned V[105], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
char IO[105];
bitset<105> a[105];
struct Gro {
  bitset<105> Set;
  unsigned long long Val;
  unsigned Last;
  inline const char operator <(const Gro& x) const {return Val < x.Val;}
}Epsi, Cur;
priority_queue<Gro> Q;
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  freopen("A.in", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = 100, m = 1000000;
  printf("%u %u\n", n, m);
  for (unsigned i(1); i <= n; ++i) printf("%u ", rand());
  putchar(0x0A);
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned j(1); j < i; ++j) putchar('1');
    putchar('0');
    for (unsigned j(i + 1); j <= n; ++j) putchar('1');
    putchar(0x0A);
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
2 5
1 2
01
10
100

*/
