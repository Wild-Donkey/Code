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
unsigned long long Mod(1004535809);
unsigned long long Ans(0);
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0);
inline void Mn(unsigned long long& x) { x -= (x >= Mod) ? (Mod) : 0; }
struct Matrix {
  unsigned long long V[2][2];
  inline Matrix operator * (const Matrix& x) {
    Matrix Rt;
    Rt.V[0][0] = (V[0][0] * x.V[0][0] + V[0][1] * x.V[1][0]) % Mod;
    Rt.V[0][1] = (V[0][0] * x.V[0][1] + V[0][1] * x.V[1][1]) % Mod;
    Rt.V[1][0] = (V[1][0] * x.V[0][0] + V[1][1] * x.V[1][0]) % Mod;
    Rt.V[1][1] = (V[1][0] * x.V[0][1] + V[1][1] * x.V[1][1]) % Mod;
    return Rt;
  }
  inline Matrix operator + (const Matrix& x) {
    Matrix Rt(x);
    Rt.V[0][0] += V[0][0], Mn(Rt.V[0][0]);
    Rt.V[0][1] += V[0][1], Mn(Rt.V[0][1]);
    Rt.V[1][0] += V[1][0], Mn(Rt.V[1][0]);
    Rt.V[1][1] += V[1][1], Mn(Rt.V[1][1]);
    return Rt;
  }
  inline Matrix Pow(unsigned x) {
    Matrix Tmp(*this), Rt{ {1, 0, 0, 1} };
    // printf("Rt %llu %llu %llu %llu\n", Rt.V[0][0], Rt.V[0][1], Rt.V[1][0], Rt.V[1][1]);
    while (x) { if (x & 1) Rt = Rt * Tmp; x >>= 1, Tmp = Tmp * Tmp; }
    return Rt;
    // while ()
  }
}Pri{ {1, 0, 0, 1} }, Meta{ {1, 1, 1, 0} }, Mul;
struct Node {
  Matrix Val, Tag;
  Node* LS, * RS;
  inline void PsDw() {
    if (Tag.V[0][1]) {
      LS->Val = LS->Val * Tag, LS->Tag = LS->Tag * Tag;
      RS->Val = RS->Val * Tag, RS->Tag = RS->Tag * Tag;
      Tag = Pri;
    }
  }
  inline void Edit(unsigned L, unsigned R) {
    if ((A <= L) && (R <= B)) { Tag = Tag * Mul, Val = Val * Mul; return; }
    unsigned Mid((L + R) >> 1);
    PsDw();
    if (A <= Mid) LS->Edit(L, Mid);
    if (Mid < B) RS->Edit(Mid + 1, R);
    Val = LS->Val + RS->Val;
  }
  inline void Qry(unsigned L, unsigned R) {
    if ((A <= L) && (R <= B)) { Ans += Val.V[0][0]; return; }
    unsigned Mid((L + R) >> 1);
    PsDw();
    if (A <= Mid) LS->Qry(L, Mid);
    if (Mid < B) RS->Qry(Mid + 1, R);
  }
}N[200005], * CntN(N);
inline void Build(Node* x, unsigned L, unsigned R) {
  x->Tag = Pri;
  if (L == R) { x->Val = x->Tag = Meta.Pow(RD() - 1); return; }
  unsigned Mid((L + R) >> 1);
  Build(x->LS = ++CntN, L, Mid);
  Build(x->RS = ++CntN, Mid + 1, R);
  x->Val = x->LS->Val + x->RS->Val;
}
//  inline void Clr() {}
signed main() {
  // freopen("B.in", "r", stdin);
  // freopen("B.out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), Build(N, 1, n);
  for (unsigned i(1); i <= m; ++i) {
    C = RD(), A = RD(), B = RD();
    if (C & 1) Mul = Meta.Pow(RD()), N->Edit(1, n);
    else Ans = 0, N->Qry(1, n), printf("%u\n", (unsigned)(Ans % Mod));
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}