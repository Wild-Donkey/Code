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
#define foreplay for
#define wild while
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
unsigned S[300005], Bor[300005], m, n;
map<unsigned, unsigned> Fa[300005];
unsigned long long A[300005], B[300005], Ans(0), CurSum(0);
char Deled[300005];
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  S[1] = RD(), A[1] = RD(), B[1] = RD(), Bor[1] = 0;
  Ans = A[1] * B[1], CurSum = B[1];
  memset(Deled, 1, n + 1);
  printf("%llu\n", Ans);
  for (unsigned i(2); i <= n; ++i) {
    S[i] = (Ans + RD()) % n, A[i] = RD(), B[i] = RD();
    unsigned Cur(Bor[i - 1]);
    while (Cur && S[Cur + 1] == S[i]) Cur = Bor[Cur];
    if (S[Cur + 1] == S[i]) Bor[i] = Cur + 1;
    if (S[i] == S[1]) CurSum += B[i], Deled[i] = 0;
    Cur = Bor[i - 1];
    while (Cur) {
      if ((S[i] ^ S[Cur + 1]) && (!Deled[i - Cur]))
        Deled[i - Cur] = 1, CurSum -= B[i - Cur];
      Cur = Bor[Cur];
    }
    Ans += CurSum * A[i];
    printf("%llu\n", Ans);
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
g++ C.cpp -O2 -std=c++11
*/