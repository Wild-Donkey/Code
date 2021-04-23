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
unsigned Cnt(0), n, Ans(0), Tmp(0), SPool[2000005], SAPool[2000005], BucketPool[2000005], SumBucketPool[2000005], AddressPool[2000005], S_S1Pool[2000005];
char TypePool[2000005];
inline char Equal (unsigned *S, char *Type, unsigned x, unsigned y) {
//  printf("Compare %u %u\n", x, y);
  while (Type[x] & Type[y]) {
    if(S[x] ^ S[y]) {
      return 0;
    }
    ++x,++y;
  }
  if(Type[x] | Type[y]) {
    return 0;
  }
  while (!(Type[x] | Type[y])) {
    if(S[x] ^ S[y]) {
      return 0;
    }
    ++x, ++y;
  }
  if(Type[x] ^ Type[y]) {
    return 0;
  }
  if(S[x] ^ S[y]) {
    return 0;
  }
//  printf("Equal!\n");
  return 1;
}
void Induc (unsigned *Address, char *Type, unsigned *SA, unsigned *S, unsigned *S_S1, unsigned *Bucket, unsigned *SumBucket, unsigned N);// 诱导 SA
void Induced_Sort (unsigned *Address, char *Type, unsigned *SA, unsigned *S, unsigned *S_S1, unsigned *Bucket, unsigned *SumBucket, unsigned N, unsigned bucketSize, unsigned LMSR) {// 通过 S 求 SA
  SumBucket[0] = 1;
  for (register unsigned i(1); i <= bucketSize; ++i) {// 重置每个栈的栈底 (右端) 
    SumBucket[i] = SumBucket[i - 1] + Bucket[i];
  }
  memset(SA + 1, 0, sizeof(unsigned) * N);
  for (register unsigned i(LMSR); i > N; --i) {// 放长度为 1 的 LMS 前缀 
    if(N < 50000) {
    }
    SA[SumBucket[S[Address[i]]]--] = Address[i];
  }
  SumBucket[0] = 1;
  for (register unsigned i(1); i <= bucketSize; ++i) {  // 重置每个栈的栈底 (左端) 
    SumBucket[i] = SumBucket[i - 1] + Bucket[i];
  }
  for (register unsigned i(1); i <= N; ++i) {         // 从左到右扫 SA 数组 
    if(SA[i] && (SA[i] - 1)) {
      if(!Type[SA[i] - 1]) {                            // Suff[SA[i] - 1] 是 L-Type 
        SA[++SumBucket[S[SA[i] - 1] - 1]] = SA[i] - 1; 
      }
    }
  }
  SumBucket[0] = 1;
  for (register unsigned i(1); i <= bucketSize; ++i) {  // 重置每个栈的栈底 (右端) 
    SumBucket[i] = SumBucket[i - 1] + Bucket[i];
  }
  for (register unsigned i(N); i >= 1; --i) {         // 从右往左扫 SA 数组 
    if(SA[i] && (SA[i] - 1)) {
      if(Type[SA[i] - 1]) {                             // Suff[SA[i] - 1] 是 S-Type 
        SA[SumBucket[S[SA[i] - 1]]--] = SA[i] - 1; 
      }
    }
  }
  register char flg(0);
  register unsigned CntLMS(0), Pre(N), Pointer(N + 1);
  for (register unsigned i(2); i <= N; ++i) {         // 扫描找出 LMS, 判重并命名 
    if(Type[SA[i]] && (!Type[SA[i] - 1])) {
      if(Pre ^ N && Equal(S, Type, SA[i], Pre)) {          // 暴力判重
        S[S_S1[SA[i]]] = CntLMS;                            // 命名 
        flg = 1;
      }
      else {
        S[S_S1[SA[i]]] = ++CntLMS;                          // 命名 
      }
      Pre = SA[i];                                          // 用来判重 
      SA[++Pointer] = S_S1[SA[i]] - N;                      // 记录 LMS 
    }
  }
  S[LMSR] = 0;
  SA[N + 1] = LMSR - N;
  if(flg) {//排序 LMS 子串, 返回是否重复 
    Induc(Address + N, Type + N, SA + N, S + N, S_S1 + N, Bucket + bucketSize + 1, SumBucket + bucketSize + 1, LMSR - N); //有重复, 先诱导 SA1, 新的 Bucket 直接接在后面 
  }
  return;//这时保证 SA1 是对的 
}
void Induc (unsigned *Address, char *Type, unsigned *SA, unsigned *S, unsigned *S_S1, unsigned *Bucket, unsigned *SumBucket, unsigned N) {// 诱导 SA
  for (register unsigned i(1), j(1); i < N; ++i) {    // 定性
    if(S[i] < S[i + 1]) { // Suff[j~i] 是 S-Type 
      while (j <= i) {
        Type[j++] = 1;
      }
    }
    if(S[i] > S[i + 1]) { // Suff[j~i] 是 L-Type 
      while (j <= i) {
        Type[j++] = 0;
      }
    }
  }
  Type[N] = 1;
  Type[0] = 1;
  register unsigned CntLMS(N);
  for (register unsigned i(1); i < N; ++i) {         // 找 LMS, 记录在 S 中地址, 统计 LMSR 
    if(!Type[i]) {
      if(Type[i + 1]) {
        Address[++CntLMS] = i + 1;
        S_S1[i + 1] = CntLMS;
      }
    }
  }
  register unsigned bucketSize(0);
  for (register unsigned i(1); i <= N; ++i) {         // 确定 Bucket
    ++Bucket[S[i]];
    bucketSize = bucketSize < S[i] ? S[i] : bucketSize; // 统计 Bucket 的空间范围 
  }
  Induced_Sort(Address, Type, SA, S, S_S1, Bucket, SumBucket, N, bucketSize, CntLMS);// 诱导排序 LMS 子串
  memset(SA + 1, 0, sizeof(unsigned) * N);
  SumBucket[0] = 1;                                     // SA1 求出来了, 开始诱导 
  for (register unsigned i(1); i <= bucketSize; ++i) {  // 重置每个栈的栈底 (右端) 
    SumBucket[i] = SumBucket[i - 1] + Bucket[i];
  }
  for (register unsigned i(CntLMS); i > N; --i) {       // 放 LMS 后缀 
    SA[SumBucket[S[Address[SA[i] + N]]]--] = Address[SA[i] + N];
  }
  SumBucket[0] = 1;
  for (register unsigned i(1); i <= bucketSize; ++i) {  // 重置每个栈的栈底 (左端) 
    SumBucket[i] = SumBucket[i - 1] + Bucket[i];
  }
  for (register unsigned i(1); i <= N; ++i) {           // 从左到右扫 SA 数组 
    if(SA[i] && (SA[i] - 1)) {
      if(!Type[SA[i] - 1]) {                            // Suff[SA[i] - 1] 是 L-Type 
        SA[++SumBucket[S[SA[i] - 1] - 1]] = SA[i] - 1; 
      }
    }
  }
  SumBucket[0] = 1;
  for (register unsigned i(1); i <= bucketSize; ++i) {  // 重置每个栈的栈底 (右端) 
    SumBucket[i] = SumBucket[i - 1] + Bucket[i];
  }
  for (register unsigned i(N); i >= 1; --i) {           // 从右往左扫 SA 数组 
    if(SA[i] && (SA[i] - 1)) {
      if(Type[SA[i] - 1]) {                             // Suff[SA[i] - 1] 是 S-Type 
        SA[SumBucket[S[SA[i] - 1]]--] = SA[i] - 1; 
      }
    }
  }
  return;
}
int main() {
  fread(TypePool + 1, 1, 1000004, stdin);
  for (register unsigned i(1); ; ++i) {   // 尽量压缩字符集 
    if(TypePool[i] <= '9' && TypePool[i] >= '0') {
      SPool[i] = TypePool[i] - 47;
      continue;
    }
    if(TypePool[i] <= 'Z' && TypePool[i] >= 'A') {
      SPool[i] = TypePool[i] - 53;
      continue;
    }
    if(TypePool[i] <= 'z' && TypePool[i] >= 'a') {
      SPool[i] = TypePool[i] - 59;
      continue;
    }
    n = i;
    break;
  }
  SPool[n] = 0;                 
  Induc (AddressPool, TypePool, SAPool, SPool, S_S1Pool, BucketPool, SumBucketPool, n);
  for (register unsigned i(2); i <= n; ++i) {
    printf("%u ", SAPool[i]);
  }
  return Wild_Donkey;
}



