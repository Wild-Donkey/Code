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
inline long long RDsg() {
  long long rdtp(0), rdsg(1);
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
struct Station {
  long long Address, Price;
  const bool operator <(const Station &x) const {
    return this->Address < x.Address;
  }
}S[100005];
unsigned n, A, B, C, D;
long long Ans(0), FinalAns(0x3f3f3f3f3f3f3f3f), Mn, Tmp, f[100005], s, t;
inline void Clr() {}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  s = RDsg();
  t = RDsg();
  for (register unsigned i(1); i <= n; ++i) {
    S[i].Price = RDsg();
    S[i].Address = RDsg();
  }
  sort (S + 1, S + n + 1);
  while (S[n].Address > t) {
    --n;
  }
  A = 1;
  while (S[A].Address < s) {
    ++A;
  }
  f[A] = 0;
  for (register unsigned i(A - 1); i > 0; --i) {
    f[i] = 0x3f3f3f3f3f3f3f3f;
    for (register unsigned j(i + 1); j <= A; ++j) {
      f[i] = min(f[i], f[j] + (long long)S[j].Price * (S[j].Address - S[i].Address));
//      printf("%u %u %lld\n", i, j, f[i]);
    }
  }
  for (register unsigned i(1); i <= A; ++i) {
    if(S[i].Price < S[A].Price || i == A) {
      Tmp = t - s;
      f[i] = f[i] + (long long)(S[A].Address - S[i].Address) * S[i].Price;
      Mn = S[i].Price;
      Ans = S[i].Price * Tmp + f[i];
      for (register unsigned j(A + 1); j <= n; ++j) {
        Tmp -= S[j].Address - S[j - 1].Address;
        if(S[j].Price < Mn) {
          Ans -= Tmp * (Mn - S[j].Price);
          Mn = S[j].Price;
        }
      }
      FinalAns = min(FinalAns, Ans);
    }
//    printf("%u %lld\n", i, Ans);
  }
  printf("%lld", FinalAns);
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
/*
12 2 100000000
43287643 -432412332
87654511 434213521
87631522 123212389
12876511 143323123
32876443 -936312323
12397973 312133333
32397973 312133333
92397973 312133333
44324322 -621432322
21312313 -132343233
31876668 2
63553890 -765322333
*/
