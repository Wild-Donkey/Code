#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
#include <string>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned long long RD() {
  unsigned long long intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
unsigned long long Mod(1000000007); 
unsigned a[10005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
struct Tree {
  unordered_map<unsigned long long, unsigned long long> BeRoot;
  map<pair<unsigned long long, unsigned long long>, unsigned long long> Dist;
  Tree* LS, * RS;
  unsigned long long Size, LP, RP, Len, Ans;
  inline unsigned long long Dis(unsigned long long x, unsigned long long y) {
//    printf("Dis %llu %llu\n", x, y);
    if(!(Dist[make_pair(x, y)])) {
      if(x == y) return 0;
      if(x > y) swap(x, y);
      if(x <= LS->Size) {
        if(y <= LS->Size) return Dist[make_pair(y, x)] = Dist[make_pair(x, y)] = LS->Dis(x, y);
        return Dist[make_pair(y, x)] = Dist[make_pair(x, y)] = (LS->Dis(x, LP) + RS->Dis(y - LS->Size, RP) + Len) % Mod;
      }
      return Dist[make_pair(y, x)] = Dist[make_pair(x, y)] = RS->Dis(x - LS->Size, y - LS->Size);
    }
    return Dist[make_pair(x, y)];
  }
  inline unsigned long long Find (const unsigned long long& x){
//    printf("Root %llu\n", x);
    if(BeRoot[x]) return BeRoot[x];
    if(Size <= 1) return BeRoot[x] = 0;
    if(x <= LS->Size) return BeRoot[x] = (Dis(x, LS->Size + RP) * (RS->Size % Mod) + LS->Find(x) + RS->Find(RP)) % Mod;
//    printf("Here\n");
    return BeRoot[x] = (Dis(x, LP) * (LS->Size % Mod) + RS->Find(x - LS->Size) + LS->Find(LP)) % Mod;
  }
}Tr[105];
inline void Clr() {
  for (unsigned i(0); i <= n; ++i) Tr[i].BeRoot.clear(), Tr[i].Dist.clear();
  n = RD();
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  t = RD(), Tr[0].Size = 1, Tr[0].Ans = 0;
  for (unsigned T(1); T <= t; ++T){
    Clr();
    for (unsigned i(1); i <= n; ++i) {
      Tr[i].LS = Tr + RD();
      Tr[i].RS = Tr + RD();
      Tr[i].LP = RD() + 1;
      Tr[i].RP = RD() + 1;
      Tr[i].Len = RD();
      Tr[i].Size = Tr[i].LS->Size + Tr[i].RS->Size;
      Tr[i].Ans = (Tr[i].LS->Ans + Tr[i].RS->Ans + ((Tr[i].LS->Size % Mod) * (Tr[i].RS->Size % Mod) % Mod) * Tr[i].Len) % Mod;
      Tr[i].Ans = (Tr[i].Ans + (Tr[i].LS->Find(Tr[i].LP) * (Tr[i].RS->Size % Mod))) % Mod;
      Tr[i].Ans = (Tr[i].Ans + (Tr[i].RS->Find(Tr[i].RP) * (Tr[i].LS->Size % Mod))) % Mod;
      printf("%llu\n", Tr[i].Ans);
    }
  }
  return Wild_Donkey;
}
/*
4
2
0 0 0 0 2
1 1 0 0 4
2
0 0 0 0 2
1 1 0 0 4
5
0 0 0 0 1
1 1 0 0 1
1 2 1 1 1
3 3 2 3 1
4 4 3 0 1
5
0 0 0 0 990472688
1 1 0 0 264288925
1 2 1 1 560177974
3 3 2 3 188078350
4 4 3 0 843648143

990472688
999991786
174004207
334395268
361542621
*/
