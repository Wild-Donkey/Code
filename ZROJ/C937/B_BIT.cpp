#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#define Wild_Donkey 0
#define Lowbit(x) ((x)&((~x)+1))
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
int a[100005], m;
unsigned BIT[100005], InvSum[100005];
long long Sum[100005], TmpSum[100005], Min;
unsigned long long A, Pls[15], Ans;
unsigned n, Cnt, PCnt[15], Pos;
inline void Clr() {
  memset(BIT, 0, (n + 1) << 2);
  if ((m > 0) && (m <= 10)) memset(Pls, 0, m << 3), memset(PCnt, 0, m << 2);
  n = RD(), Ans = 0, Min = 0x3f3f3f3f3f3f3f3f;
}
int main() {
  for (Clr();n; Clr()) {
    for (unsigned i(1); i <= n; ++i) { Sum[i] = Sum[i - 1] + (a[i] = RDsg()); if (Sum[i] < Min) Min = Sum[i], Pos = i; }
    if (Sum[n] <= 0) { printf("-1\n");continue; }
    for (unsigned i(1); i <= n; ++i) TmpSum[i] = Sum[i] = Sum[i - 1] + a[(Pos + i > n) ? (Pos + i - n) : (Pos + i)];
    sort(Sum + 1, Sum + n + 1, greater<long long>());
    for (unsigned i(1); i <= n; ++i) InvSum[i] = lower_bound(Sum + 1, Sum + n + 1, TmpSum[i], greater<long long>()) - Sum;
    for (unsigned i(1); i <= n; ++i) {
      for (unsigned j(InvSum[i] - 1); j; j -= Lowbit(j)) Ans += BIT[j];
      for (unsigned j(InvSum[i]); j <= n; j += Lowbit(j)) ++BIT[j];
    }
    Sum[n + 1] = 0x3f3f3f3f3f3f3f3f, Cnt = 1, m = TmpSum[n];
    for (unsigned i(1); i <= n; ++i, ++Cnt) {
      if (Sum[i] ^ Sum[i + 1]) {
        Pos = Sum[i] % m, A = Sum[i] / m;
        for (unsigned j(0); j < m; ++j) Ans += (Pls[j] - PCnt[j] * (A + ((Pos < j) ? 0 : 1))) * Cnt;
        Pls[Pos] += Cnt * A, PCnt[Pos] += Cnt, Cnt = 0;
      }
    }
    printf("%llu\n", Ans);
  }
  return Wild_Donkey;
}