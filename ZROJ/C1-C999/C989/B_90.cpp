#pragma GCC diagnostic error "-std=c++11"
#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <algorithm>
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
unsigned a[4005][2005], f[4005][2005], g[4005][2005];
unsigned m, n, Sz(1000000), Now(Sz);
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0);
char RB[1000005];
inline char GC() {
  if (Now == Sz) Now = 0, fread(RB, 1, Sz, stdin);
  return RB[Now++];
}
inline unsigned RD() {
  register unsigned intmp(0);
  register char rdch(GC());
  while (rdch < '0') rdch = GC();
  while (rdch >= '0') intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = GC();
  return intmp;
}
inline unsigned Mx(const unsigned x, const unsigned y) { return (y < x) ? x : y; }
inline void Udt(unsigned& x, const unsigned y) { if (x > y) x = y; }
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  memset(f, 0x3f, sizeof(f)), memset(g, 0x3f, sizeof(g)), n = RD(), m = n >> 1;
  for (register unsigned i(1); i <= n; ++i)
    for (register unsigned j(1), Len((n - i + 1) >> 1); j <= Len; ++j)
      a[i][j] = RD();
  for (register unsigned i(n - 1); i; --i) g[i + 1][1] = f[i][1] = a[i][1];
  for (register unsigned Len(2); Len <= m; ++Len) {
    for (register unsigned i(n - (Len << 1) + 1); i; --i) {
      register unsigned* Le(f[i]), * Ri(g[i + (Len << 1) - 1] + Len), Tmp(Mx(f[i + 1][Len - 1], a[i][Len]));
      for (register unsigned j((Len + 7) >> 3); j; --j) {
        Udt(Tmp, Mx(*(++Le), *(--Ri)));
        Udt(Tmp, Mx(*(++Le), *(--Ri)));
        Udt(Tmp, Mx(*(++Le), *(--Ri)));
        Udt(Tmp, Mx(*(++Le), *(--Ri)));
        Udt(Tmp, Mx(*(++Le), *(--Ri)));
        Udt(Tmp, Mx(*(++Le), *(--Ri)));
        Udt(Tmp, Mx(*(++Le), *(--Ri)));
        Udt(Tmp, Mx(*(++Le), *(--Ri)));
      }
      f[i][Len] = g[i + (Len << 1) - 1][Len] = Tmp;
    }
  }
  printf("%u\n", f[1][m]);
  //  }
  return Wild_Donkey;
}