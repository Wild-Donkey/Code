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
const unsigned M(6561);
const unsigned Tri[105] = { 1,3,9,27,81,243,729,2187,6561 };
const unsigned Prime[105] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499 };
vector <unsigned> Bel[505];
unsigned long long Mod(998244353), f[7005], Ans(0);
unsigned PopCnt[7005], Need[7005][2];
unsigned Stack[505], STop(0), Have[505];
unsigned m, n;
unsigned A, B, D, t;
unsigned Cnt(0), Tmp(0);
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
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
      if (Jth) {
        if (Jth % 1) Need[i][0] |= (1 << j);
        else Need[i][1] |= (1 << j);
      }
    }
  }
  sort(Stack + 1, Stack + STop + 1);
  STop = unique(Stack + 1, Stack + STop + 1) - Stack - 1;
  for (unsigned i(0); i < M; ++i) PopCnt[i] = PopCnt[i / 3] + (bool)(i % 3);
  for (unsigned i(0); i < M; ++i) {
    f[i] = 1;
    // printf("Need %u: %u %u\n", i, Need[i][0], Need[i][1]);
    for (auto j : Bel[1]) {
      // printf("Have %u: %u\n", j, Have[j]);
      if ((Have[j] & Need[i][0]) == Have[j]) { f[i] <<= 1; if (f[i] >= Mod) f[i] -= Mod; }
      if ((Have[j] & Need[i][1]) == Have[j]) { f[i] <<= 1; if (f[i] >= Mod) f[i] -= Mod; }
    }
    for (unsigned j(1); j <= STop; ++j) {
      A = 1, B = 1;
      for (auto k : Bel[Stack[j]]) {
        if ((Have[k] & Need[i][0]) == Have[k]) { A <<= 1; if (A >= Mod) A -= Mod; }
        if ((Have[k] & Need[i][1]) == Have[k]) { B <<= 1; if (B >= Mod) B -= Mod; }
      }
      f[i] = f[i] * (A + B - 1) % Mod;
    }
    Ans += (PopCnt[i] & 1) ? (Mod - f[i]) : f[i];
    if (Ans >= Mod) Ans -= Mod;
    // printf("f%u = %llu\n", i, f[i]);
  }
  printf("%llu\n", Ans);
  //  }
  system("pause");
  return Wild_Donkey;
}