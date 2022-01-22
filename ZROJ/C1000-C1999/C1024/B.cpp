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
struct Calc {
  double Tms;
  unsigned Pos, Val;
  char Type;
  inline const char operator < (const Calc& x) const {return Tms > x.Tms;} 
}Cl[100005];
const unsigned long long Mod(1000000007);
unsigned long long a[100005], Ans(1);
unsigned m, n, Do, A, B, C;
unsigned CntC(0);
unsigned Chg[100005];
vector<unsigned> Pls[100005];
signed main() {
//  freopen("B.in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), Do = RD();
  for (unsigned i(1); i <= n; ++i) a[i] = RD();
//  printf("Done\n");
  for (unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD(), C = RD();
    if(A & 1) {
      if(A & 2) {
        ++CntC, Cl[CntC].Tms = Cl[CntC].Val = C, Cl[CntC].Type = 1;
      } else Chg[B] = max(Chg[B], C);
    } else Pls[B].push_back(C);
  }
//  printf("Done\n");
  for (unsigned i(1); i <= n; ++i) {
    if(Chg[i] > a[i]) Pls[i].push_back(Chg[i] - a[i]);
    if(Pls[i].size()) {
      sort(Pls[i].begin(), Pls[i].end());
      double Now(a[i]);
      for (unsigned j(Pls[i].size() - 1); ~j; --j) {
        ++CntC;
        Cl[CntC].Tms = (Now + Pls[i][j]) / Now;
        Cl[CntC].Pos = i;
        Now += (Cl[CntC].Val = Pls[i][j]);
      }
    }
  }
//  printf("Done\n");
  sort(Cl + 1, Cl + CntC + 1);
//  printf("Done\n");
  for (unsigned i(min(Do, CntC)); i; --i) {
    if(Cl[i].Type) Ans = Ans * Cl[i].Val % Mod;
    else {
      a[Cl[i].Pos] += Cl[i].Val;
      if(a[Cl[i].Pos] >= Mod) a[Cl[i].Pos] -= Mod;
    }
  }
  for (unsigned i(1); i <= n; ++i) Ans = Ans * a[i] % Mod;
  printf("%llu\n", Ans);
//  }
  return Wild_Donkey;
}

