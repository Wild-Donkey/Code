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
unsigned m, n, Cnt(0), A, B, t, Ans(0), Dep[50005];
pair<unsigned, unsigned> Fa[50005], C, D;
inline pair<unsigned, unsigned> Find (unsigned x) {
  register unsigned now(x), Val(0);
  while (Fa[now].first ^ now) { // 跳到根 
    Val += Fa[now].second;      // 统计权值和 
    now = Fa[now].first; 
  }
  return Fa[x] = make_pair(now, (Val %= 3));// 取模 
}
int main() {
  freopen("P2024_2.in", "r", stdin);
  n = RD(), m = RD();
  for (register unsigned i(1); i <= n; ++i) { // 初始化 
    Fa[i] = make_pair(i, 0);
  }
  for (register unsigned i(1); i <= m; ++i) {
    if(RD() & 1) { // A equals to B
      A = RD(), B = RD();
      if(A > n || B > n) {  // 超出范围的输入 
        ++Ans;
        continue;
      }
      if(A == B) {          // 我和我自己同类 
        continue;
      }
      C = Find(A), D = Find(B);
      if (C.first ^ D.first) {  // 没有食物关系, 建立关系 
        if (C.second < D.second) {
          Fa[C.first] = make_pair(D.first, (D.second - C.second) % 3);
        } else {
          Fa[D.first] = make_pair(C.first, (C.second - D.second) % 3);
        }
        continue;
      }
      Ans += C.second != D.second;// 食物关系错误
    } else {       // A eat B
      A = RD(), B = RD();
      if(A == B || A > n || B > n) {  // 我吃我自己或超出范围 
        ++Ans;
        continue;
      }
      C = Find(A), D = Find(B);
      if (C.first ^ D.first) {        // 无关系, 建立关系 
        if (C.second + 1 < D.second) {
          Fa[C.first] = make_pair(D.first, (D.second - C.second - 1) % 3);
        } else {
          Fa[D.first] = make_pair(C.first, (C.second - D.second + 1) % 3);
        }
        continue;
      }
      Ans += (C.second + 1) % 3 != D.second;  // 关系错乱 
    }
    printf("i %u ans %u\n", i, Ans);
  }
  printf("%u\n", Ans);
  return Wild_Donkey;
}
