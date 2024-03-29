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
  unsigned intmp = 0;
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') {
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) {
    rdch = getchar();
  }
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = rdtp * 10 + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned Fa[4005], m, n, N, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
char flg(0);
inline void Clr() {
  n = RD(), m = RD();
  N = (n << 1) + 1;
  for (register unsigned i(1); i <= N; ++i) {
    Fa[i] = i;
  }
  flg = 0;
}
inline unsigned Find(const unsigned &x) {
  register unsigned now(x);
  while (now ^ Fa[now]) now = Fa[now];
  return Fa[x] = now;
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  t = RD();
  for (register unsigned T(1); T <= t; ++T){
    Clr();
    printf("Scenario #%u:\n", T);
    for (register unsigned i(1); i <= m; ++i) {
      A = RD(), B = RD();
      if(flg) continue;
      if(Find(A << 1) == Find(B << 1)) {
        flg = 1;
        continue;
      }
      Fa[Fa[A << 1]] = Find((B << 1) + 1);
      Fa[Fa[B << 1]] = Find((A << 1) + 1);
    }
    printf(flg ? "Suspicious bugs found!\n" : "No suspicious bugs found!\n");
  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
