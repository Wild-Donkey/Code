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
unsigned m, n, Cnt[50005], BlockLen, BlockCnt;
long long a[50005], Ans[50005][2], Tmp0(0), Tmp1(1), TmpG, TmpSquare(1);
struct Query{
  unsigned L, R, Num, BelongToBlocks;
  inline const char operator <(const Query &x) {  // 按左端点所在块排序 
    return (this->BelongToBlocks ^ x.BelongToBlocks) ? this->BelongToBlocks < x.BelongToBlocks : this->R < x.R;
  }
}Q[50005];
inline unsigned GCD(register unsigned x, register unsigned y) {
  register unsigned tmp;
  while(y) tmp = x, x = y, y = tmp % y;
  return x;
}
int main() {
  n = RD(), m = RD();
  BlockLen = (m ^ 0) ? (n / sqrt(m)) + 1 : sqrt(n) + 1;
  for (register unsigned i(1); i <= n; ++i) {
    a[i] = RD();
  }
  for (register unsigned i(1); i <= m; ++i) {
    Q[i].L = RD(), Q[i].R = RD(), Q[i].Num = i, Q[i].BelongToBlocks = (Q[i].L + BlockLen - 1) / BlockLen;
  }
  sort(Q + 1, Q + m + 1);
  Tmp0 = 0, Tmp1 = 1, Q[0].L = 1, Q[0].R = 1, Cnt[a[1]] = 1; // 初始化当前区间为 [1, 1] 
  for (register unsigned i(1); i <= m; ++i) {
    if(Q[i].L == Q[i].R) {      // 特判, 单点查询 
      Ans[Q[i].Num][0] = 0, Ans[Q[i].Num][1] = 1;
      continue;
    }
    register unsigned Col, Len(Q[i].R - Q[i].L + 1);
    while (Q[0].L > Q[i].L) {   // 左端点左移 
      ++Cnt[Col = a[--Q[0].L]];
      TmpSquare += (Cnt[Col] << 1) - 1; // Cnt[Col] 增加, 维护方差, 下同 
    }
    while (Q[0].R < Q[i].R) {   // 右端点右移 
      ++Cnt[Col = a[++Q[0].R]];
      TmpSquare += (Cnt[Col] << 1) - 1;
    }
    while (Q[0].L < Q[i].L) {   // 左端点右移
      --Cnt[Col = a[Q[0].L++]];
      TmpSquare -= (Cnt[Col] << 1) + 1;
    }
    while (Q[0].R > Q[i].R) {   // 右端点左移
      --Cnt[Col = a[Q[0].R--]];
      TmpSquare -= (Cnt[Col] << 1) + 1;
    }
    Ans[Q[i].Num][0] = TmpSquare - Len;
    Ans[Q[i].Num][1] = Len * Len - Len;
    TmpG = GCD(Ans[Q[i].Num][0], Ans[Q[i].Num][1]);
    Ans[Q[i].Num][0] /= TmpG;
    Ans[Q[i].Num][1] /= TmpG;
  }
  for (register unsigned i(1); i <= m; ++i) {
    printf("%u/%u\n", Ans[i][0], Ans[i][1]);
  }
  return Wild_Donkey;
}



