#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <string>
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
unsigned long long Ans(0), Tmp(0), Increase[100005][27], Reduce[2][100005];
const unsigned long long Base(29), Mod(998244353);
unsigned HashPre[100005], HashPro[100005], Power[100005];
unsigned n(0), m, A, B, C, D, t, Num(0);
unsigned Change[2][100005];
unsigned f1[100005], f2[100005];
char a[100005], GChar, Flg(0);
unsigned Hash(unsigned x, unsigned y) { return (Mod + HashPre[y] - ((unsigned long long)HashPre[x - 1] * Power[y - x + 1] % Mod)) % Mod; }
unsigned DeHash(unsigned x, unsigned y) { return (Mod + HashPro[x] - ((unsigned long long)HashPro[y + 1] * Power[y - x + 1] % Mod)) % Mod; }
unsigned Palindrome(unsigned x, unsigned y) {
  unsigned L(0), R(min(x, n - y + 1)), Mid;
  while (L ^ R) {
    Mid = ((L + R + 1) >> 1), Flg = 0;
    if (DeHash(x - Mid + 1, x) ^ Hash(y, y + Mid - 1))  R = Mid - 1;
    else L = Mid;
  }
  return L;
}
signed main() {
  //  freopen(".in", "r", stdin);
  // freopen("D.out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  GChar = getchar();
  while (GChar < 'a') GChar = getchar();
  while (GChar >= 'a') a[++n] = GChar - '`', GChar = getchar();
  a[0] = 'A', Power[0] = 1;
  for (unsigned i(1); i <= n; ++i) Power[i] = Power[i - 1] * Base % Mod;
  for (unsigned i(1); i <= n; ++i) HashPre[i] = ((HashPre[i - 1] * Base) + a[i]) % Mod;
  for (unsigned i(n); i; --i) HashPro[i] = ((HashPro[i + 1] * Base) + a[i]) % Mod;
  for (unsigned i(1); i <= n; ++i) Ans += f1[i] = Palindrome(i, i);
  for (unsigned i(2); i <= n; ++i) Ans += f2[i] = Palindrome(i - 1, i);
  for (unsigned i(1), j; i <= n; ++i) {
    if ((f1[i] < i) && (f1[i] + i <= n)) {
      Increase[i - f1[i]][a[i + f1[i]]] += 1 + (j = Palindrome(i - f1[i] - 1, i + f1[i] + 1));
      Increase[i + f1[i]][a[i - f1[i]]] += 1 + j;
    }
  }
  for (unsigned i(2), j; i <= n; ++i) {
    if ((f2[i] + 1 < i) && (f2[i] + i <= n)) {
      Increase[i - f2[i] - 1][a[i + f2[i]]] += 1 + (j = Palindrome(i - f2[i] - 2, i + f2[i] + 1));
      Increase[i + f2[i]][a[i - f2[i] - 1]] += 1 + j;
    }
  }
  for (unsigned i(1); i <= n; ++i) ++Change[0][i - f1[i] + 1], --Change[0][i];
  for (unsigned i(1); i <= n; ++i) ++Change[0][i - f2[i]], --Change[0][i];
  for (unsigned i(1); i <= n; ++i) Change[0][i] += Change[0][i - 1];
  for (unsigned i(1); i <= n; ++i) ++Change[1][i + f1[i] - 1], --Change[1][i];
  for (unsigned i(1); i <= n; ++i) ++Change[1][i + f2[i] - 1], --Change[1][i - 1];
  for (unsigned i(n); i; --i) Change[1][i] += Change[1][i + 1];
  for (unsigned i(1); i <= n; ++i) Reduce[0][i] = Reduce[0][i - 1] + Change[0][i] - f1[i] - f2[i] + 1;
  for (unsigned i(n); i; --i) Reduce[1][i] = Reduce[1][i + 1] + Change[1][i] - f1[i] - f2[i + 1] + 1;
  for (unsigned i(1); i <= n; ++i) {
    unsigned long long Max(0);
    for (unsigned j(1); j <= 26; ++j) Max = max(Max, Increase[i][j]);
    // printf("Increase[%u] %u\n", i, Max);
    if (Max > Reduce[0][i] + Reduce[1][i]) Tmp = max(Tmp, Max - Reduce[0][i] - Reduce[1][i]);
  }
  printf("%llu\n", Ans + Tmp);
  return Wild_Donkey;
}
/*
egegbanananeblasssnqxylgwzzzaaadabcddcbadaaaaaaaaaaaadzzzwglyxqnsssalbenananabgege
*/