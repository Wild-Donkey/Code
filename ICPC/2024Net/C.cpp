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
unsigned S[300005], Bor[300005], Jump[300005], m, n;
unsigned long long A[300005], B[300005], Ans(0), CurSum(0);
char Deled[300005];
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  S[1] = RD(), A[1] = RD(), B[1] = RD();
  Ans = A[1] * B[1], CurSum = B[1];
  memset(Deled, 1, n + 1);
  printf("%llu\n", Ans);
  for (unsigned i(2); i <= n; ++i) {
    // S[i] = RD(), A[i] = RD(), B[i] = RD();
    S[i] = (Ans + RD()) % n, A[i] = RD(), B[i] = RD();
    if (S[i] != S[Bor[i - 1] + 1]) Jump[i - 1] = Bor[i - 1];
    else Jump[i - 1] = Jump[Bor[i - 1]];
    unsigned Cur(Bor[i - 1]);
    while (Cur && (S[Cur + 1] ^ S[i])) Cur = Bor[Cur];
    if (S[Cur + 1] == S[i]) Bor[i] = Cur + 1;
    if (S[i] == S[1]) CurSum += B[i], Deled[i] = 0;
    Cur = Bor[i - 1];
    while (Cur) {
      // printf("Cur %u\n");
      if (S[i] == S[Cur + 1]) Cur = Jump[Cur];
      else {
        if (!Deled[i - Cur])
          Deled[i - Cur] = 1, CurSum -= B[i - Cur];
        Cur = Bor[Cur];
      }
    }
    // printf("%u\n", CurSum);
    // printf("Bor:\n");
    // for (unsigned i(1); i <= n; ++i) printf("%u ", Bor[i]); putchar(0x0A);
    Ans += CurSum * A[i];
    printf("%llu\n", Ans);
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
g++ C.cpp -O2 -std=c++11
8
1 1 1
2 1 1
1 1 1
2 1 1
1 1 1
3 1 1
1 1 1
2 1 1
*/