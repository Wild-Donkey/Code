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
  inline const char operator <(const Query &x) {
    return (this->BelongToBlocks ^ x.BelongToBlocks) ? this->BelongToBlocks < x.BelongToBlocks : this->R < x.R;
  }
}Q[50005];
inline long long GCD(register long long x, register long long y) {
  register long long tmp;
  while(y) {
    tmp = x; 
    x = y;
    y = tmp % y;
  }
  return x;
}
int main() {
  // double Ti(clock()), Mti(0);
//  freopen("P1494_4.in", "r", stdin);
//  freopen("my.out", "w", stdout);
  n = RD(), m = RD();
  BlockLen = sqrt(n) + 1;
//  printf("BlockLen %u\n", BlockLen);
//  BlockCnt = (n + BlockLen - 1) / BlockLen;
  for (register unsigned i(1); i <= n; ++i) {
    a[i] = RD();
  }
  for (register unsigned i(1); i <= m; ++i) {
    Q[i].L = RD(), Q[i].R = RD(), Q[i].Num = i, Q[i].BelongToBlocks = (Q[i].L + BlockLen - 1) / BlockLen;
//    printf("Belong to %u\n", Q[i].BelongToBlocks);
  }
  sort(Q + 1, Q + m + 1);
  Tmp0 = 0, Tmp1 = 1, Q[0].L = 1, Q[0].R = 1;
  Cnt[a[1]] = 1;
  for (register unsigned i(1); i <= m; ++i) {
//    printf("[%u, %u]\n", Q[i].L, Q[i].R);
//    printf("Belong to %u\n", Q[i].BelongToBlocks);
    if(Q[i].L == Q[i].R) {
      Ans[Q[i].Num][0] = 0, Ans[Q[i].Num][1] = 1;
      continue;
    }
//    printf("Before %lld/%lld\n", Tmp0, Tmp1);
    register unsigned Col, Len(Q[i].R - Q[i].L + 1);
    while (Q[0].L > Q[i].L) {   // 左端点左移 
      ++Cnt[Col = a[--Q[0].L]];
      TmpSquare += (Cnt[Col] << 1) - 1;
    }
    while (Q[0].R < Q[i].R) {   // 右端点右移 
      ++Cnt[Col = a[++Q[0].R]];
      TmpSquare += (Cnt[Col] << 1) - 1;
    }
    while (Q[0].L < Q[i].L) {   // 左端点右移
      --Cnt[Col = a[Q[0].L++]]; // 计数数组对应颜色减少
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
//    printf("%u %lld/%lld\n", Q[i].Num, Tmp0, Tmp1);
//    if(!(Ans[Q[i].Num][0] || Ans[Q[i].Num][1])) {
//      printf("Oops %u %u [%u, %u]\n", Q[i].Num, i, Q[i].L, Q[i].R);
//    }
  }
  for (register unsigned i(1); i <= m; ++i) {
    printf("%u/%u\n", Ans[i][0], Ans[i][1]);
  }
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}



