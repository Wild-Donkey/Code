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
#define lbt(x) ((x)&(((~(x))+1)))
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
unsigned Sub[2];
char Ava[1100000];
struct Node {
  Node* LS, * RS;
  inline void Qry (unsigned Height) {
    if(!(~Height)) return;
    if(B & (1 << Height)) {
      if(LS) C |= (1 << Height), LS->Qry(Height - 1);
      else RS->Qry(Height - 1);
    } else {
      if(RS) C |= (1 << Height), RS->Qry(Height - 1);
      else LS->Qry(Height - 1);
    }
  }
}N[20000005], * CntN(N);
inline void Insert(Node* x, unsigned Height) {
  if(!(~Height)) return;
  if(B & (1 << Height)) {
    if(!(x->RS)) x->RS = ++CntN;
    Insert(x->RS, Height - 1);
  }
  else {
    if(!(x->LS)) x->LS = ++CntN;
    Insert(x->LS, Height - 1);
  }
  return;
}
inline void Add(unsigned x) {
//  printf("Add %u\n", x);
  if(!x) return;
  Ava[x] = 1;
  for (unsigned i(x); i; i -= lbt(i))
    if(!Ava[x ^ lbt(i)]) Add(x ^ lbt(i));
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) {
    A = RD(), B = RD();
    switch(A) {
      case (1) :{
        Insert(N, 19);
        Add(B);
        break;
      }
      case (2) :{
        C = 0;
        N->Qry(19);
        Sub[0] = 0, Sub[1] = B;
        for (unsigned j(19), k(0), Bin(1 << 19); ~j; --j, Bin >>= 1)
          if(B & Bin) if(Ava[k + Bin]) Sub[0] |= Bin, k += Bin;
        for (unsigned j(19), k(0), Bin(1 << 19); ~j; --j, Bin >>= 1)
          if(!(B & Bin)) if(Ava[k + Bin]) Sub[1] |= Bin, k += Bin;
        printf("%u %u %u\n", C, Sub[0], Sub[1]);
        break;
      }
      case (3) :{
        C = 0;
        N->Qry(19);
        printf("%u\n", C);
        break;
      }
    }
  }
  return Wild_Donkey;
}
/*
10
1 194570
1 202332
1 802413
3 234800
1 1011194
3 1021030
3 715144
3 720841
1 7684
3 85165
*/
