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
unsigned Mod(1000000007);
unsigned Nxt[1000005], f[1000005], Bin[1000005], m, n(0), Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
char a[1000005];
int main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  fread(a + 1, 1, 1000002, stdin);
  Nxt[1] = 0, Bin[0] = 1;
  for (register unsigned i(2), j(1); a[i] >= '0'; ++i) {
    n = i;
    j = i - 1;
    while (j && (a[Nxt[j] + 1] ^ a[i])) {
      j = Nxt[j];
    }
    if (!j) { Nxt[i] = 0; continue; }
    Nxt[i] = Nxt[j] + 1;
    //    printf("%u %u\n", i, Nxt[i]);
  }
  f[n] = 0;
  for (register unsigned i(1); i <= n; ++i) {
    Bin[i] = (Bin[i - 1] << 1);
    if (Bin[i] >= Mod) Bin[i] -= Mod;
  }
  register unsigned i(n);
  while (i) {
    Ans += Bin[i];
    if (Ans >= Mod) Ans -= Mod;
    i = Nxt[i];
  }
  printf("%u\n", Ans);
  system("pause");
  return Wild_Donkey;
}

