#include <cmath>
#include <cstdio>
#include <iostream>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp = 0;char rdch(getchar());
  while (rdch < '0' || rdch > '9')rdch = getchar();
  while (rdch >= '0' && rdch <= '9') intmp = intmp * 10 + rdch - '0', rdch = getchar();
  return intmp;
}
unsigned A[100005], B[100005], m, n, q, Ans(0), From[100005], f[100005][400], g[100005][400], BlockLen, BlockNum, Block[100405], Ql, Qr, Stack[100005];
int main() {
  n = RD(), m = RD();
  for (register unsigned i(1); i <= m; ++i) { // 先读进来, 因为求块长需要用 q 
    A[i] = RD(), B[i] = RD();
  }
  q = RD();
  BlockLen = (n / (sqrt(q) + 1)) + 1;       // 理论最优块长 
  BlockNum = (n + BlockLen - 1) / BlockLen; // 块数 
  for (register unsigned i(1); i <= BlockNum; ++i) {
    for (register unsigned j(1); j <= BlockLen; ++j) {
      Block[(i - 1) * BlockLen + j] = i;    // O(n) 预处理 Block 数组 
    }
  }
  for (register unsigned i(1); i <= m; ++i) {
    g[A[i]][Block[B[i]]] = max(g[A[i]][Block[B[i]]], B[i]); // 更新 g[l][Block[r]]
    From[B[i]] = A[i];                                      // 存储 From[r] = l 
  }
  for (register unsigned i(1); i <= n; ++i) {
    g[i][Block[i]] = max(i, g[i][Block[i]]);
    for (register unsigned j(Block[i]); j <= BlockNum; ++j) {
      g[i][j] = max(g[i][j], g[i][j - 1]);                  // 扫一遍 g 数组, 通过单调性处理 g 
    }
  }
  for (register unsigned j(1), Ri; j <= BlockNum; ++j) {
    Ri = j * BlockLen;
    Ri = (Ri > n) ? n : Ri;                         // 终点的最大值 (第 j 块的右界)
    for (register unsigned i(Ri), Hd(0); i >= 1; --i) {
      while(Hd && Stack[Hd] <= g[i][j]) --Hd;       // 弹出队尾 
      if(Stack[Hd + 1] <= g[i][j]) {                // 这个 i 弹出了至少一次队尾 
        f[i][j] = max(f[Stack[Hd + 1]][j], g[i][j]);
      }
      else {                                        // 一次也没弹出 
        f[i][j] = g[i][j];
      }
      Stack[++Hd] = i;
    }
  }
  for (register unsigned i(1), j; i <= q; ++i) {  // 回答询问 
    Ql = RD(), Qr = RD();
    if(Block[Ql] ^ Block[Qr]) {                   // 左右端点在不同块内 
      Ans = f[Ql][Block[Qr] - 1];
      j = ((Block[Qr] - 1) * BlockLen) + 1;
    } else {                                      // 在同一块内 
      Ans = Ql;
      j = Ans + 1;
    }
    while (j <= Qr) {                             // 暴力最后不足一块的部分 
      if(Ql <= From[j] && From[j] <= Ans) {
        Ans = j;
      }
      ++j;
    }
    printf("%u\n", Ans);
  }
  return Wild_Donkey;
}
