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
unsigned f[200005][20], b[200005], Bin[205], Log[200005], m, n, Cnt[30], BinL, BinR, BinMid, A, B, C, D, t, Ans(0), Tmp(0), NowL, NowR, LastL, LastR;
char ap[200005], *a(ap);
struct Node {
  Node *LS, *RS;
  unsigned Val; 
}N[500005], *CntN(N);
void Build(Node *x, unsigned L, unsigned R) {
//  printf("Build %u [%u, %u]\n", x - N, L, R);
  if(L == R) {
    x->Val = b[L];
    return; 
  }
  register unsigned Mid((L + R) >> 1);
  Build(x->LS = ++CntN, L, Mid);
  Build(x->RS = ++CntN, Mid + 1, R);
  x->Val = (x->LS->Val) | (x->RS->Val);
  return;
}
inline unsigned Count (unsigned x) {
  register unsigned Ctmp(0);
  for (register char i(0); i < 26; ++i) {
    Ctmp += (x & (1 << i)) ? 1 : 0;
  }
  return Ctmp;
}
void Qry(Node *x, unsigned L, unsigned R) {
  if((A <= L) && (R <= B)) {
    C |= x->Val;
    return;
  }
  register unsigned Mid((L + R) >> 1);
  if(B > Mid) {
    Qry(x->RS, Mid + 1, R);
  }
  if(A <= Mid) {
    Qry(x->LS, L, Mid);
  }
  return;
}
char Judge1 (unsigned x) {
//  printf("Judge1 %u\n", x);
  A = x, B = D, C = 0, Qry(N, 1, n);
  return Count(C) <= m;
}
char Judge2 (unsigned x) {
//  printf("Judge2 %u\n", x);
  A = x, B = D, C = 0, Qry(N, 1, n);
  return Count(C) >= m;
}
inline unsigned Find(unsigned x, unsigned y) {
  register unsigned Tmp(Log[y - x + 1]);
  return min(f[x][Tmp], f[y - Bin[Tmp] + 1][Tmp]);
}
int main() {
//  freopen("C.in", "r", stdin);
//  freopen("C.out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  m = RD();
  fread(ap + 1, 1, 200002, stdin);
  while (a[1] < 'a') ++a;
  while (a[n + 1] >= 'a') ++n;
  for (register unsigned i(1); i <= n; ++i) {
    b[i] = 1 << (a[i] - 'a');
  }
  Build(N, 1, n);
  for (register unsigned i(1), j(0); i <= n; i <<= 1, ++j) {
    Bin[j] = i, Log[i] = j; 
  }
  for (register unsigned i(1); i <= n; ++i) {
    Log[i] = max(Log[i], Log[i - 1]);
  }
  NowL = NowR = 0;
  for (register unsigned i(1); i <= n; ++i) {
    D = i, BinL = 1, BinR = i;
    while (BinL ^ BinR) {
      BinMid = (BinL + BinR) >> 1;
      if(Judge1(BinMid)) {
        BinR = BinMid;
      } else {
        BinL = BinMid + 1;
      }
    }
    NowL = BinL;
    BinL = 0, BinR = i;
    while (BinL ^ BinR) {
      BinMid = (BinL + BinR + 1) >> 1;
      if(Judge2(BinMid)) {
        BinL = BinMid;
      } else {
        BinR = BinMid - 1;
      }
    }
    NowR = BinL;
//    printf("Done [%u, %u]\n", NowL, NowR);
    f[0][0] = 0;
    if(NowR <= 0) {
      f[i][0] = 0x3f3f3f3f;
    } else {
      if(!NowL) NowL = 1;
      f[i][0] = Find(NowL - 1, NowR - 1) + 1;
    }
    for (register unsigned j(1); j <= Log[i]; ++j) {
      f[i - Bin[j] + 1][j] = min(f[i - Bin[j - 1] + 1][j - 1], f[i - Bin[j] + 1][j - 1]);
    }
    if(f[i][0] >= 0x3f3f3f3f) {
      printf("-1\n");
    } else {
      printf("%u\n", f[i][0]);
    }
  }
//  for (register unsigned i(1); i <= n; ++i) {
//    printf("\n%u ", i);
//    putchar(a[i]);
//  }
//  }
  return Wild_Donkey;
}
/*
dkffkfkdfdkfdfk
-1 1 -1

1
abaaa

1
babaabcb

2
cbbaaacbaa
*/  
