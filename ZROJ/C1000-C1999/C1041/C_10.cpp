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
vector <unsigned> Contain[500005];
bitset<500005> Own;
unsigned a[500005], Range[500005][2];
unsigned StCo[500005];
unsigned m, n, q;
unsigned A, B, C, D, t;
unsigned Ans(0), Cnt(0), Tmp(0);
char Flg(0);
//  inline void Clr() {}
signed main() {
//  freopen("C4.in", "r", stdin);
//  freopen("C4.out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(1); i < n; ++i) a[i] = RD();
  if(n <= 5000) {
    for (unsigned i(1); i <= n; ++i) for (unsigned j(RD()); j; --j) Contain[i].push_back(RD());
    for (unsigned i(1); i <= n; ++i) {
      Own = 0;
      Range[i][0] = Range[i][1] = i;
      for (auto j:Contain[i]) Own[j] = 1;
      while (1) {
        if((Range[i][0] > 1) && (Own[a[Range[i][0] - 1]])) {
          --Range[i][0];
          for (auto j:Contain[Range[i][0]]) Own[j] = 1;
          continue;
        }
        if((Range[i][1] < n) && (Own[a[Range[i][1]]])) {
          ++Range[i][1];
          for (auto j:Contain[Range[i][1]]) Own[j] = 1;
          continue;
        }
        break;
      }
  //    printf("%u : [%u, %u]\n", i, Range[i][0], Range[i][1]);
    }
    m = RD();
    for (unsigned i(1); i <= m; ++i) {
      A = RD(), B = RD();
      printf(((Range[A][0] <= B) && (B <= Range[A][1])) ? "YES\n" : "NO\n");
    }
  } else {
    for (unsigned i(1); i <= n; ++i) for (unsigned j(RD()); j; --j) StCo[i] |= 1 << (RD() - 1);
    
  }
  return Wild_Donkey;
}
/*
7
6 3 4 1 2 5
1 1
1 5
1 1
1 1
2 2 3
1 4
1 6
3
4 1
5 3
4 7
*/
