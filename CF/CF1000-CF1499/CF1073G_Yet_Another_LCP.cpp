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
unsigned ScdRk[200005], Bucket[200005], SA[200005], RK[200005];
unsigned RkTmp[400005], ST[18][200005], m, n;
unsigned SzA, SzB, A[200005], B[200005], C, D;
unsigned Bin[20], Log[200005];
unsigned long long Ans(0);
char a[200005];
struct Node {
  Node* LS, * RS;
  unsigned long long Sum, Cnt;
  void Udt() {
    this->Sum = this->LS->Sum + this->RS->Sum;
    this->Cnt = this->LS->Cnt + this->RS->Cnt;
  }
  void PsDw() { if (!this->Cnt) this->LS->Cnt = this->RS->Cnt = this->LS->Sum = this->RS->Sum = 0; }
  void Add(unsigned L, unsigned R) {
    // printf("Add [%u, %u]\n", L, R);
    if (L == R) {
      (this->Cnt) += D;
      this->Sum = this->Cnt * L;
      return;
    }
    this->PsDw();
    register unsigned Mid((L + R) >> 1);
    if (C <= Mid) { this->LS->Add(L, Mid); }
    else { this->RS->Add(Mid + 1, R); }
    this->Udt();
  }
  void QryDel(unsigned L, unsigned R) {
    // printf("QryDel %u in [%u, %u]\n", C, L, R);
    if (L > C) {
      D += this->Cnt;
      this->Cnt = this->Sum = 0;
      return;
    }
    this->PsDw();
    register unsigned Mid((L + R) >> 1);
    if (Mid > C) this->LS->QryDel(L, Mid);
    this->RS->QryDel(Mid + 1, R);
  }
}N[400005], * CntN(N);
void Build(Node* x, unsigned L, unsigned R) {
  if (L == R) { return; }
  register unsigned Mid((L + R) >> 1);
  Build(x->LS = ++CntN, L, Mid);
  Build(x->RS = ++CntN, Mid + 1, R);
  // x->Udt();
}
inline unsigned Min(unsigned L, unsigned R) {
  register unsigned LenLog(Log[R - L + 1]);
  return min(ST[LenLog][L], ST[LenLog][R - Bin[LenLog] + 1]);
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  scanf("%s", a + 1);
  for (register unsigned i(1); i <= n; ++i)
    ++Bucket[RK[i] = (a[i] - 'a' + 2)];
  for (register unsigned i(1); i <= 27; ++i)
    Bucket[i] += Bucket[i - 1];
  for (register unsigned i(1); i <= n; ++i)
    SA[Bucket[RK[i]]--] = i;
  for (register unsigned i(1), BucketTop(27); i <= n; i <<= 1) {
    for (register unsigned j(n - i + 1); j <= n; ++j) ScdRk[j] = j;
    for (register unsigned j(1), Top(n - i + 1); j <= n; ++j)
      if (SA[j] > i) ScdRk[--Top] = SA[j] - i;
    memset(Bucket, 0, (BucketTop + 1) << 2);
    for (register unsigned j(1); j <= n; ++j)
      ++Bucket[RK[j]];
    for (register unsigned j(1); j <= BucketTop; ++j)
      Bucket[j] += Bucket[j - 1];
    for (register unsigned j(1); j <= n; ++j)
      SA[Bucket[RK[ScdRk[j]]]--] = ScdRk[j];
    BucketTop = 0;
    memcpy(RkTmp, RK, (n + 1) << 2);
    for (register unsigned j(1); j <= n; ++j)
      RK[SA[j]] = ((RkTmp[SA[j]] ^ RkTmp[SA[j - 1]]) || (RkTmp[SA[j] + i] ^ RkTmp[SA[j - 1] + i])) ? (++BucketTop) : BucketTop;
    // printf("SA Round log(%u)\n", i);
    // for (register unsigned j(1); j <= n; ++j) printf("%u ", SA[j]);
    // putchar('\n');
    // for (register unsigned j(1); j <= n; ++j) printf("%u ", RkTmp[j]);
    // putchar('\n');
    if (BucketTop == n) break;
  }
  // for (register unsigned i(1); i <= n; ++i) printf("%u ", SA[i]);
  // putchar('\n');
  // for (register unsigned i(1); i <= n; ++i) {
  //   for (register unsigned j(SA[i]); j <= n; ++j) {
  //     putchar(a[j]);
  //   }
  //   putchar('\n');
  // }
  for (register unsigned i(1), j, H(1); i <= n; ++i) {
    if (RK[i] == 1) { ST[0][RK[i]] = 0; continue; }
    j = SA[RK[i] - 1];if (H) --H;
    while ((a[i + H] == a[j + H]) && (i + H <= n) && (j + H <= n)) ++H;
    ST[0][RK[i]] = H;
  }
  // printf("Height\n");
  // for (register unsigned i(1); i <= n; ++i) printf("%u ", ST[0][i]);
  // putchar('\n');
  // printf("Height\n");
  // for (register unsigned i(1); i <= n; ++i) printf("%u ", ST[0][RK[i]]);
  // putchar('\n');
  for (register unsigned i(1), j(0); i <= n; i <<= 1, ++j)
    Bin[j] = i, Log[i] = j;
  for (register unsigned i(1); i <= n; ++i)
    Log[i] = max(Log[i], Log[i - 1]);
  for (register unsigned i(1), j(0); i <= n; i <<= 1, ++j)
    for (register unsigned k(1); k + (i << 1) <= n + 1; ++k)
      ST[j + 1][k] = min(ST[j][k], ST[j][k + i]);
  B[0] = -1, A[0] = -1, Build(N, 0, n);
  for (register unsigned i(1); i <= m; ++i) {
    SzA = RD(), SzB = RD(), Ans = 0;
    for (register unsigned i(1); i <= SzA; ++i) A[i] = RK[RD()];
    for (register unsigned i(1); i <= SzB; ++i) B[i] = RK[RD()];
    // printf("A:");
    // for (register unsigned i(1); i <= SzA; ++i) printf("%u ", A[i]);
    // printf("\nB:");
    // for (register unsigned i(1); i <= SzB; ++i) printf("%u ", B[i]);
    // putchar('\n');
    sort(A + 1, A + SzA + 1), sort(B + 1, B + SzB + 1);
    for (register unsigned i(1), j(1); j <= SzB; ++j) {
      C = Min(B[j - 1] + 1, B[j]), D = 0, N->QryDel(0, n), N->Add(0, n);
      // printf("Del Min[%u,  %u] %u\n", B[j - 1] + 1, B[j], C);
      while ((A[i] <= B[j]) && (i <= SzA)) {
        C = ((A[i] ^ B[j]) ? (Min(A[i] + 1, B[j])) : (n - SA[A[i]] + 1)), D = 1, N->Add(0, n);
        // printf("Add A[%u]=%u %u\n", i, A[i], C);
        ++i;
      }
      Ans += N->Sum;
    }
    C = 0, N->QryDel(0, n);
    for (register unsigned i(1), j(1); j <= SzA; ++j) {
      C = Min(A[j - 1] + 1, A[j]), D = 0, N->QryDel(0, n), N->Add(0, n);
      // printf("Del2 Min[%u,  %u] %u\n", A[j - 1] + 1, A[j], C);
      while ((B[i] < A[j]) && (i <= SzB)) {
        C = Min(B[i] + 1, A[j]), D = 1, N->Add(0, n);
        // printf("Add2 B[%u]=%u %u\n", i, B[i], C);
        ++i;
      }
      Ans += N->Sum;
    }
    printf("%llu\n", Ans);
  }
  // system("pause");
  return Wild_Donkey;
}
/*
6 2
banana
6 4 2 1 5 3
*/