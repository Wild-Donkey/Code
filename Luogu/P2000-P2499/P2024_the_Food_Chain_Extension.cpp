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
unsigned m, n, Cnt(0), A, B, C, t, Ans(0), Fa[150050];
inline unsigned Find (unsigned x) {
  register unsigned now(x);
  while (Fa[now] ^ now) now = Fa[now];
  return Fa[x] = now; // 路径压缩 
}
int main() {
  n = RD(), m = RD();
  t = n * 3 + 3;  // 总点数 
  for (register unsigned i(1); i <= t; ++i) { // 初始化 
    Fa[i] = i;
  }
  for (register unsigned i(1); i <= m; ++i) {
    if(RD() & 1) {
      A = RD(), B = RD();
      if(A > n || B > n) {
        ++Ans;
        continue;
      }
      if(A == B) {
        continue;
      }
      C = Find(A * 3);
      if (C == Find((B * 3) + 1) || C == Find((B * 3) + 2)) { // A eat B or B eat A 关系错乱 
        ++Ans;
        continue;
      }
      if (C ^ Find(B * 3)) {  // 建立关系 
        Fa[C] = Fa[B * 3];                      // 我的同类的同类是我自己, 将 A 的第一个点和 B 的第一个点合并
        Fa[Find((A * 3) + 1)] = Fa[(B * 3) + 1];// 我的同类的天敌是我的天敌, 将 A 的第二个点和 B 的第二个点合并 
        Fa[Find((A * 3) + 2)] = Fa[(B * 3) + 2];// 我的同类的食物是我的食物, 将 A 的第三个点和 B 的第三个点合并 
      }
    } else {
      A = RD(), B = RD();
      if(A == B || A > n || B > n) {  // 我吃我自己或超出范围
        ++Ans;
        continue;
      }
      C = Find(A * 3);
      if (C == Find(B * 3) || C == Find((B * 3) + 2)) { // A 是 B 的同类或食物, 关系错乱 
        ++Ans;
        continue;
      }
      if (C ^ Find((B * 3) + 1)) {  // 建立关系 
        Fa[C] = Fa[(B * 3) + 1];                // 我的食物的天敌是我自己, 将 A 的第一个点和 B 的第二个点合并
        Fa[Find((A * 3) + 2)] = Fa[B * 3];      // 我的食物的同类是我的食物, 将 A 的第三个点和 B 的第一个点合并
        Fa[Find((A * 3) + 1)] = Fa[(B * 3) + 2];// 我的食物的食物是我的天敌, 将 A 的第二个点和 B 的第三个点合并
      }
    }
  }
  printf("%u\n", Ans);
  return Wild_Donkey;
}
