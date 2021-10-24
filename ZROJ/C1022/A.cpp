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
const unsigned long long Mod(998244353), Inv2(499122177);
unsigned long long Ans[100005], A, B, C, D;
unsigned long long Sumx(0), Sumy(0), Sumqx(0), Sumqy(0);
unsigned long long Qx, Qy, Qxy, QN;
unsigned long long Tx, Ty, Txy, TN;
unsigned long long Nx, Ny;
unsigned b[100005], c[100005], m, n;
unsigned Cnt(0),Tmp(0);
struct Pnt {
  unsigned Ve, Ho, RV, RH, Num;
  inline const char operator< (const Pnt& x) const {return Ve < x.Ve;}
}a[100005];
struct Node {
  Node* LS, * RS;
  unsigned Nu, Ve, Ho, VeHo; 
  inline void Udt() {
    Nu = LS->Nu + RS->Nu; 
    Ve = LS->Ve + RS->Ve;
    Ho = LS->Ho + RS->Ho;
    VeHo = LS->VeHo + RS->VeHo;
    if(Ve >= Mod) Ve -= Mod;
    if(Ho >= Mod) Ho -= Mod;
    if(VeHo >= Mod) VeHo -= Mod; 
  }
  inline void Qry(unsigned L, unsigned R) {
    if ((A <= L) && (R <= B)) {
      Qx += Ve, Qy += Ho, Qxy += VeHo, QN += Nu;
      if(Qx >= Mod) Qx -= Mod;
      if(Qy >= Mod) Qy -= Mod;
      if(Qxy >= Mod) Qxy -= Mod;
      return;
    }
    unsigned Mid((L + R) >> 1);
    if(A <= Mid) LS->Qry(L, Mid);
    if(B > Mid) RS->Qry(Mid + 1, R);
    return;
  }
}N[40000005], * Root[100005], * CntN(N);
inline void Build(Node* x, unsigned L, unsigned R) {
  x->Nu = x->Ve = x->Ho = x->VeHo = 0;
  if(L == R) return;
  unsigned Mid((L + R) >> 1);
  Build(x->LS = ++CntN, L, Mid);
  Build(x->RS = ++CntN, Mid + 1, R);
}
inline void Ins(Node* x, Node* y, unsigned L, unsigned R) {
  if(x) *y = *x;
  if (L == R) {
    ++(y->Nu), y->Ve += B, y->Ho += C, y->VeHo = (y->VeHo + B * C) % Mod;
    if(y->Ve >= Mod) y->Ve -= Mod;
    if(y->Ho >= Mod) y->Ho -= Mod;
    return;
  }
  unsigned Mid((L + R) >> 1);
  if(A <= Mid)  Ins(x->LS, y->LS = ++CntN, L, Mid);
  else Ins(x->RS, y->RS = ++CntN, Mid + 1, R);
  y->Udt();
  return;
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) a[i].Num = i, b[i] = a[i].RV = RD(), c[i] = a[i].RH = RD();
  sort(b + 1, b + n + 1), b[0] = unique(b + 1, b + n + 1) - b;
  sort(c + 1, c + n + 1), c[0] = unique(c + 1, c + n + 1) - c;
  for (unsigned i(1); i <= n; ++i) {
    Sumx += a[i].RV;
    Sumy += a[i].RH;
    Sumqx = (Sumqx + (unsigned long long)a[i].RV * a[i].RV) % Mod;
    Sumqy = (Sumqy + (unsigned long long)a[i].RH * a[i].RH) % Mod;
    a[i].Ve = lower_bound(b + 1, b + b[0], a[i].RV) - b;
    a[i].Ho = lower_bound(c + 1, c + c[0], a[i].RH) - c;
  }
  sort(a + 1, a + n + 1), Build(Root[0] = N, 1, c[0]); 
  for (unsigned i(1); i <= n; ++i) {
    A = a[i].Ho, B = a[i].RV, C = a[i].RH;
    Ins(Root[i - 1], Root[i] = ++CntN, 1, c[0]);
  }
  for (unsigned i(1); i <= n; ++i) {
    unsigned long long* An(Ans + a[i].Num);
    Nx = a[i].RV, Ny = a[i].RH;
    *An = (Nx * Nx + Ny * Ny) % Mod;
    *An = (*An) * n % Mod;
    *An += Sumqx + Sumqy;
    *An = (*An) * Inv2 % Mod;
    *An = (*An) + (Mod << 1) - (Nx * Sumx % Mod) - (Ny * Sumy % Mod);
//    printf("Ans %u Pre %llu\n", a[i].Num, (*An) % Mod);
    A = 1, B = a[i].Ho, QN = Qx = Qy = Qxy = 0, Root[i]->Qry(1, c[0]);
    *An = ((*An) + (QN * Nx % Mod) * Ny) % Mod;
    *An = ((*An) + Mod + Mod + Qxy - (Qy * Nx % Mod) - (Qx * Ny % Mod)) % Mod;
    TN = QN, Tx = Qx, Ty = Qy, Txy = Qxy, QN = Qx = Qy = Qxy = 0, Root[n]->Qry(1, c[0]);
    QN -= TN, Qx -= Tx, Qy -= Ty, Qxy -= Txy;
    *An = (*An) + Mod - ((QN * Nx % Mod) * Ny % Mod);
    *An = ((*An) + Mod + (Qy * Nx) + (Qx * Ny) - Qxy) % Mod;
//    printf("Ans %u Pre %llu\n", a[i].Num, (*An) % Mod);
    A = a[i].Ho + 1, B = c[0], QN = Qx = Qy = Qxy = 0, Root[i]->Qry(1, c[0]);
    *An = (*An) + Mod - ((QN * Nx % Mod) * Ny % Mod);
    *An = ((*An) + Mod + (Qy * Nx) + (Qx * Ny) - Qxy) % Mod;
//    printf("Tn %llu Tx %llu Ty %llu Txy %llu\n", QN, Qx, Qy, Qxy);
    TN = QN, Tx = Qx, Ty = Qy, Txy = Qxy, QN = Qx = Qy = Qxy = 0, Root[n]->Qry(1, c[0]);
//    printf("Qn %llu Qx %llu Qy %llu Qxy %llu\n", QN, Qx, Qy, Qxy);
    QN -= TN, Qx -= Tx, Qy -= Ty, Qxy -= Txy;
    *An = ((*An) + (QN * Nx % Mod) * Ny) % Mod;
    *An = ((*An) + Mod + Mod + Qxy - (Qy * Nx % Mod) - (Qx * Ny % Mod)) % Mod;
    *An = (*An) << 1; if(*An >= Mod) (*An) -= Mod;
  }
  for (unsigned i(1); i <= n; ++i) printf("%llu\n", Ans[i]); 
  //  }
  //  system("pause");
  return Wild_Donkey;
}

