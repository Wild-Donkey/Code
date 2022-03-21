#pragma GCC optimize(2)
#pragma GCC target("avx")
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
#pragma GCC optimize(3)
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
bitset<1500005> Ava;
bitset<1000005> M; 
unsigned Nxt[3000005], To[3000005], E[1000005];
unsigned Add[1500005][2], Dgr[1000005];
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
char Flg(0);
inline void DFS(unsigned x) {
//  printf("DFS %u %u\n", x - N, x->Top);
  unsigned &Cur(E[x]), Cr;
  while(Cur) {
    Cr = To[Cur], Cur = Nxt[Cur];
    if(!Ava[Cr]) {
      Ava[Cr] = 1;
      unsigned L(Add[Cr][0]), R(Add[Cr][1]), To((L == x) ? R : L);
      if(E[To]) DFS(To); Flg ^= 1;
      if(Flg) {
        if(Cr <= m) M[Cr] = 1, ++Tmp;
        else Dgr[L] = Dgr[R] = 0;
      }
    }
  }
}
//  inline void Clr() {}
signed main() {
//  freopen("graph2.in", "r", stdin);
//  freopen("my.out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= m; ++i) {
    ++Dgr[Add[i][0] = A = RD()], ++Dgr[Add[i][1] = B = RD()];
    Nxt[++Cnt] = E[A], E[A] = Cnt, To[Cnt] = i;
    Nxt[++Cnt] = E[B], E[B] = Cnt, To[Cnt] = i;
  }
  for (unsigned i(1), Lst(0), Ct(m); i <= n; ++i) if(Dgr[i] & 1){ 
    if(Lst) {
      Nxt[++Cnt] = E[i], E[i] = Cnt, To[Cnt] = ++Ct;
      Nxt[++Cnt] = E[Lst], E[Lst] = Cnt, To[Cnt] = Ct;
      Add[Ct][0] = Lst, Add[Ct][1] = i, Lst = 0;
    } else Lst = i;
  }
  DFS(1);
//  if(m > 900000) return 0;
  for (unsigned i(1); i <= m; ++i) if(!M[i]) {
    unsigned &L(Dgr[Add[i][0]]), &R(Dgr[Add[i][1]]); 
    if(!(L && R)) M[i] = L = R = 1, ++Tmp;
  }
  printf("%u\n", Tmp);
  for (unsigned i(1); i <= m; ++i) if(M[i]) printf("%u ", i);
//  for (unsigned i(1); i <= m; ++i) if(M[i]) printf("%u %u\n", Add[i][0], Add[i][1]);
//  }
  return Wild_Donkey;
}

