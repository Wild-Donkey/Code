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
unsigned a[10005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
struct Set {
  Set *Son[2], *Fa;
  unsigned Val, Size;
  inline void PsUp() {
    Size = 1;
    if(LS) Size += LS->Size;
    if(RS) Size += RS->Size;
  }
  inline void Rotate() {
    if(!Fa) return;
    Set* Cur(Fa);
    char Ty(Cur->Son[1] == this);
    Fa = Cur->Fa, Cur->Son[Ty] = Son[Ty ^ 1], Son[Ty ^ 1] = Cur, ;
  }
}S[4000005], *CntS();
struct Node {
  Set *S;
  Node *LS, *RS;
  unsigned long long Inv, Sum;
}N[200005], *CntN(N);
inline void Build(Node* x, unsigned L, unsigned R) {
  if(L == R) {x->Inv = x->Sum = 0, x->S.insert(RD()); return;}
  unsigned Mid((L + R) >> 1);
  Build(x->LS = ++CntN, L, Mid);
  Build(x->RS = ++CntN, Mid + 1, R);
  for (auto i:x->LS->S) {
    x->Inv += x->RS->S.lower_bound(i) - x->RS->S.begin();
  }
  x->Sum = x->LS->Sum + x->RS->Sum + x->Inv;
}
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) {
    a[i] = RD();
  }
//  }
//  system("pause");
  return Wild_Donkey;
}

