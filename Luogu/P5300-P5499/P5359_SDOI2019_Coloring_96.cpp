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
const unsigned long long Mod(1000000009);
inline void Mn(unsigned long long& x) {x -= ((x >= Mod) ? Mod : 0);}
inline void Mn(unsigned& x) {x -= ((x >= Mod) ? Mod : 0);}
unsigned a[100005][2];
unsigned long long mm;
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0);
struct Sta {
  unsigned long long Pl, SumPR, SumPC, SumExist;
  unsigned PR[10005], PC[10005], Exist[10005], Pos;
  char Type;
  inline unsigned long long Sum () {
    return (SumExist + mm * Pl + (SumPR + SumPC) * (m - 1)) % Mod;
  }
  inline unsigned long long Get(unsigned x, unsigned y) {
    unsigned Ex(0);
    if(Type == 1) Ex = ((x == Pos) ? Exist[y] : 0);
    if(Type == 2) Ex = ((y == Pos) ? Exist[x] : 0);
    return (Pl + PR[x] + PC[y] + Ex) % Mod;
  }
  inline unsigned long long GetRow(unsigned x) {
    unsigned Ex(0);
    if(Type == 1) Ex = ((x == Pos) ? (Mod + SumExist - Exist[x]) : 0);
    if(Type == 2) Ex = ((x == Pos) ? 0 : Exist[x]);
    return ((Pl + PR[x]) * (m - 1) + Mod - PC[x] + SumPC + Ex) % Mod;
  }
  inline unsigned long long GetColumn(unsigned x) {
    unsigned Ex(0);
    if(Type == 1) Ex = ((x == Pos) ? 0 : Exist[x]);
    if(Type == 2) Ex = ((x == Pos) ? (Mod + SumExist - Exist[x]) : 0);
    return ((Pl + PC[x]) * (m - 1) + Mod - PR[x] + SumPR + Ex) % Mod;
  }
  inline void Clr() {
    Pl = 0;
    memset(PR + 1, 0, m << 2);
    memset(PC + 1, 0, m << 2);
  }
  inline void Udt() {
    SumExist = SumPR = SumPC = 0;
    for (unsigned i(1); i <= m; ++i) SumExist += Exist[i];
    for (unsigned i(1); i <= m; ++i) SumPC += PC[i];
    for (unsigned i(1); i <= m; ++i) SumPR += PR[i];
    SumExist %= Mod;
    SumPC %= Mod;
    SumPR %= Mod;
  }
}Cur, Lst;
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), mm = (m = RD()) - 1, mm = mm * m % Mod;
  for (unsigned i(1); i <= n; ++i) a[i][0] = RD();
  for (unsigned i(1); i <= n; ++i) a[i][1] = RD();
  if(a[1][0]) {
    Cur.Type = 1, Cur.Pos = a[1][0];
    if(a[1][1]) Cur.Exist[a[1][1]] = 1, Cur.SumExist = 1;
    else Cur.PR[Cur.Pos] = 1, Cur.SumPR = 1;
  }
  else {
    if(!a[1][1]) Cur.Type = 0, Cur.Pl = 1; 
    else Cur.Type = 2, Cur.PC[Cur.Pos = a[1][1]] = 1, Cur.SumPC = 1;
  }
  printf("%llu\n", Cur.Sum());
  for (unsigned i(2); i <= n; ++i) {
    Lst = Cur, Mn(Cur.Pl += Lst.Sum());
    for (unsigned j(1); j <= m; ++j) Mn(Cur.PR[j] += Mod - Lst.GetRow(j));
    for (unsigned j(1); j <= m; ++j) Mn(Cur.PC[j] += Mod - Lst.GetColumn(j));
    if(a[i][0]) {
      if (a[i][1]) {
        memset(Cur.Exist + 1, 0, m << 2);
        Cur.Exist[a[i][1]] = Cur.Get(a[i][0], a[i][1]);
      } else {
        for (unsigned j(1); j <= m; ++j) Lst.Exist[j] = Cur.Get(a[i][0], j); Lst.Exist[a[i][0]] = 0;
        memcpy(Cur.Exist + 1, Lst.Exist + 1, m << 2);
      }
      Cur.Clr(), Cur.Type = 1, Cur.Pos = a[i][0];
    } else {
      if (a[i][1]) {
        for (unsigned j(1); j <= m; ++j) Lst.Exist[j] = Cur.Get(j, a[i][1]); Lst.Exist[a[i][1]] = 0; 
        memcpy(Cur.Exist + 1, Lst.Exist + 1, m << 2);
        Cur.Clr(), Cur.Type = 2, Cur.Pos = a[i][1];
      }
    }
    Cur.Udt();
    printf("%llu\n", Cur.Sum());
  }
  printf("%llu\n", Cur.Sum());
//  }
  return Wild_Donkey;
}

