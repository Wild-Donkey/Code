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
inline unsigned long long RDll() {
  unsigned long long intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
struct Stone {
  unsigned long long f, g;
  unsigned Pos;
};
vector<Stone> b[1000005];
unsigned long long K;
unsigned a[2000005], Cnt[1000005], n, m, nn;
unsigned A, B, C, D, t;
unsigned Ans(0), Tmp(0);
unsigned long long Back(unsigned x, unsigned y, unsigned z) {
  if(y == z) return b[x][y - 1].f;
  unsigned long long Rt(b[x][y - 1].f - b[x][y - z].f);
  Rt -= (unsigned long long)(y - z) * (b[x][y - 1].Pos - b[x][y - z].Pos + 1 - z);
  return Rt;
}
unsigned long long Frt(unsigned x, unsigned y, unsigned z) {
  unsigned Tot(b[x].size());
  if(Tot - z == y - 1) return b[x][y - 1].g;
  unsigned long long Rt(b[x][y - 1].g - b[x][y + z - 2].g);
  Rt -= (unsigned long long)(Tot + 1 - y - z) * (b[x][y + z - 2].Pos - b[x][y - 1].Pos + 1 - z);
  return Rt;
}
//  inline void Clr() {}
signed main() {
//  freopen("magic3.in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  nn = ((n = RD()) << 1), m = RD(), K = RDll();
  for (unsigned i(1); i <= n; ++i) ++Cnt[a[n + i] = a[i] = RD()];
  for (unsigned i(1); i <= nn; ++i) {
    unsigned Cur(a[i]);
    if(!(b[Cur].size())) {b[Cur].push_back({0, 0, i}); continue;}
    unsigned long long Len((unsigned long long)b[Cur].size() * (i - b[Cur].back().Pos - 1));
    b[Cur].push_back({b[Cur].back().f + Len, 0, i});
  }
  for (unsigned i(1); i <= m; ++i) if(b[i].size()) {
    unsigned Tot(b[i].size());
    for (unsigned j(Tot - 2); ~j; --j) {
      unsigned long long Len((unsigned long long)(Tot - j - 1) * (b[i][j + 1].Pos - b[i][j].Pos - 1));
      b[i][j].g = b[i][j + 1].g + Len;
    }
  }
  for (unsigned i(1); i <= m; ++i) if(b[i].size()) {
    unsigned Tot(b[i].size());
    for (unsigned j(Tot - 1); ~j; --j) {
      unsigned long long Cost(0);
      unsigned L(1), R(min((Cnt[i] + 1) >> 1, min(j + 1, Tot - j))), Mid;
//      printf("2k + 1 From %u Mx %u\n", j + 1, R);
      while (L < R) {
        Mid = ((L + R + 1) >> 1);
        Cost = Back(i, j + 1, Mid) + Frt(i, j + 1, Mid);
//        printf("Len %u, %u in [%u, %u] Cost %llu\n", Mid, i, j - Mid + 2, j + Mid, Cost);
        if(Cost <= K) L = Mid;
        else R = Mid - 1;
      }
//      printf("Done %u\n", L);
      Ans = max((L << 1) - 1, Ans);
    }
    for (unsigned j(Tot - 1); j; --j) {
      unsigned long long Cost(0);
      unsigned L(1), R(min(Cnt[i] >> 1, min(j, Tot - j))), Mid;
      while (L < R) {
        Mid = ((L + R + 1) >> 1);
        Cost = Back(i, j, Mid) + Frt(i, j, Mid + 1);
//        printf("Len %u, %u in [%u, %u] Cost %llu\n", Mid, i, j - Mid + 1, j + Mid, Cost);
        if(Cost <= K) L = Mid;
        else R = Mid - 1;
      }
      Ans = max(L << 1, Ans);
//      printf("Done %u\n", L);
    }
  }
  printf("%u\n", Ans);
//  }
  return Wild_Donkey;
}
/*
10 2 3
1 2 1 1 2 1 2 2 1 1
1 2 1 1 2 1 2 2 1 1 1 2 1 1 2 1 2 2 1 1
*/
