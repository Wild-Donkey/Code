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
unsigned Inv[10000020], Q[100005][3], Pos[100005], a[100005], T[100005], Sum;
unsigned long long C;
unsigned Val(0), Mul(1), Pls(0), m, n, t;
unsigned A, B, D;
unsigned Cnt(0), Ans(0), Tmp(0);
inline void Mn(unsigned& x) { x -= ((x >= Mod) ? Mod : 0);}
inline unsigned Single(unsigned x) {return (((T[x] > T[0]) ? a[x] : Val) * (unsigned long long)Mul + Pls) % Mod;}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  Inv[1] = 1; for (unsigned i(2); i < Mod; ++i) Inv[i] = (Mod - (Mod / i)) * Inv[Mod % i] % Mod;
//  for (unsigned i(2); i < Mod; ++i) printf("%u ", Inv[i]); putchar(0x0A);
  n = RD(), m = RD(), Val = 0;
  for (unsigned i(1); i <= m; ++i) {
    Q[i][0] = A = RD();
    if(A ^ 6) {
      if(A ^ 5) { if(A == 1) Pos[++Cnt] = Q[i][1] = RD(), Q[i][2] = RDsg(); else Q[i][1] = RDsg(); }
      else Q[i][1] = Pos[++Cnt] = RD();
    }
  }
  sort(Pos + 1, Pos + Cnt + 1), Cnt = unique(Pos + 1, Pos + Cnt + 1) - Pos, t = RD();
  for (unsigned i(1); i <= m; ++i) if((Q[i][0] == 5) || (Q[i][0] == 1))
    Q[i][1] = lower_bound(Pos + 1, Pos + Cnt, Q[i][1]) - Pos;
  for (unsigned i(1), k(1); i <= t; ++i) {
    A = RD(), B = RD();
    for (unsigned j(1); j <= m; ++j, ++k) {
      D = ((A + (unsigned long long)B * j) % m) + 1, C = Q[D][1];
      switch(Q[D][0]) {
        case (1) :{
          Mn(Sum += Mod - Single(C));
          a[C] = ((unsigned long long)Q[D][2] + Mod - Pls) * Inv[Mul] % Mod;
          Mn(Sum += Q[D][2]), T[C] = k;
          break;
        }
        case (2) :{
          Mn(Pls += C), Sum = (Sum + n * C) % Mod;
          break;
        }
        case (3) :{
          Sum = Sum * C % Mod;
          Mul = Mul * C % Mod;
          Pls = Pls * C % Mod;
          if(Mul == 0) T[0] = k, Val = Pls = 0, Mul = 1;
          break;
        }
        case (4) :{
          Mul = 1, Pls = 0, Val = C, T[0] = k;
          Sum = n * C % Mod;
          break;
        }
        case (5) :{
//          printf("Ti %u find %u Time %u T0 %u\n", k, C, T[C], T[0]);
//          printf("%u\n", ((T[C] > T[0]) ? Calc(a[C]) : Calc(Val)));
          Mn(Ans += Single(C));
          break;
        }
        case (6) :{
//          printf("%u\n", Sum);
          Mn(Ans += Sum);
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
