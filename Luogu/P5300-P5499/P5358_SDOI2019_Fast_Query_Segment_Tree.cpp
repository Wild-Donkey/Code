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
const unsigned long long Mod(10000019);
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
inline unsigned RDsg() {
  unsigned rdtp(0);
  char Sg(0), rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') Sg = 1, rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0', rdch = getchar();
  return Sg ? (Mod - (rdtp % Mod)) : (rdtp % Mod);
}
inline void Mn(unsigned& x) { x -= ((x >= Mod) ? Mod : 0);}
unsigned Q[100005][3], Pos[100005];
unsigned m, n, t, Val;
unsigned A, B, C, D, OpP, OpV;
unsigned Cnt(0), Ans(0), Tmp(0);
struct Node {
  Node *LS, *RS;
  unsigned Sum, Def, Mul, Pls;
  inline void Build(unsigned L, unsigned R);
  inline void PsDw(unsigned long long Llen, unsigned long long Rlen) {
    if(Def ^ 0x3f3f3f3f) {
      LS->Mul = RS->Mul = 1;
      LS->Pls = RS->Pls = 0;
      LS->Def = RS->Def = Def;
      LS->Sum = Def * Llen % Mod;
      RS->Sum = Def * Rlen % Mod;
      Def = 0x3f3f3f3f;
    }
    if(Mul ^ 1) {
      LS->Mul = (unsigned long long)Mul * LS->Mul % Mod;
      LS->Pls = (unsigned long long)Mul * LS->Pls % Mod;
      LS->Sum = (unsigned long long)Mul * LS->Sum % Mod;
      RS->Mul = (unsigned long long)Mul * RS->Mul % Mod;
      RS->Pls = (unsigned long long)Mul * RS->Pls % Mod;
      RS->Sum = (unsigned long long)Mul * RS->Sum % Mod;
      Mul = 1;
    }
    if(Pls) {
      Mn(LS->Pls += Pls), Mn(RS->Pls += Pls);
      LS->Sum = (LS->Sum + Pls * Llen) % Mod;
      RS->Sum = (RS->Sum + Pls * Rlen) % Mod;
      Pls = 0;
    }
  }
  inline void Define(unsigned L, unsigned R) {
    if(L == R) {Mul = 1, Pls = 0, Def = Sum = OpV; return;}
    unsigned Mid((L + R) >> 1);
    this->PsDw(Mid - L + 1, R - Mid);
    if(OpP <= Mid) LS->Define(L, Mid);
    else RS->Define(Mid + 1, R);
    Sum = LS->Sum + RS->Sum, Mn(Sum);
  }
  inline void Qry(unsigned L, unsigned R) {
    if(L == R) {OpV = Sum; return;}
    unsigned Mid((L + R) >> 1);
    this->PsDw(Mid - L + 1, R - Mid);
    if(OpP <= Mid) LS->Qry(L, Mid);
    else RS->Qry(Mid + 1, R);
  }
}N[200005], *CntN(N);
inline void Node::Build(unsigned L, unsigned R) {
  Def = 0x3f3f3f3f, Mul = 1, Pls = 0, Sum = 0;
  if(L == R) return;
  unsigned Mid((L + R) >> 1);
  (LS = ++CntN)->Build(L, Mid);
  (RS = ++CntN)->Build(Mid + 1, R);
}
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), Val = 0;
  for (unsigned i(1); i <= m; ++i) {
    Q[i][0] = A = RD();
    if(A ^ 6) {
      if(A ^ 5) { if(A == 1) Pos[++Cnt] = Q[i][1] = RD(), Q[i][2] = RDsg(); else Q[i][1] = RDsg(); }
      else Q[i][1] = Pos[++Cnt] = RD();
    }
  }
  sort(Pos + 1, Pos + Cnt + 1), Cnt = unique(Pos + 1, Pos + Cnt + 1) - Pos - 1;
//  for (unsigned i(1); i <= Cnt; ++i) printf("%u ", Pos[i]); putchar(0x0A);
  N->Build(1, Cnt), t = RD(), n -= Cnt;
//  printf("%u + %u\n", Cnt, n);
  for (unsigned i(1); i <= m; ++i) if((Q[i][0] == 5) || (Q[i][0] == 1))
    Q[i][1] = lower_bound(Pos + 1, Pos + Cnt + 1, Q[i][1]) - Pos;
  for (unsigned i(1); i <= t; ++i) {
    A = RD(), B = RD();
    for (unsigned j(1); j <= m; ++j) {
      D = ((A + (unsigned long long)B * j) % m) + 1;
      printf("D %u Do %u Args %u %u\n", D, Q[D][0], Q[D][1], Q[D][2]);
      switch(Q[D][0]) {
        case (1) :{
          OpP = Q[D][1], OpV = Q[D][2], N->Define(1, Cnt);
          break;
        }
        case (2) :{
          Mn(Val += Q[D][1]);
          Mn(N->Pls += Q[D][1]), N->Sum = (N->Sum + ((unsigned long long)Cnt * Q[D][1])) % Mod;
          break;
        }
        case (3) :{
          Val = (unsigned long long)Q[D][1] * Val % Mod;
          N->Mul = (unsigned long long)N->Mul * Q[D][1] % Mod;
          N->Pls = (unsigned long long)N->Pls * Q[D][1] % Mod;
          N->Sum = (unsigned long long)N->Sum * Q[D][1] % Mod;
          break;
        }
        case (4) :{
          N->Mul = 1, N->Pls = 0, Val = N->Def = Q[D][1];
          N->Sum = (unsigned long long)Cnt * Q[D][1] % Mod;
          break;
        }
        case (5) :{
          OpP = Q[D][1], N->Qry(1, Cnt), Mn(Ans += OpV);
          printf("%u\n", OpV);
          break;
        }
        case (6) :{
          printf("%u\n", (N->Sum + (unsigned long long)Val * n) % Mod);
          Ans = (Ans + N->Sum + (unsigned long long)Val * n) % Mod;
          break;
        }
      }
//      printf("Val %u Sum %u\n", Val, N->Sum);
    }
  }
  printf("%u\n", Ans);
//  }
  return Wild_Donkey;
}
/*
8036510

1701731

7957206
*/
