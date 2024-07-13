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
vector <char> To[65];
unsigned List[65], Do[65], f[65], g[65];
unsigned M, m, n, p, P, Q;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char Flg(0);
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), M = 1 << (m = RD()), p = RD(), Q = p - (P = RD()) - 1;
  for (unsigned j(0); j < p; ++j) B |= (RD() << j);
  for (unsigned j(0); j < p; ++j) A |= (RD() << j);
  for (unsigned j(p - 1); ~j; --j) C |= (RD() << j);
  for (unsigned i(0); i < M; ++i, Flg = 0) {
    for (unsigned j(0); (j < m) && (!Flg); ++j) if((1 << j) & i) {
      i ^= (1 << j);
      if(j < P) Flg = (i & (A >> (P - j))) ? 1 : 0;
      else Flg = (i & (A << (j - P))) ? 1 : 0;
      i ^= (1 << j);
    }
    if(!Flg) List[++Cnt] = i;
  }
  for (unsigned i(1); i <= Cnt; ++i) {
    for (unsigned j(0); j < M; ++j) if((1 << j) & List[i]) {
      if(j < P) Do[i] |= (B >> (P - j));
      else Do[i] |= (B << (j - P));
      if(j < Q) Do[i] |= (C >> (Q - j));
      else Do[i] |= (C << (j - Q));
    }
//    printf("%u %u Do %u\n", i, List[i], Do[i]);
  }
  for (unsigned j(1); j <= Cnt; ++j) {
    for (unsigned k(1); k <= Cnt; ++k) {
      if(!(Do[j] & List[k])) To[j].push_back(k);
    }
  }
  g[1] = 1;
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned j(1); j <= Cnt; ++j) for (auto k:To[j]) f[k] += g[j];
    memcpy(g, f, (Cnt + 1) << 2), memset(f, 0, (Cnt + 1) << 2);
  }
  for (unsigned i(1); i <= Cnt; ++i) Ans += g[i];
  printf("%u\n", Ans);
//  }
  return Wild_Donkey;
}

