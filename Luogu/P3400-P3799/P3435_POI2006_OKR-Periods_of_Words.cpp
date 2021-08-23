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
unsigned Bdr[1000005];
char aP[1000005];
int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  register unsigned n(RD());
  register unsigned long long Ans(0);
  register char *a(aP);
  fread(a + 1, 1, 1000002, stdin);
  while (a[1] < 'a') ++a;
  for (register unsigned i(2), j; i <= n; ++i) {
    j = Bdr[i - 1];
    while (j && (a[j + 1] ^ a[i])) j = Bdr[j];
    Bdr[i] = (j ? (j + 1) : (a[1] == a[i]));
  }
  for (register unsigned i(1), j, *Bdi(Bdr + 1); i <= n; ++i, ++Bdi) if(j = *Bdi) Ans += i - (*Bdi = (Bdr[j] ? Bdr[j] : j));
  printf("%llu\n", Ans);
//  }
  return Wild_Donkey;
}
