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
struct Line {
  map<unsigned, unsigned> S;
}L[4005];
map<unsigned, Line> SS;
unsigned Pos[4000005][2];
unsigned a[2005][2005];
char Ans[2005][2005];
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
char Cur, Pre;
//  inline void Clr() {}
inline char Find() {
  
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), A = n * n;
  for (unsigned i(1); i <= n; ++i) for (unsigned j(1); j <= n; ++j) Pos[a[i][j] = RD()][0] = i, Pos[a[i][j]][1] = j;
  for (unsigned i(1); i <= A; ++i) L[Pos[i][0] + Pos[i][1]].S.insert({n + Pos[i][1] - Pos[i][0], i});
  for (unsigned i(n << 1); i; --i) if(L[i].S.size()) SS.insert({i, L[i]});
  for (unsigned i(A); i; --i) {
    C = Pos[i][0], D = Pos[i][1];
    map<unsigned, Line>::iterator It(SS.find(C + D));
    if(It != SS.end()) {
//      printf("%u Found %u\n", i, It->first);
      map<unsigned, unsigned>::iterator IT(It->second.S.find(n + D - C));
      if(IT != It->second.S.end()) {
//        printf("%u Found %u\n", i, IT->first);
        Ans[C][D] = 1, It->second.S.erase(IT);
        if(!(It->second.S.size())) SS.erase(C + D);
        if(!SS.size()) continue;
//        printf("%u %u\n", C, D);
        B = C + D, D = n + D - C, C = B;
//        printf("%u %u\n", C, D);
        if(C > m) while (SS.begin()->first < C - m) SS.erase(SS.begin());
        while (SS.rbegin()->first > C + m) SS.erase(--SS.end());
        for (map<unsigned, Line>::iterator j(SS.begin()); j != SS.end(); ++j) {
//          printf("Del %u, %u] [%u Ba %u\n", j.first, D - m, D + m, j->second.S.rbegin()->first);
          while((j != SS.end()) && (!(j->second.S.size()))) SS.erase(j++);
          if(D > m) while (j->second.S.begin()->first < D - m) j->second.S.erase(j->second.S.begin());
          while (j->second.S.rbegin()->first > D + m) j->second.S.erase(--(j->second.S.end()));
//          printf("Del [%u, %u]\n", j.second.S.begin()->first, j.second.S.rbegin()->first);
//          for (auto k:j.second.S) printf("%u ", k.first); putchar(0x0A);
        }
      }
    }
  }
  for (unsigned i(1); i <= n; ++i) {for (unsigned j(1); j <= n; ++j) putchar(Ans[i][j] ? 'M' : 'G'); putchar(0x0A);}
//  }
  return Wild_Donkey;
}
/*
3 1
1 2 4
6 8 3
9 5 7
*/
