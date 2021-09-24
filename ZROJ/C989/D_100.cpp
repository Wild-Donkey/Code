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
const unsigned long long Mod(998244353);
unsigned ST[2][18][200005], Log[200005], Bin[20];
unsigned Pos[200005], f[200005], Sum[200005];
unsigned m, n, Cnt(0), Ans(0);
unsigned A, B, C, D, t;
char flg(0), Flg(0);
struct Line {
  unsigned LB, RB, Ver;
  char Type;
  inline const char operator<(const Line& x) {return this->Ver < x.Ver;}
}Li[400005];
struct Node {
  Node* LS, * RS;
  unsigned Val, Times;
}N[400005], * CntN(N);
inline void Udt(Node* x, unsigned L, unsigned R, unsigned Mid) {
  if(x->LS->Times) {x->Val = Mod + Sum[Mid] - Sum[L - 1]; if(x->Val >= Mod) x->Val -= Mod;}
  else x->Val = x->LS->Val;
  if(x->RS->Times) x->Val += Mod + Sum[R] - Sum[Mid];
  else x->Val += x->RS->Val; 
  while(x->Val >= Mod) x->Val -= Mod;
}
void Build(Node* x, unsigned L, unsigned R) {
  if(L == R) return;
  unsigned Mid((L + R) >> 1);
  Build(x->LS = ++CntN, L, Mid), Build(x->RS = ++CntN, Mid + 1, R);
}
void Add(Node* x, unsigned L, unsigned R) {
  if((A <= L) && (R <= B)) {++(x->Times); return;}
  unsigned Mid((L + R) >> 1);
  if(A <= Mid) Add(x->LS, L, Mid);
  if(B > Mid) Add(x->RS, Mid + 1, R);
  Udt(x, L, R, Mid);
}
void Dec(Node* x, unsigned L, unsigned R) {
  if((A <= L) && (R <= B)) {--(x->Times); return;}
  unsigned Mid((L + R) >> 1);
  if(A <= Mid) Dec(x->LS, L, Mid);
  if(B > Mid) Dec(x->RS, Mid + 1, R);
  Udt(x, L, R, Mid);
}
void Qry(Node* x, unsigned L, unsigned R, int Lay) {
  if(R <= A) {
    Ans += (Lay + x->Times) ? (Mod + Sum[R] - Sum[L - 1]) : x->Val; 
    while(Ans >= Mod) Ans -= Mod; return;
  }
  unsigned Mid((L + R) >> 1);
  Qry(x->LS, L, Mid, Lay + x->Times);
  if(A > Mid) Qry(x->RS, Mid + 1, R, Lay + x->Times);
}
unsigned FindMx(unsigned L, unsigned R) {
  unsigned LeLo(Log[R - L + 1]);
  return max(ST[0][LeLo][L], ST[0][LeLo][R - Bin[LeLo] + 1]);
}
unsigned FindMn(unsigned L, unsigned R) {
  unsigned LeLo(Log[R - L + 1]);
  return min(ST[1][LeLo][L], ST[1][LeLo][R - Bin[LeLo] + 1]);
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = n >> 1; 
  for (unsigned i(1), j(0); i <= n; i <<= 1, ++j) Log[i] = j, Bin[j] = i;
  for (unsigned i(2); i <= n; ++i) Log[i] = max(Log[i], Log[i - 1]);
  for (unsigned i(1); i <= n; ++i) Pos[ST[1][0][i] = ST[0][0][i] = RD()] = i;
  for (unsigned i(1), j(0); i <= m; i <<= 1, ++j) 
    for (unsigned k(1); k <= n; ++k) ST[0][j + 1][k] = max(ST[0][j][k], ST[0][j][k + i]);
  for (unsigned i(1), j(0); i <= m; i <<= 1, ++j) 
    for (unsigned k(1); k <= n; ++k) ST[1][j + 1][k] = min(ST[1][j][k], ST[1][j][k + i]);
  Build(N, 1, n);
  for (unsigned i(1), TL, TR; i <= n; ++i) {
    unsigned BinL(1), BinR(Pos[i]), BinMid;
//    printf("At %u\n", i);
    while(BinL ^ BinR) {
//      printf("[%u, %u]\n", BinL, BinR);
      BinMid = (BinL + BinR) >> 1;
      if(FindMx(BinMid, Pos[i]) > i) BinL = BinMid + 1; 
      else BinR = BinMid;
    }
    TL = BinL, BinL = Pos[i], BinR = n;
    while(BinL ^ BinR) {
//      printf("[%u, %u]'\n", BinL, BinR);
      BinMid = (BinL + BinR + 1) >> 1;
      if(FindMx(Pos[i], BinMid) > i) BinR = BinMid - 1; 
      else BinL = BinMid;
    }
    if(BinL == n) {Li[(i << 1) - 1].Type = Li[i << 1].Type = 2; continue;}
    Li[i << 1].Type = 1, TR = BinL, BinL = TR + 1, BinR = n;
    while(BinL ^ BinR) {
//      printf("[%u, %u]''\n", BinL, BinR);
      BinMid = (BinL + BinR + 1) >> 1;
      if(FindMn(TR + 1, BinMid) > i) BinL = BinMid; 
      else BinR = BinMid - 1;
    }
    Li[(i << 1) - 1].LB = Li[i << 1].LB = TL;
    Li[(i << 1) - 1].RB = Li[i << 1].RB = TR;
    Li[(i << 1) - 1].Ver = TR + 1, Li[i << 1].Ver = BinL + 1;
  }
  sort(Li + 1, Li + ((n << 1) ^ 1));
//  for (unsigned i(1); i <= n; ++i) {
//    for (unsigned j(1); j <= n; ++j) {
//      printf("%u ", InAva[i][j]);
//    }
//    putchar('\n');
//  }
  f[0] = 1, Li[(n << 1) ^ 1].Ver = n + 1;
//  for (unsigned i(1); i <= (n << 1); ++i) {
//    printf("%u T%u [%u, %u] At%u\n", i, Li[i].Type, Li[i].LB, Li[i].RB, Li[i].Ver); 
//  }
  for (unsigned i(1), j(1); i <= n; ++i) {
    while(Li[j].Ver <= i) {
//      printf("at%u [%u, %u] T%u\n", Li[j].Ver, Li[j].LB, Li[j].RB, Li[j].Type);
      if(Li[j].Type == 2) {++j; continue;}
      A = Li[j].LB, B = Li[j].RB, (Li[j].Type ? Dec(N, 1, n) : Add(N, 1, n)), ++j;
    }
    Sum[i] = Sum[i - 1] + f[i - 1]; if(Sum[i] >= Mod) Sum[i] -= Mod;
    Ans = 0, A = i, Qry(N, 1, n, 0), f[i] = Mod + Sum[i] - Ans; if(f[i] >= Mod) f[i] -= Mod;
//    printf("%u Sum %u Ans %u\n", i, Sum[i], Ans);
  }
//  for (unsigned i(1); i <= n; ++i) printf("f[%u] %u\n", i, f[i]);
  printf("%u\n", f[n]);
  return Wild_Donkey;
}
/*
10
2 5 3 1 4 7 10 8 9 6
*/
