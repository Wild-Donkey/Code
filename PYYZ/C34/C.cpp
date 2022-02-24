#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#define Wild_Donkey 0
#define INF 0x3f3f3f3f
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') rdsg = -1, rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0', rdch = getchar();
  return rdtp * rdsg;
}
priority_queue<pair<unsigned, pair<unsigned, unsigned> > > Q;
unsigned long long Ans(0);
unsigned Fa[200005], Stack[200005], STop(0), List[200005];
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(1), Tmp(0);
inline unsigned Find(unsigned x) {
  while (x ^ Fa[x]) Stack[++STop] = x, x = Fa[x];
  while (STop) Fa[Stack[STop--]] = x;
  return x;
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  if (n == 1) { printf("0\n"); return 0; }
  memset(List, 0x3f, (n + 1) << 2);
  for (unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD(), C = RD();
    Q.push({ INF - C ,{A, B} });
    List[A] = min(List[A], ++C);
    List[B] = min(List[B], C + 1);
    List[0] = min(List[0], min(C + ((n - A) << 1), C + 1 + ((n - B) << 1)));
  }
  // for (unsigned i(0); i < n; ++i) printf("%u ", List[i]); putchar(0x0A);
  for (unsigned i(0); i < n; ++i) List[i + 1] = min(List[i] + 2, List[i + 1]);
  for (unsigned i(n - 2); ~i; --i) Q.push({ INF - List[i], {i, i + 1} });
  Q.push({ INF - List[n - 1], {n - 1, 0} });
  for (unsigned i(0); i <= n; ++i) Fa[i] = i;
  while (Cnt < n) {
    A = Find(Q.top().second.second), B = Find(Q.top().second.first), C = INF - Q.top().first, Q.pop();
    if (A ^ B) ++Cnt, Fa[A] = B, Ans += C;
  }
  printf("%llu\n", Ans);
  //  }
  //  system("pause");
  return Wild_Donkey;
}