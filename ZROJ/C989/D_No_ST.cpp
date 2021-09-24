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
  for (unsigned i(1), TL, TR, RR; i <= n; ++i) {
    TL = TR = Pos[i];
    for (unsigned j(Log[n - TR + 1]); ~j; --j)
      if((TR + Bin[j] <= n + 1) && (ST[0][j][TR] <= i)) TR += Bin[j];
    RR = TR;
    if(RR > n) {Li[i << 1].Type = Li[(i << 1) - 1].Type = 2;continue;}
    for (unsigned j(Log[TL]); ~j; --j)
      if((Bin[j] <= TL) && (ST[0][j][TL - Bin[j] + 1] <= i)) TL -= Bin[j];
    ++TL, Li[i << 1].Type = 1;
    for (unsigned j(Log[n - RR + 1]); ~j; --j)
      if((RR + Bin[j] <= n + 1) && (ST[1][j][RR] > i)) RR += Bin[j];
    Li[(i << 1) - 1].LB = Li[i << 1].LB = TL;
    Li[(i << 1) - 1].RB = Li[i << 1].RB = TR - 1;
    Li[(i << 1) - 1].Ver = TR, Li[i << 1].Ver = RR;
  }
  sort(Li + 1, Li + ((n << 1) ^ 1));
  f[0] = 1, Li[(n << 1) ^ 1].Ver = n + 1;
  for (unsigned i(1), j(1); i <= n; ++i) {
    while(Li[j].Ver <= i) {
      if(Li[j].Type == 2) {++j; continue;}
      A = Li[j].LB, B = Li[j].RB, (Li[j].Type ? Dec(N, 1, n) : Add(N, 1, n)), ++j;
    }
    Sum[i] = Sum[i - 1] + f[i - 1];
    if(Sum[i] >= Mod) Sum[i] -= Mod;
    Ans = 0, A = i, Qry(N, 1, n, 0), f[i] = Mod + Sum[i] - Ans;
    if(f[i] >= Mod) f[i] -= Mod;
  }
  printf("%u\n", f[n]);
  return Wild_Donkey;
}
/*
10
2 5 3 1 4 7 10 8 9 6
*/
