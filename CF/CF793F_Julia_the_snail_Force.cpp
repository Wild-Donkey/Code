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
unsigned a[10005], m, n, q, Cnt(0), A, B, C, D, t, Ans[100005], Tmp(0), NowRi(0), To, From[100005];
struct Node {
  Node *Son[2];
  unsigned Val, TagMax; 
}N[100005];
struct Rope {
  unsigned L, R;
  inline const char operator < (const Rope &x) const {
    return this->R < x.R;
  }
}R[100005];
struct Qry {
  unsigned L, R, Num;
  inline const char operator < (const Qry &x) const {
    return this->R < x.R;
  }
}Q[100005];
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(); 
  for (register unsigned i(1); i <= m; ++i) {
    R[i].L = RD(), R[i].R = RD(); 
    From[R[i].R] = R[i].L;
  }
  sort(R + 1, R + m + 1);
  q = RD(); 
  for (register unsigned i(1); i <= q; ++i) {
    Q[i].L = RD(), Q[i].R = RD(), Q[i].Num = i;
  }
  sort(Q + 1, Q + q + 1);
  for (register unsigned i(1), j; i <= q; ++i) {
    j = Q[i].L + 1;
    Ans[0] = Q[i].L;
    while (j <= Q[i].R) {
      if(Q[i].L <= From[j] && From[j] <= Ans[0]) {
        Ans[0] = j;
      }
      ++j;
    }
    Ans[Q[i].Num] = Ans[0];
  }
  for (register unsigned i(1); i <= q; ++i) {
    printf("%u\n", Ans[i]);
  }
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}



