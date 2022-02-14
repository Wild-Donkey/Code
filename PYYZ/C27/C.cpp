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
unsigned long long Mod(1000000007);
unsigned m, n, K, KK;
unsigned A, B, C, D, t;
unsigned long long Inve(unsigned long long x) {
  unsigned Ti(Mod - 2);
  unsigned long long Rt(1);
  while (Ti) { if (Ti & 1) Rt = Rt * x % Mod; x = x * x % Mod, Ti >>= 1; }
  return Rt;
}
struct Matrix {
  unsigned Val[5][5];
  inline void Init() { for (unsigned i(0); i < K; ++i) for (unsigned j(0); j < K; ++j) Val[i][j] = RD(); }
  inline void Prt() {
    printf("Matrix:\n");
    for (unsigned i(0); i < K; ++i) {
      printf("%u:", i);
      for (unsigned j(0); j < K; ++j) printf("%llu ", (unsigned long long)Val[i][j]); putchar(0x0A);
    }
  }
  inline void Tr() { for (unsigned i(1); i < K; ++i) for (unsigned j(0); j < i; ++j) swap(Val[i][j], Val[j][i]); }
  inline void Inv() {
    unsigned long long Tmp[K][KK];
    memset(Tmp, 0, sizeof(Tmp));
    for (unsigned i(0); i < K; ++i) for (unsigned j(0); j < K; ++j) Tmp[i][j] = Val[i][j];
    for (unsigned i(0); i < K; ++i) Tmp[i][i + K] = 1;
    for (unsigned i(0); i < K; ++i) {
      unsigned No(i);
      while (!Tmp[No][i]) ++No;
      if (No ^ i) for (unsigned j(i); j < KK; ++j) swap(Tmp[No][j], Tmp[i][j]);
      unsigned long long Invers(Inve(Tmp[i][i]));
      for (unsigned j(i); j < KK; ++j) Tmp[i][j] = Tmp[i][j] * Invers % Mod;
      for (unsigned j(i + 1); j < K; ++j) if (Tmp[j][i]) {
        unsigned long long Mul(Mod - Tmp[j][i]);
        for (unsigned k(i); k < KK; ++k) Tmp[j][k] = (Tmp[j][k] + Tmp[i][k] * Mul) % Mod;
      }
    }
    for (unsigned i(K - 1); ~i; --i) if (Tmp[i][i]) {
      for (unsigned j(0); j < i; ++j) if (Tmp[j][i]) {
        unsigned long long Mul(Mod - Tmp[j][i]);
        for (unsigned k(i); k < KK; ++k) Tmp[j][k] = (Tmp[j][k] + Tmp[i][k] * Mul) % Mod;
      }
    }
    // for (unsigned i(0); i < K; ++i) { for (unsigned j(0); j < KK; ++j) printf("%u ", (unsigned)Tmp[i][j]); putchar(0x0A); }
    for (unsigned i(0); i < K; ++i) for (unsigned j(0); j < K; ++j) Val[i][j] = (unsigned)Tmp[i][j + K];
  }
  inline unsigned long long Sum() {
    unsigned long long Rt(0);
    for (unsigned i(0); i < K; ++i) for (unsigned j(0); j < K; ++j) Rt += Val[i][j];
    return Rt % Mod;
  }
  inline Matrix operator* (const Matrix& x) {
    Matrix Rt;
    memset(&Rt, 0, sizeof(Matrix));
    for (unsigned i(0); i < K; ++i) for (unsigned j(0); j < K; ++j) for (unsigned k(0); k < K; ++k)
      Rt.Val[i][j] = (Rt.Val[i][j] + (unsigned long long)Val[i][k] * x.Val[k][j]) % Mod;
    return Rt;
  }
  inline Matrix Pow(unsigned x) {
    Matrix Tmp(*this), Rt;
    memset(&Rt, 0, sizeof(Matrix));
    for (unsigned i(0); i < K; ++i) Rt.Val[i][i] = 1;
    // printf("Tmp\n"), Tmp.Prt();
    // printf("Rt\n"), Rt.Prt();
    while (x) { if (x & 1) Rt = Rt * Tmp; Tmp = Tmp * Tmp, x >>= 1; }
    return Rt;
  }
}Ans;
struct Node {
  Matrix M, RM, Tag;
  Node* LS, * RS;
  char Ro, In, Exi;
  inline void PsDw(const unsigned& L, const unsigned& R, const unsigned& Mid) {
    if (Exi) {
      LS->In = LS->Ro = RS->In = RS->Ro = 0;
      LS->Exi = RS->Exi = 1;
      LS->Tag = RS->Tag = Tag;
      LS->M = LS->RM = Tag.Pow(Mid - L + 1);
      RS->M = RS->RM = Tag.Pow(R - Mid);
    }
    if (Ro ^ In) swap(RS->M, RS->RM), swap(LS->M, LS->RM);
    if (Ro) {
      LS->Ro ^= 1, RS->Ro ^= 1;
      LS->M.Tr(), LS->RM.Tr();
      RS->M.Tr(), RS->RM.Tr();
    }
    if (In) {
      LS->In ^= 1, LS->M.Inv(), LS->RM.Inv();
      RS->In ^= 1, RS->M.Inv(), RS->RM.Inv();
    }
    Exi = Ro = In = 0;
  }
  inline void Tran(unsigned L, unsigned R) {
    if ((A <= L) && (R <= B)) { Ro ^= 1, swap(M, RM), M.Tr(), RM.Tr(); return; }
    unsigned Mid((L + R) >> 1);
    PsDw(L, R, Mid);
    if (A <= Mid) LS->Tran(L, Mid);
    if (Mid < B) RS->Tran(Mid + 1, R);
    M = LS->M * RS->M, RM = RS->RM * LS->RM;
  }
  inline void Inver(unsigned L, unsigned R) {
    if ((A <= L) && (R <= B)) { In ^= 1, swap(M, RM), M.Inv(), RM.Inv(); return; }
    unsigned Mid((L + R) >> 1);
    PsDw(L, R, Mid);
    if (A <= Mid) LS->Inver(L, Mid);
    if (Mid < B) RS->Inver(Mid + 1, R);
    M = LS->M * RS->M, RM = RS->RM * LS->RM;
  }
  inline void Defi(unsigned L, unsigned R) {
    if ((A <= L) && (R <= B)) { In = Ro = 0, Exi = 1, Tag = Ans, RM = M = Tag.Pow(R - L + 1); return; }
    unsigned Mid((L + R) >> 1);
    PsDw(L, R, Mid);
    if (A <= Mid) LS->Defi(L, Mid);
    if (Mid < B) RS->Defi(Mid + 1, R);
    M = LS->M * RS->M, RM = RS->RM * LS->RM;
  }
  inline void Find(unsigned L, unsigned R) {
    if ((A <= L) && (R <= B)) { Ans = Ans * M; return; }
    unsigned Mid((L + R) >> 1);
    PsDw(L, R, Mid);
    if (A <= Mid) LS->Find(L, Mid);
    if (Mid < B) RS->Find(Mid + 1, R);
  }
}N[100005], * CntN(N);
inline void Build(Node* x, unsigned L, unsigned R) {
  x->Ro = x->In = x->Exi = 0;
  if (L == R) { x->M.Init(), x->RM = x->M; return; }
  unsigned Mid((L + R) >> 1);
  Build(x->LS = ++CntN, L, Mid);
  Build(x->RS = ++CntN, Mid + 1, R);
  x->M = x->LS->M * x->RS->M;
  x->RM = x->RS->RM * x->LS->RM;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  // KK = ((K = 3) << 1);
  // Ans.Init(), Ans.Inv(), Ans.Prt();
  n = RD(), m = RD(), KK = ((K = RD()) << 1), Build(N, 1, n);
  for (unsigned i(1); i <= m; ++i) {
    // if (i == 4) C = 1, A = 4122, B = 9719;
    C = RD(), A = RD(), B = RD();
    // printf("Op %u [%u, %u]\n", C, A, B);
    switch (C) {
    case 1: {
      memset(&Ans, 0, sizeof(Matrix));
      for (unsigned i(0); i < K; ++i) Ans.Val[i][i] = 1;
      // N->Tag.Prt();
      N->Find(1, n), printf("%llu\n", Ans.Sum());
      // Ans.Prt();
      break;
    }
    case 2: {N->Inver(1, n);break;}
    case 3: {N->Tran(1, n);break;}
    case 4: {Ans.Init(), N->Defi(1, n);break;}
    }
  }
  //  }
  // system("pause");
  return Wild_Donkey;
}
/*
3 3 3
401 12149 18095
1640 642 20839
8441 5266 19425
401 12149 18095
1640 642 20839
8441 5266 19425
401 12149 18095
1640 642 20839
8441 5266 19425
4 1 2
8441 5266 19425
401 12149 18095
1640 642 20839
2 2 3
1 1 3

517592088

801143874
801143874
*/