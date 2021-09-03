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
unsigned SA[500005], RK[500005], ScdRk[500005], Bucket[500005], RkTmp[1000005];
unsigned ST[20][500005], Bin[20], Log[500005], f[500005];
unsigned m, n, Cnt(0), A, B, C, D, t, Ans(0), Final(1), Tmp(0);
char aP[500010], * a(aP);
unsigned Min(const unsigned L, const unsigned R) {
  unsigned LenLog(Log[R - L + 1]);
  return min(ST[LenLog][L], ST[LenLog][R - Bin[LenLog] + 1]);
}
struct Node {
  Node* LS, * RS;
  unsigned Val;
  void Add(unsigned L, unsigned R) {
    // printf("Add [%u, %u] for %u by %u Pos Before %u\n", L, R, A, B, SA[A]);
    if (L == R) { this->Val = B;return; }
    unsigned Mid((L + R) >> 1);
    if (A <= Mid) this->LS->Add(L, Mid);
    else this->RS->Add(Mid + 1, R);
    this->Val = max(this->LS->Val, this->RS->Val);
  }
  void Qry(unsigned L, unsigned R) {
    if ((A <= L) && (R <= B)) { Ans = max(Ans, this->Val); return; }
    unsigned Mid((L + R) >> 1);
    if (A <= Mid) this->LS->Qry(L, Mid);
    if (Mid < B) this->RS->Qry(Mid + 1, R);
  }
}N[1000005], * CntN(N);
void Build(Node* x, unsigned L, unsigned R) {
  if (L == R) { return; }
  unsigned Mid((L + R) >> 1);
  Build(x->LS = (++CntN), L, Mid), Build(x->RS = (++CntN), Mid + 1, R);
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  fread(aP + 1, 1, n + 5, stdin), Build(N, 1, n);
  while (a[1] < 'a') ++a;
  for (unsigned i(1); i <= n; ++i) ++Bucket[RK[i] = (a[i] -= '`')];
  for (unsigned i(1); i <= 26; ++i) Bucket[i] += Bucket[i - 1];
  for (unsigned i(1); i <= n; ++i) SA[Bucket[RK[i]]--] = i;
  for (unsigned i(1), BucketSize(26); i <= n; i <<= 1) {
    memset(Bucket, 0, (BucketSize + 1) << 2);
    for (unsigned j(1); j <= n; ++j) ++Bucket[RK[j]];
    for (unsigned j(1); j <= BucketSize; ++j) Bucket[j] += Bucket[j - 1];
    for (unsigned j(n - i + 1); j <= n; ++j) ScdRk[j] = j;
    for (unsigned j(1), TopSR(n - i + 1); j <= n; ++j) if (SA[j] > i) ScdRk[--TopSR] = SA[j] - i;
    for (unsigned j(1); j <= n; ++j) SA[Bucket[RK[ScdRk[j]]]--] = ScdRk[j];
    memcpy(RkTmp, RK, (n + 1) << 2), BucketSize = 0;
    for (unsigned j(1); j <= n; ++j) RK[SA[j]] = ((RkTmp[SA[j]] ^ RkTmp[SA[j - 1]]) || (RkTmp[SA[j] + i] ^ RkTmp[SA[j - 1] + i])) ? (++BucketSize) : (BucketSize);
    if (BucketSize == n) break;
  }
  for (unsigned i(1), j(0); i <= n; ++i) {
    if (RK[i] == 1) ST[0][1] = 0;
    if (j) --j;
    while (a[i + j] == a[SA[RK[i] - 1] + j]) ++j;
    ST[0][RK[i]] = j;
  }
  for (unsigned i(1), j(0); i <= n; i <<= 1, ++j)
    for (unsigned k(1); k + (i << 1) - 1 <= n; ++k)
      ST[j + 1][k] = min(ST[j][k], ST[j][k + i]);
  for (unsigned i(1), j(0); i <= n; i <<= 1, ++j) Bin[j] = i, Log[i] = j;
  for (unsigned i(1); i <= n; ++i) Log[i] = max(Log[i], Log[i - 1]);
  // printf("Height\n");
  // for (unsigned i(1); i <= n; ++i) printf("%u ", ST[0][i]);
  // putchar('\n');
  // printf("SA\n");
  // for (unsigned i(1); i <= n; ++i) printf("%u ", SA[i]);
  // putchar('\n');
  for (unsigned i(n), j(0), Right(n + 1); i; --i, ++j) {
    while (j) {
      unsigned BL(1), BR(RK[i]), BMid;
      while (BL < BR) {
        BMid = (BL + BR) >> 1;
        if (Min(BMid, RK[i]) >= j) BR = BMid;
        else BL = BMid + 1;
      }
      A = (ST[0][BL] >= j) ? (BL - 1) : (BL), BL = RK[i] + 1, BR = n;
      while (BL < BR) {
        BMid = (BL + BR + 1) >> 1;
        if (Min(RK[i] + 1, BMid) >= j) BL = BMid;
        else BR = BMid - 1;
      }
      B = (ST[0][BL] >= j) ? (BL) : (BL - 1);
      // printf("Num %u [Qry %u, %u]\n", i, A, B);
      Ans = 0, N->Qry(1, n);
      if (Ans >= j) { Final = max(Final, f[i] = j + 1); break; }
      BL = 1, BR = RK[i + 1];
      while (BL < BR) {
        BMid = (BL + BR) >> 1;
        if (Min(BMid, RK[i + 1]) >= j) BR = BMid;
        else BL = BMid + 1;
      }
      A = (ST[0][BL] >= j) ? (BL - 1) : (BL), BL = RK[i + 1] + 1, BR = n;
      while (BL < BR) {
        BMid = (BL + BR + 1) >> 1;
        if (Min(RK[i + 1] + 1, BMid) >= j) BL = BMid;
        else BR = BMid - 1;
      }
      B = (ST[0][BL] >= j) ? (BL) : (BL - 1);
      // printf("Num %u [Qry %u, %u]\n", i, A, B);
      Ans = 0, N->Qry(1, n);
      if (Ans >= j) { Final = max(Final, f[i] = j + 1); break; }
      A = RK[i + j], B = f[i + j], --j, N->Add(1, n);
    }
    if (!f[i]) f[i] = 1;
  }
  printf("%u\n", Final);
  // system("pause");
  return Wild_Donkey;
}
/*
503
abbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbabaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaababbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbabaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaababbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbabaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababb
218
bbaabbabaabbaababbabaababbaabbabaababbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbabaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababb
185
ababbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbabaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababb
139
baababbabaabbaababbaabbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbabaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababb
95
abbabaabbaababbaabbabaababbabaabbaababbabaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababb
71
abbabaabbaababbabaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababb
57
babaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababb
*/