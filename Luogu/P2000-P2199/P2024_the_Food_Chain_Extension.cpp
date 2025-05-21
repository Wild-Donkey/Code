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
unsigned m, n, Cnt(0), A, B, C, D, t, Ans(0), Fa[150050];
unsigned Stack[150050], * Top(Stack);
inline unsigned Find(unsigned x) {
  register unsigned now(x);
  while (Fa[now] ^ now) *(++Top) = now, now = Fa[now];
  while (Top > Stack) Fa[*(Top--)] = now;
  return now;
}
int main() {
  n = RD(), m = RD();
  t = n * 3 + 3;  // �ܵ��� 
  for (register unsigned i(1); i <= t; ++i) Fa[i] = i;
  for (register unsigned i(1); i <= m; ++i) {
    D = RD(), A = RD(), B = RD();
    if (A > n || B > n) {
      ++Ans;
      continue;
    }
    if (D & 1) {//A same B
      if (A == B) continue;
      C = Find(A * 3);
      if (C == Find((B * 3) + 1) || C == Find((B * 3) + 2)) {
        ++Ans;
        continue;
      }
      if (C ^ Find(B * 3)) {
        Fa[C] = Fa[B * 3];
        Fa[Find((A * 3) + 1)] = Fa[(B * 3) + 1];
        Fa[Find((A * 3) + 2)] = Fa[(B * 3) + 2];
      }
    } else {// A eat B
      if (A == B) {
        ++Ans;
        continue;
      }
      C = Find(A * 3);
      if (C == Find(B * 3) || C == Find((B * 3) + 2)) {
        ++Ans;
        continue;
      }
      if (C ^ Find((B * 3) + 1)) {
        Fa[C] = Fa[(B * 3) + 1];
        Fa[Find((A * 3) + 2)] = Fa[B * 3];
        Fa[Find((A * 3) + 1)] = Fa[(B * 3) + 2];
      }
    }
  }
  printf("%u\n", Ans);
  return Wild_Donkey;
}
