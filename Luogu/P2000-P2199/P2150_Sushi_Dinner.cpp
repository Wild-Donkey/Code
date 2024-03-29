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
const unsigned M(6561);
const unsigned Tri[10] = { 1,3,9,27,81,243,729,2187,6561 };
const unsigned Prime[10] = { 2,3,5,7,11,13,17,19 };
vector <unsigned> Bel[505];
unsigned long long Tmp(0), Mod(998244353), Ans(0);
unsigned PopCnt[7005], Need[7005][2];
unsigned Stack[505], STop(0), Have[505];
unsigned m, n;
unsigned A, B, D, t;
unsigned Cnt(0);
signed main() {
  n = RD(), Mod = RD();
  for (unsigned i(2); i <= n; ++i) {
    unsigned Ti(i);
    for (unsigned j(0); j < 8; ++j) {
      if (!(Ti % Prime[j])) Have[i] |= (1 << j);
      while (!(Ti % Prime[j])) Ti /= Prime[j];
    }
    if (Ti > 1) Stack[++STop] = Ti;
    Bel[Ti].push_back(i);
  }
  for (unsigned i(0); i < M; ++i) {
    for (unsigned j(0); j < 8; ++j) {
      unsigned Jth((i / Tri[j]) % 3);
      if (Jth) Need[i][(Jth & 1) ? 0 : 1] |= (1 << j);
    }
  }
  sort(Stack + 1, Stack + STop + 1);
  STop = unique(Stack + 1, Stack + STop + 1) - Stack - 1;
  for (unsigned i(0); i < M; ++i) PopCnt[i] = PopCnt[i / 3] + (bool)(i % 3);
  for (unsigned i(0); i < M; ++i) {
    Tmp = 1;
    for (auto j : Bel[1]) {
      if ((Have[j] & Need[i][0]) == Have[j]) { Tmp <<= 1; if (Tmp >= Mod) Tmp -= Mod; }
      if ((Have[j] & Need[i][1]) == Have[j]) { Tmp <<= 1; if (Tmp >= Mod) Tmp -= Mod; }
    }
    for (unsigned j(1); j <= STop; ++j) {
      A = 1, B = 1;
      for (auto k : Bel[Stack[j]]) {
        if ((Have[k] & Need[i][0]) == Have[k]) { A <<= 1; if (A >= Mod) A -= Mod; }
        if ((Have[k] & Need[i][1]) == Have[k]) { B <<= 1; if (B >= Mod) B -= Mod; }
      }
      Tmp = Tmp * (A + B - 1) % Mod;
    }
    Ans += (PopCnt[i] & 1) ? (Mod - Tmp) : Tmp;
    if (Ans >= Mod) Ans -= Mod;
  }
  printf("%llu\n", Ans);
  return Wild_Donkey;
}
/*
100 100000000
*/