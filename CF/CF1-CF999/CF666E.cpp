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
unsigned ST[20][600005], Bin[20], Log[600005], ScdRk[600005];
unsigned Bucket[600005], SA[600005], RK[600005], RkTmp[1200005];
unsigned a[50005], BNum[600005], Cnt[50005], AnsN[500005], AnsC[500005];
unsigned m, n, q, A, B, C, D, t, Tmp(0), BlcL, BlcL2;
unsigned AnsBuc[230], BlcCnt[230][50005];
char S[600005];
struct Qry {
  unsigned L, R, RL, RR, Bl, Num;
  inline const char operator< (const Qry& x) const { return (this->Bl ^ x.Bl) ? (this->Bl < x.Bl) : (this->L < x.L); }
}Q[500005];
inline unsigned Min(unsigned L, unsigned R) {
  register unsigned LenLog(Log[R - L + 1]);
  return min(ST[LenLog][L], ST[LenLog][R - Bin[LenLog] + 1]);
}
inline void Add(unsigned x) {
  if (!x) return;
  register unsigned BlcN(x / BlcL2);
  // printf("Add %u %u\n", x, BlcN);
  --BlcCnt[BlcN][Cnt[x]];
  if (++Cnt[x] > AnsBuc[BlcN]) ++AnsBuc[BlcN];
  ++BlcCnt[BlcN][Cnt[x]];
  // printf("Add Ans to %u\n", AnsBuc[BlcN]);
}
inline void Del(unsigned x) {
  if (!x) return;
  register unsigned BlcN(x / BlcL2);
  // printf("Del %u %u\n", x, BlcN);
  --BlcCnt[BlcN][Cnt[x]];
  if (!BlcCnt[BlcN][Cnt[x]]) if ((Cnt[x]) == AnsBuc[BlcN]) --AnsBuc[BlcN];
  ++BlcCnt[BlcN][--Cnt[x]];
  // printf("Del Ans to %u\n", AnsBuc[BlcN]);
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  a[0] = 1;
  scanf("%s", S + 1), a[1] = strlen(S + 1) + 1;
  n = RD();
  for (register unsigned i(1); i <= n; ++i) {
    S[a[i]] = '`';
    scanf("%s", S + a[i] + 1);
    a[i + 1] = a[i] + strlen(S + a[i] + 1) + 1;
  }
  // printf("%s\n", S + 1);
  m = a[n + 1] - 1, BlcL2 = sqrt(n) + 1;
  for (register unsigned i(1); i <= m; ++i) ++Bucket[RK[i] = (S[i] -= '_')];
  for (register unsigned i(1); i <= 27; ++i) Bucket[i] += Bucket[i - 1];
  for (register unsigned i(1); i <= m; ++i) SA[Bucket[RK[i]]--] = i;
  for (register unsigned i(1), BucketSize(27); i <= m; ++i) {
    memset(Bucket, 0, (BucketSize + 1) << 2);
    for (register unsigned j(1); j <= m; ++j) ++Bucket[RK[j]];
    for (register unsigned j(1); j <= BucketSize; ++j) Bucket[j] += Bucket[j - 1];
    for (register unsigned j(m - i + 1); j <= m; ++j) ScdRk[j] = j;
    for (register unsigned j(1), TopSR(m - i + 1); j <= m; ++j) if (SA[j] > i) ScdRk[--TopSR] = SA[j] - i;
    for (register unsigned j(1); j <= m; ++j) SA[Bucket[RK[ScdRk[j]]]--] = ScdRk[j];
    memcpy(RkTmp, RK, (m + 1) << 2), BucketSize = 0;
    for (register unsigned j(1); j <= m; ++j) RK[SA[j]] = ((RkTmp[SA[j]] ^ RkTmp[SA[j - 1]]) || (RkTmp[SA[j] + i] ^ RkTmp[SA[j - 1] + i])) ? (++BucketSize) : (BucketSize);
    if (BucketSize == m) break;
  }
  for (register unsigned i(0); i <= n; ++i)
    for (register unsigned j(a[i]); j < a[i + 1]; ++j) BNum[RK[j]] = i;
  // printf("BNum\n");
  // for (register unsigned i(1); i <= m; ++i) printf("%u ", BNum[i]);
  // putchar('\n');
  for (register unsigned i(1), j(0); i <= m; ++i) {
    if (j) --j;
    if (RK[i] == 1) { ST[0][RK[i]] = 0; continue; }
    while ((SA[RK[i] - 1] + j <= m) && (i + j <= m) && (S[i + j] == S[SA[RK[i] - 1] + j])) ++j;
    ST[0][RK[i]] = j;
  }
  for (register unsigned i(1), j(0); i <= m; i <<= 1, ++j)
    for (register unsigned k(1); k + (i << 1) - 1 <= m; ++k)
      ST[j + 1][k] = min(ST[j][k], ST[j][k + i]);
  // printf("SA\n");
  // for (register unsigned i(1); i <= m; ++i) printf("%u %c", SA[i], S[SA[i]] + 95);
  // putchar('\n');
  // printf("Height\n");
  // for (register unsigned i(1); i <= m; ++i) printf("%u ", ST[0][i]);
  // putchar('\n');
  // printf("RK\n");
  // for (register unsigned i(1); i <= m; ++i) printf("%u ", RK[i]);
  // putchar('\n');
  for (register unsigned i(1), j(0); i <= m; i <<= 1, ++j) Bin[j] = i, Log[i] = j;
  for (register unsigned i(1); i <= m; ++i) Log[i] = max(Log[i], Log[i - 1]);// printf("Log %u = %u\n", i, Log[i]);
  q = RD(), BlcL = (m / sqrt(q)) + 1;
  for (register unsigned i(1); i <= q; ++i) {
    Q[i].RL = RD(), Q[i].RR = RD(), A = RD(), B = RD() - A + 1, A = RK[A], Q[i].Num = i;
    register unsigned BL(2), BR(A), BMid;
    while (BL < BR) {
      BMid = (BL + BR) >> 1;
      // printf("[%u, %u] Judge Min[%u, %u]\n", BL, BR, BMid, A);
      if (Min(BMid, A) >= B) BR = BMid;
      else BL = BMid + 1;
    }
    // printf("Done %u So %u\n", BL, ST[0][BL]);
    Q[i].L = (ST[0][BL] < B) ? BL : (BL - 1), BL = A + 1, BR = m;
    while (BL < BR) {
      BMid = (BL + BR + 1) >> 1;
      if (Min(A + 1, BMid) >= B) BL = BMid;
      else BR = BMid - 1;
    }
    Q[i].R = (ST[0][BL] < B) ? (BL - 1) : BL;
    // printf("Qry %u [%u, %u]\n", i, Q[i].L, Q[i].R);
  }
  for (register unsigned i(1); i <= n; ++i) Q[i].Bl = Q[i].R / BlcL;
  sort(Q + 1, Q + q + 1);
  for (register unsigned i(1), NowL(1), NowR(0), TmpAns, TmpPos, LBlc, RBlc, TmpL, TmpR; i <= q; ++i) {
    // printf("Qry Num %u [%u, %u] in %u\n", Q[i].Num, Q[i].L, Q[i].R, Q[i].Bl);
    while (NowL > Q[i].L) Add(BNum[--NowL]);
    while (NowR < Q[i].R) Add(BNum[++NowR]);
    while (NowL < Q[i].L) Del(BNum[NowL++]);
    while (NowR > Q[i].R) Del(BNum[NowR--]);
    LBlc = (Q[i].RL + BlcL2 - 1) / BlcL2, RBlc = (Q[i].RR + 1) / BlcL2, TmpAns = TmpPos = 0;
    // printf("[%u, %u] LB %u RB %u BL %u\n", Q[i].L, Q[i].R, LBlc, RBlc, BlcL2);
    if (RBlc <= LBlc) {
      for (register unsigned j(Q[i].RR); j >= Q[i].RL; --j) if (Cnt[j] >= TmpAns) TmpAns = Cnt[j], TmpPos = j;
      AnsC[Q[i].Num] = TmpAns, AnsN[Q[i].Num] = TmpPos; continue;
    }
    for (register unsigned j(RBlc - 1); j >= LBlc; --j) if (AnsBuc[j] >= TmpAns) TmpAns = AnsBuc[j], TmpPos = j;
    TmpL = TmpPos * BlcL2, TmpR = (TmpPos + 1) * BlcL2;
    for (register unsigned j(TmpL); j < TmpR; ++j) if (Cnt[j] == TmpAns) { TmpPos = j;  break; }
    for (register unsigned j((LBlc* BlcL2) - 1); j >= Q[i].RL; --j) if (Cnt[j] >= TmpAns) TmpAns = Cnt[j], TmpPos = j;
    for (register unsigned j((RBlc* BlcL2)); j <= Q[i].RR; ++j) if (Cnt[j] > TmpAns) TmpAns = Cnt[j], TmpPos = j;
    AnsC[Q[i].Num] = TmpAns, AnsN[Q[i].Num] = TmpPos;
  }
  for (register unsigned i(1); i <= q; ++i) printf("%u %u\n", AnsN[i], AnsC[i]);
  // system("pause");
  return Wild_Donkey;
}
/*
jhadsaksjdghfadsfkj
10
aksjfbd
askdjfhg
adksjfhkjdshf
asddfkjhasdf
asdkjfbskadf
askfjhe
asdkfjkjf
sdkhfgds
asekehgf
waieugu
1
3 10 17 18

4 1
*/