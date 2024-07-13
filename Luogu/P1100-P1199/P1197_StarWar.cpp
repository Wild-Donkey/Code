#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
unsigned m, n, k, A, B;
unsigned Time[400005], Ans[400005], Cnt, Cur;
unsigned Fa[400005], Stack[400005], * Top(Stack);
unsigned Find(unsigned x) {
  while (Fa[x] != x) *(++Top) = x, x = Fa[x];
  while (Top > Stack) Fa[*(Top--)] = x;
  return x;
}
struct Side {
  unsigned S, T, time;
  const char operator<(const Side& x)const { return time > x.time; }
  void Udt() {
    time = min(Time[S], Time[T]);
  }
  void Merge() {
    // printf("Merge %u %u at %u\n", S, T, time);
    unsigned x(Find(S)), y(Find(T));
    if (x == y) return;
    Fa[x] = y, --Cnt;
  }
}Si[200005];
int main() {
  Cnt = n = RD(), m = RD();
  for (unsigned i(0); i < n; ++i)
    Fa[i] = i, Time[i] = 10000000;
  for (unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD();
    Si[i] = { A, B, 10000000 };
  }
  Cur = 1 + (k = RD());
  for (unsigned i(1); i <= k; ++i)
    Time[RD()] = i;
  for (unsigned i(1); i <= m; ++i) Si[i].Udt();
  sort(Si + 1, Si + m + 1);
  for (unsigned i(1); i <= m; ++i) {
    while (Cur > Si[i].time) Ans[Cur--] = Cnt;
    Si[i].Merge();
  }
  while (Cur) Ans[Cur--] = Cnt;
  for (unsigned i(1); i <= k + 1; ++i)
    printf("%u\n", Ans[i] - (i - 1));
  return 0;
}