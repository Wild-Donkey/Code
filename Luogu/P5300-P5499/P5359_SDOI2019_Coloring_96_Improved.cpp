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
char Type, EType;
struct Sta {
  unsigned long long SumPR, SumPC, SumExist;
  unsigned PR[10005], PC[10005], Exist[10005], Pos;
  inline unsigned long long Sum () {
    return (SumExist + (SumPR + SumPC) * (m - 1)) % Mod;
  }
  inline unsigned long long GetRow(unsigned x) {
    unsigned Ex(0);
    if(EType ^ Type) Ex = Exist[x];
    else Ex = ((x == Pos) ? SumExist : 0);
    return ((unsigned long long)PR[x] * (m - 1) + Mod - PC[x] + SumPC + Ex) % Mod;
  }
  inline unsigned long long GetColumn(unsigned x) {
    unsigned Ex(0);
    if(EType ^ Type) Ex = ((x == Pos) ? SumExist : 0);
    else Ex = Exist[x];
    return ((unsigned long long)PC[x] * (m - 1) + Mod - PR[x] + SumPR + Ex) % Mod;
  }
  inline unsigned long long Get(unsigned x, unsigned y) {
    if(x == y) return 0;
    unsigned Ex;
    if(EType ^ Type) Ex = ((y == Pos) ? Exist[x] : 0);
    else Ex = ((x == Pos) ? Exist[y] : 0);
    return (PR[x] + PC[y] + Ex) % Mod;
  }
  inline void Clr() {
    memset(PR + 1, 0, m << 2), memset(PC + 1, 0, m << 2), SumPR = SumPC = 0; 
  }
}cl[2], *Cur(cl + 0), *Lst(cl + 1);
inline void Flip() {
//  printf("Flip\n");
  Type ^= 1;
  swap(Cur->SumPR, Cur->SumPC);
  for (unsigned i(1); i <= m; ++i) swap(Cur->PC[i], Cur->PR[i]);
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  n = RD(), mm = (m = RD()) - 1, mm = mm * m % Mod;
  for (unsigned i(1); i <= n; ++i) a[i][0] = RD();
  for (unsigned i(1); i <= n; ++i) a[i][1] = RD();
  if(a[1][1]) EType = Type = 1, swap(a[1][1], a[1][0]);
  if(a[1][0]) {
    Cur->Pos = a[1][0];
    if(a[1][1]) Cur->Exist[a[1][1]] = 1, Cur->SumExist = 1;
    else Cur->PR[Cur->Pos] = 1, Cur->SumPR = 1;
  } else {for (unsigned i(1); i <= m; ++i) Cur->PR[i] = 1; Cur->SumPR = m;}
  for (unsigned i(2); i <= n; ++i) {
//    printf("%llu %u %u\n", Cur->Sum(), Type, EType);
    swap(Lst, Cur), Cur->SumPR = Cur->SumPC = 0;
    unsigned long long Pl(Lst->Sum());
    for (unsigned j(1); j <= m; ++j) 
      Cur->PR[j] = Lst->PR[j] + Mod - Lst->GetRow(j), Mn(Cur->PR[j]), Mn(Cur->PR[j] += Pl), Mn(Cur->SumPR += Cur->PR[j]);
    for (unsigned j(1); j <= m; ++j) 
      Cur->PC[j] = Lst->PC[j] + Mod - Lst->GetColumn(j), Mn(Cur->PC[j]), Mn(Cur->SumPC += Cur->PC[j]);
    memcpy(Cur->Exist + 1, Lst->Exist + 1, m << 2), Cur->Pos = Lst->Pos, Cur->SumExist = Lst->SumExist; 
    if(a[i][1]) {swap(a[i][1], a[i][0]); if(!Type) Flip(); }
    else if(Type) Flip();
    if(a[i][0]) {
      if (a[i][1]) {
        unsigned TmpC(Cur->Get(a[i][0], a[i][1]));
        memset(Cur->Exist + 1, 0, m << 2), Cur->SumExist = Cur->Exist[a[i][1]] = TmpC;
      } else {
        Cur->SumExist = 0;
        for (unsigned j(1); j <= m; ++j) Mn(Cur->SumExist += (Lst->Exist[j] = Cur->Get(a[i][0], j)));
        memcpy(Cur->Exist + 1, Lst->Exist + 1, m << 2);
      }
      Cur->Clr(), Cur->Pos = a[i][0], EType = Type;
    }
  }
//  printf("%llu %u %u\n", Cur->Sum(), Type, EType);
  printf("%llu\n", Cur->Sum());
//  }
  return Wild_Donkey;
}
