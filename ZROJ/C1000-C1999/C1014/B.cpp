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
#include <string>
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
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt[4], Ans(0), Tmp(0);
char a[1000005], Cl[256];
struct Node {
  Node* Pre, * Suf;
  unsigned Num; 
  char Col;
}N[1000005], * Cur(N + 1);
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), scanf("%s", a + 1);
  Cl['R'] = 1, Cl['G'] = 2, Cl['B'] = 3;
  for (unsigned i(1); i <= n; ++i) a[i] = Cl[a[i]], N[i].Num = i, ++Cnt[a[i]];
  for (unsigned i(1); i <= n; ++i) N[i].Col = a[i], N[i].Pre = N + i - 1, N[i].Suf = N + i + 1;
  N[1].Pre = N + n, N[n].Suf = N + 1;
  while (n > 3) {
//    printf("Now %u L %u R %u\n", Cur->Num, Cur->Pre->Num, Cur->Suf->Num);
    if((Cur->Pre->Col ^ Cur->Suf->Col) && (Cur->Pre->Col ^ Cur->Col) && (Cur->Col ^ Cur->Suf->Col) && (Cnt[Cur->Col] > 1))
      --Cnt[Cur->Col], printf("%u %u\n", Cur->Pre->Num, Cur->Suf->Num), --n, Cur->Suf->Pre = Cur->Pre, Cur->Pre->Suf = Cur->Suf;
    Cur = Cur->Suf; 
  }
//  }
  return Wild_Donkey;
}

