#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <ctime>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>
#define Wild_Donkey 0
#define INFi 0x3f3f3f3f3f3f3f3f
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
map<pair<unsigned, unsigned>, unsigned> List;
unsigned m, n, Now;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char Flg(0);
inline void DFS (unsigned x, unsigned y) {
//  printf("Pre %u Len %u\n", x, y);
  if(!x) {Ans = min(Ans, y - 1); return;}
  if(x >= y) DFS(x - y, y << 1);
  if(x > y) DFS(x - y - 1, (y << 1) + 1);
  if(x + (y << 1) <= Ans) DFS(x, y << 1);
  if((x + (y << 1) - 1 <= Ans) && (y > 1)) DFS(x, (y << 1) - 1);
}
inline char Judge (unsigned x, unsigned L, unsigned R) {
//  printf("Judge [%u, %u] as %u\n", L, R, x);
  if(R > x) return 0;
  if((!L) && (R == x)) return 1;
  if(L > (x >> 1)) return Judge((x - 1) >> 1, L - (x >> 1) - 1, R - (x >> 1) - 1);
  if(R <= (x >> 1)) return Judge(x >> 1, L, R);
  return 0;
}
signed main() {
//  freopen("A.in", "r", stdin);
//  freopen("A.out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    A = RD(), B = RD(), n = min(RD(), B << 1);
    unsigned Top(min(n, ((A - 1) << 1) + 1));
    if(Top <= 50000 + B) {
      Flg = 0;
      for (unsigned i(B); i <= Top; ++i) if(Judge(i, A, B)) {Flg = 1, printf("%u\n", i); break;}
      if(!Flg) printf("-1\n");
    } else {
      Ans = n + 1, DFS(A, B - A + 1);
      if(Ans > n) printf("-1\n");
      else printf("%u\n", Ans);
    }
  }
  return Wild_Donkey;
}
/*
2
0 5 10
6 7 10

8942 9040 28304
*/
