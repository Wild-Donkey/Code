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
unsigned a[10005], A, B, m, n, q, Cnt(0), Ans[100005], Tmp(0), NowRi(0), To, From[100005], f[100005][400], BlockLen, BlockNum, Block[100005];
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
struct To {
  unsigned Dest;
  To *Nxt;
}T[100005], *CntTo, *Out[100005];
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  BlockLen = sqrt(n);
  BlockNum = (n + BlockLen - 1) / BlockLen;
  for (register unsigned i(1); i <= BlockNum; ++i) {
    for (register unsigned j(1); j <= BlockLen; ++j) {
      Block[(i - 1) * BlockLen + j] = i;
    }
  }
  for (register unsigned i(1); i <= m; ++i) {
    R[i].L = RD(), R[i].R = RD();
  }
  sort(R + 1, R + m + 1);
  for (register unsigned i(1); i <= m; ++i) {
    (++CntTo)->Nxt = Out[R[i].L];
    Out[R[i].L] = CntTo;
    CntTo->Dest = R[i].R; 
    From[R[i].L] = R[i].R;
  }
  q = RD(); 
  for (register unsigned i(1); i <= q; ++i) {
    Q[i].L = RD(), Q[i].R = RD(), Q[i].Num = i;
  }
  for (register unsigned i(1); i <= n; ++i) {
    Ans[0] = i;
    for (register unsigned j((i + BlockLen - 1) / BlockLen), Ri, k(i + 1); j <= BlockNum; ++j) {
      Ri = j * BlockLen;
      Ri = (Ri > n) ? n : Ri;
      while (Out[i]->Nxt->Dest <= Ri) {
        Out[i] = Out[i]->Nxt;
      }
      g[i][j] = Out[i]->Dest;
    }
  }
  for (register unsigned j(BlockNum), Ri; j >= 1; --j) {
    Ri = j * BlockLen;
    Ri = (Ri > n) ? n : Ri;
    for (register unsigned i())
  }
  for (register unsigned i(1), j; i <= q; ++i) {
    if(Block[Q[i].L] ^ Block[Q[i].R]) {
      Ans[0] = f[Q[i].L][Block[Q[i].R] - 1];
      j = ((((Q[i].R + 1) / BlockLen) - 1) * BlockLen) + 1;
    } else {
      Ans[0] = Q[i].L;
      j = Ans[0] + 1;
    }
    while (j <= Q[i].R) {
      if(Q[i].L <= From[j] && From[j] <= Ans[0]) {
        Ans[0] = j;
      }
      ++j;
    }
    printf("%u\n", Ans[0]);
  }
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}



