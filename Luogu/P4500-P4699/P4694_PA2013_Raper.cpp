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
long long Ans, LA(0), RA;
unsigned a[500005], b[500005], m, n;
unsigned L(0), R, B, AL(0), AR(2000000005), A;
unsigned Cnt(0);
inline long long Judge() {
  long long f[n + 2];
  priority_queue<unsigned> Q, Qa;
  f[n + 1] = B = 0, Qa.push(0);
  for (unsigned i(n); i; --i) {
    Q.push(b[i]);
    long long Tmp(f[i + 1] + 0x3f3f3f3f - Q.top() + a[i] - A);
    if (Tmp < f[i + 1] - max((int)Qa.top() - (int)a[i], 0)) Q.pop(), f[i] = Tmp, ++B, Qa.push(a[i]);
    else { f[i] = f[i + 1]; if (a[i] < Qa.top()) f[i] -= Qa.top() - a[i], Qa.push(a[i]), Qa.pop(); }
    // printf("%u %lld %lld\n", i, f[i], Tmp);
  }
  return f[1] + (long long)B * A;
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  R = n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) RA = a[i] = RD();
  for (unsigned i(1); i <= n; ++i) RA = b[i] = RD();
  for (unsigned i(1); i <= n; ++i) b[i] = 0x3f3f3f3f - b[i];
  while (AL <= AR) {
    A = ((AL + AR) >> 1), Ans = Judge();
    // printf("[%u, %u] %u (%u, %lld)\n", AL, AR, A, B, Ans);
    if (B == m) { printf("%lld\n", Ans)/*, system("pause")*/; return 0; }
    if (B > m) AR = A - 1, RA = ((R > B) ? Ans : min(RA, Ans)), R = B;
    else AL = A + 1, LA = ((L < B) ? Ans : min(LA, Ans)), L = B;
  }
  // printf("[%u %u] %lld %lld\n", L, R, LA, RA);
  printf("%lld\n", LA + ((RA - LA) / (R - L) * (m - L)));
  //  }
  // system("pause");
  return Wild_Donkey;
}
/*
8 4
3 8 7 9 9 4 6 8
2 5 9 4 3 8 9 1
*/