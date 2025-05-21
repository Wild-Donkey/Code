#include <bits/stdc++.h>
#define Wild_Donkey 0
#define foreplay for
#define wild while
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
unsigned S = 1, T = 2;
unsigned l, r, Base(1), Lg(0), Lim(0);
unsigned FullN[30];
vector<pair<unsigned, char> > To[105];
unsigned Cnt(2), Ans(0), Tmp(0);
//  inline void Clr() {}
unsigned Full(unsigned x) {
  while (Lim < x)
    FullN[Lim + 1] = ++Cnt, To[Cnt].push_back({FullN[Lim], 0}),
                To[Cnt].push_back({FullN[Lim], 1}), ++Lim;
  return FullN[x];
}
void Go(unsigned L, unsigned R, unsigned Dep, unsigned From) {
  // printf("[%u, %u] D %u La %u\n", L, R, Dep, From);
  unsigned Mid((L + R) >> 1), Cur;
  if (l <= Mid) {
    if (l <= L && Mid <= r)
      To[From].push_back({Full(Dep - 1), 0});
    else {
      if (From == 1)
        Cur = 1;
      else
        Cur = ++Cnt, To[From].push_back({Cur, 0});
      Go(L, Mid, Dep - 1, Cur);
    }
  }
  if (r > Mid) {
    if (l <= Mid + 1 && R <= r)
      To[From].push_back({Full(Dep - 1), 1});
    else {
      Cur = ++Cnt, To[From].push_back({Cur, 1});
      Go(Mid + 1, R, Dep - 1, Cur);
    }
  }
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  l = RD(), r = RD(), FullN[0] = T;
  while (Base <= r) Base <<= 1, ++Lg;
  Go(0, Base - 1, Lg, S);
  printf("%u\n", Cnt);
  for (unsigned i(1); i <= Cnt; ++i) {
    printf("%u", To[i].size());
    for (auto j : To[i]) printf(" %u %u", j.first, j.second);
    putchar(0x0A);
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
g++ a.cpp -static-libstdc++
*/