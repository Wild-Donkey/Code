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
unsigned m, n, Cnt(0), A, B, t, Ans(0);
pair<unsigned, unsigned> Fa[50005], Stack[50005], * Top(Stack), C, D;
inline pair<unsigned, unsigned> Find(unsigned x) {
  unsigned now(x), Val(0);
  while (Fa[now].first ^ now) {
    *(++Top) = { now, Fa[now].second };
    now = Fa[now].first;
  }
  while (Top > Stack) {
    Val = (Val + Top->second) % 3;
    Fa[Top->first] = { now, Val };
    --Top;
  }
  return { now, Val };
}
int main() {
  // freopen("P2024_2.in", "r", stdin);
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i)
    Fa[i] = { i, 0 };
  for (unsigned i(1); i <= m; ++i) {
    t = RD(), A = RD(), B = RD();
    if (A > n || B > n) {
      ++Ans;
      continue;
    }
    C = Find(A), D = Find(B);
    // printf("C (%u,%u) D(%u,%u)\n", C.first, C.second, D.first, D.second);
    if (t & 1) { // A equals to B
      if (A == B) continue;
      if (C.first ^ D.first) {
        if (C.second < D.second)
          Fa[C.first] = make_pair(D.first, D.second - C.second);
        else
          Fa[D.first] = make_pair(C.first, C.second - D.second);
        continue;
      }
      Ans += C.second != D.second;
    } else {       // A eat B
      if (A == B) {
        ++Ans;
        continue;
      }
      if (C.first ^ D.first) {
        if (C.second + 1 < D.second)
          Fa[C.first] = make_pair(D.first, D.second - C.second - 1);
        else
          Fa[D.first] = make_pair(C.first, (C.second - D.second + 1) % 3);
        continue;
      }
      Ans += (C.second + 1) % 3 != D.second;
    }
  }
  printf("%u\n", Ans);
  return Wild_Donkey;
}
