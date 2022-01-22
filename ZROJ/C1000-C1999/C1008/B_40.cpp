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
unsigned a[10005], m, n;
unsigned A, B, C, D, t;
unsigned Sub[3];
unsigned Cnt(0), Ans(0), Tmp(0);
unsigned b[1050], Block(0);
unsigned List[3][1050][1050];
struct Node {
  Node* LS, * RS;
  inline void Qry (unsigned Height) {
//    printf("Q %u %u %u\n", B, LS, RS);
    if(!(~Height)) return;
    if(B & (1 << Height)) {
      if(LS) C |= (1 << Height), LS->Qry(Height - 1);
      else RS->Qry(Height - 1);
    } else {
      if(RS) C |= (1 << Height), RS->Qry(Height - 1);
      else LS->Qry(Height - 1);
    }
  }
}N[5000005], * CntN(N);
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
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  if(n <= 5000) {
    for (unsigned i(1); i <= n; ++i) {
      A = RD(), B = RD();
      switch(A) {
        case (1) :{
          a[++Cnt] = B;
          break;
        }
        case (2) :{
          Sub[0] = Sub[1] = Sub[2] = 0;
          for (unsigned j(1); j <= Cnt; ++j) {
            Sub[0] = max(Sub[0], B ^ a[j]);
            Sub[1] = max(Sub[1], B & a[j]);
            Sub[2] = max(Sub[2], B | a[j]);
          }
          printf("%u %u %u\n", Sub[0], Sub[1], Sub[2]);
          break;
        }
        case (3) :{
          Sub[0] = 0;
          for (unsigned j(1); j <= Cnt; ++j)
            Sub[0] = max(Sub[0], B ^ a[j]);
          printf("%u\n", Sub[0]);
          break;
        } 
      }
    }
    return 0;
  }
//  for (unsigned i(1); i <= n; ++i) {
//    A = RD(), B = RD();
//    switch(A) {
//      case (1) :{
//        if (B < 1024) b[B] = 1;
//        Insert(N, 19);
//        break;
//      }
//      case (2) :{
//        Sub[0] = Sub[1] = Sub[2] = 0;
//        for (unsigned i(0); i < 1024; ++i) if(b[i]){
//          Sub[0] = max(Sub[0], B ^ i);
//          Sub[1] = max(Sub[1], B & i);
//          Sub[2] = max(Sub[2], B | i);
//        }
//        printf("%u %u %u\n", Sub[0], Sub[1], Sub[2]);
//        break;
//      }
//      case (3) :{
//        C = 0;
//        N->Qry(19);
//        printf("%u\n", C);
//        break;
//      }
//    }
//  }
  Block = sqrt(n) + 1;
  for (unsigned i(1); i <= n; ++i) {
    A = RD(), B = RD();
    switch(A) {
      case (1) :{
        unsigned Bel(B / Block);
        for (unsigned j(0); j < Block; ++j) {
          
        }
        List[0]
        Insert(N, 19);
        break;
      }
      case (2) :{
        Sub[0] = Sub[1] = Sub[2] = 0;
        for (unsigned i(0); i < 1024; ++i) if(b[i]){
          Sub[0] = max(Sub[0], B ^ i);
          Sub[1] = max(Sub[1], B & i);
          Sub[2] = max(Sub[2], B | i);
        }
        printf("%u %u %u\n", Sub[0], Sub[1], Sub[2]);
        break;
      }
      case (3) :{
        for (unsigned i(n / Block); ~i; --i) {
          if()
        }
        break;
      }
    }
  }
//  }
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
