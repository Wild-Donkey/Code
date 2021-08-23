#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned c[105][105], Contain[105][105], To[105], m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
char Flg(0);
struct Edge {
  unsigned Value, From, To;
  const inline char operator <(const Edge &x) const{
    return this->Value < x.Value;
  }
}E[1005];
inline void Clr() {}
int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = n - RD();
  for (register unsigned i(1); i <= n; ++i) {
    for (register unsigned j(1); j <= n; ++j) {
      if(i ^ j) {
        E[++Cnt].From = i, E[Cnt].To = j, E[Cnt].Value = RD();
      } else {
        RD();
      }
    }
  }
  for (register unsigned i(1); i <= n; ++i) {
    Contain[i][0] = 1, Contain[i][1] = i;
  }
  sort(E + 1, E + Cnt + 1);
  for (register unsigned i(1); (i <= Cnt) && m; ++i) {
    Flg = 0;
    if(!To[E[i].From]) {
      for (register unsigned j(1); j <= Contain[E[i].From][0]; ++j) {
        if(Contain[E[i].From][j] == E[i].To) {
          Flg = 1;
          break;
        }
      }
      if(!Flg) {
        To[E[i].From] = E[i].To, --m, Ans += E[i].Value;
        for (register unsigned j(Contain[E[i].To][0] + 1); j <= Contain[E[i].To][0] + Contain[E[i].From][0]; ++j) {
          Contain[E[i].To][j] = Contain[E[i].From][j - Contain[E[i].To][0]];
        }
        Contain[E[i].To][0] += Contain[E[i].From][0];
      }
    }
  }
//  for(register unsigned i(1); i <= n; ++i) {
//    printf("%u %u:  ", i, Contain[i][0]);
//    for (register unsigned j(1); j <= Contain[i][0]; ++j) {
//      printf("%u ", Contain[i][j]);
//    }
//    putchar('\n');
//  }
  printf("%u\n", Ans);
//  }
  return Wild_Donkey;
}

