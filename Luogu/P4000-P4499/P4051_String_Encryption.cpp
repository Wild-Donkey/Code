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
inline int RDsg() {
  int rdtp(0), rdsg(1);
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
unsigned Addre[400005], SPool[400005], SAPool[400005], BucketPool[400005], PosPool[400005], TmpPool[400005], m, n, Cnt(0), A, B, C, D, t, Ans(0);
char Src[100005], TypePool[400005];
inline char Judge(unsigned *S, char *Type, unsigned x, unsigned y) {
  while (Type[x] & Type[y]) {
    if(S[x] ^ S[y]) return 0x1;
    ++x, ++y;
  }
  if(Type[x] | Type[y]) return 0x1;
  while (!(Type[x] | Type[y])) {
    if(S[x] ^ S[y]) return 0x1; 
    ++x, ++y;
  }
  if(!(Type[x] & Type[y])) return 0x1;
  return 0x0;
} 
void Induc (unsigned *S, unsigned *SA, unsigned *Bucket, char *Type, unsigned *Pos, unsigned *Tmp, unsigned N) {
  unsigned *S1(S + N), *SA1(SA + N), BucSiz(0), CntLMS(0), Rank(0);
  char flg(0);
  for (register unsigned i(1), j(0); i <= N; ++i)
    if(S[i] ^ S[i - 1]) {
      if(S[i] > S[i - 1]) while (j + 1 < i) Type[++j] = 1;
      else j = i - 1;
    }
  Type[0] = 0, Type[N] = 1;
  for (register unsigned i(1); i <= N; ++i)
    if(Type[i] && (!Type[i - 1]))
      Pos[++CntLMS] = i, Addre[i] = CntLMS;
  for (register unsigned i(1); i <= N; ++i)
    ++Bucket[S[i]], BucSiz = max(BucSiz, S[i]);
  for (register unsigned i(1); i <= BucSiz; ++i)
    Bucket[i] += Bucket[i - 1];
  memcpy(Tmp, Bucket, ((BucSiz + 0x1) << 2));
  memset(SA + 1, 0, (N << 0x2));
  for (register unsigned i(1); i <= CntLMS; ++i)
    SA[Tmp[S[Pos[i]]]--] = Pos[i];
  memcpy(Tmp, Bucket, ((BucSiz + 0x1) << 2)), Type[0] = 1;
  for (register unsigned i(1); i <= N; ++i)
    if(SA[i] > 1) if(!Type[SA[i] - 1])
      SA[++Tmp[S[SA[i] - 1] - 1]] = SA[i] - 1;
  memcpy(Tmp, Bucket, ((BucSiz + 0x1) << 2)), Type[0] = 0;
  for (register unsigned i(N); i; --i)
    if(SA[i] > 1) if(Type[SA[i] - 1])
        SA[Tmp[S[SA[i] - 1]]--] = SA[i] - 1;
  Cnt = 0;
  for (register unsigned i(1); i <= N; ++i) {
    if(Type[SA[i]] && (!Type[SA[i] - 1])) {
      SA1[++Cnt] = Addre[SA[i]];
      if((Cnt == 1) || Judge(S, Type, Pos[SA1[Cnt - 1]], Pos[SA1[Cnt]])) ++Rank;
      else flg = 1;
      S1[SA1[Cnt]] = Rank;
    }
  }
  if(flg) Induc(S1, SA1, Bucket + BucSiz + 1, Type + N, Pos + CntLMS, Tmp + BucSiz + 1, CntLMS);
  memset(SA + 1, 0, (N << 0x2));
  memcpy(Tmp, Bucket, ((BucSiz + 0x1) << 2));
  for (register unsigned i(CntLMS); i; --i)
    SA[Tmp[S[Pos[SA1[i]]]]--] = Pos[SA1[i]];
  memcpy(Tmp, Bucket, ((BucSiz + 0x1) << 2)), Type[0] = 1;
  for (register unsigned i(1); i <= N; ++i)
    if(SA[i] > 1) if(!Type[SA[i] - 1])
        SA[++Tmp[S[SA[i] - 1] - 1]] = SA[i] - 1;
  memcpy(Tmp, Bucket, ((BucSiz + 0x1) << 2)), Type[0] = 0;
  for (register unsigned i(N); i; --i)
    if(SA[i] > 1) if(Type[SA[i] - 1])
        SA[Tmp[S[SA[i] - 1]]--] = SA[i] - 1;
  Type[0] = 1;
}
int main() {
  fread(Src + 1, 1, 100000, stdin);
  while (Src[++n] >= 33) SPool[n] = Src[n]; --n;
  memcpy(SPool + n + 1, SPool + 1, ((n - 1) << 2));
  Src[n + 1] = Src[1];
  n <<= 0x1;
  SPool[n] = 1;
  Induc(SPool, SAPool, BucketPool, TypePool, PosPool, TmpPool, n);
  for (register unsigned i(1); i <= n; ++i)
    if(SAPool[i] <= (n >> 1)) putchar(Src[(SAPool[i] ^ 1) ? (SAPool[i] - 1) : (n >> 1)]);
  putchar('\n');
  return Wild_Donkey;
}
