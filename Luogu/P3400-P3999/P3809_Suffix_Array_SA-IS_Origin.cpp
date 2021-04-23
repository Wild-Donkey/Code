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
char TypePool[2000005], IfLMSPool[2000005];
void Print(char *IfLMS, unsigned *Address, char *Type, unsigned *SA, unsigned *S, unsigned *S_S1, unsigned N) {
  printf("Address[%u, %u]\n", 1, N);
  for (register unsigned i(1); i <= N; ++i) {
    printf("%3u", i);
  }
  putchar('\n');
  printf("S[%u, %u]\n", 1, N);
  for (register unsigned i(1); i <= N; ++i) {
    printf("%3u", S[i]);
  }
  putchar('\n');
  printf("Type[%u, %u]\n", 1, N);
  for (register unsigned i(1); i <= N; ++i) {
    printf("%3c", Type[i] ? 'S' : 'L');
  }
  putchar('\n');
  printf("SA[%u, %u]\n", 1, N);
  for (register unsigned i(1); i <= N; ++i) {
    printf("%3u", SA[i]);
  }
  putchar('\n');
  printf("IfLMS[%u, %u]\n", 1, N);
  for (register unsigned i(1); i <= N; ++i) {
    printf("%3u", IfLMS[i]);
  }
  putchar('\n');
  putchar('\n');
  putchar('\n');
  return;
}
inline char Equal (unsigned *S, char *IfLMS, unsigned x, unsigned y) {
//  printf("Compare %u %u %u %u\n", x, y, S[x], S[y]);
  if(S[x] ^ S[y]) {
    return 0;
  }
  while (!(IfLMS[++x] | IfLMS[++y])) {
    if(S[x] ^ S[y]) {
//      printf("%u %u %u %u\n", x, y, S[x], S[y]);
      return 0;
    }
  }
  if(S[x] ^ S[y]) {
    return 0;
  }
//  printf("%u %u %u %u\n", x, y, S[x], S[y]);
  if(IfLMS[x] ^ IfLMS[y]) {
    return 0;
  }
//  printf("Equal!!\n");
  return 1;
}
void Induc (char *IfLMS, unsigned *Address, char *Type, unsigned *SA, unsigned *S, unsigned *S_S1, unsigned *Bucket, unsigned *SumBucket, unsigned N);// 诱导 SA
void Induced_Sort (char *IfLMS, unsigned *Address, char *Type, unsigned *SA, unsigned *S, unsigned *S_S1, unsigned *Bucket, unsigned *SumBucket, unsigned N, unsigned bucketSize, unsigned LMSR) {// 通过 S 求 SA
//  printf("Induced_Sort Here %u %u %u %u\n", S - SPool, N, bucketSize, LMSR);
  SumBucket[0] = 1;
  for (register unsigned i(1); i <= bucketSize; ++i) {// 重置每个栈的栈底 (右端) 
    SumBucket[i] = SumBucket[i - 1] + Bucket[i];
//    printf("SumBucket[%u] = %u\n", i, SumBucket[i]);
  }
  memset(SA + 1, 0, sizeof(unsigned) * N);
  for (register unsigned i(LMSR); i > N; --i) {// 放长度为 1 的 LMS 前缀 
    if(N < 50000) {
//      printf("Why %u %u %u\n", i, Address[i], S[Address[i]]);
    }
    SA[SumBucket[S[Address[i]]]--] = Address[i];
  }
//  printf("Sort After LMS\n");
//  Print(IfLMS, Address, Type, SA, S, S_S1, N);
//  printf("BooM?!\n");
  SumBucket[0] = 1;
  for (register unsigned i(1); i <= bucketSize; ++i) {  // 重置每个栈的栈底 (左端) 
    SumBucket[i] = SumBucket[i - 1] + Bucket[i];
//    printf("SumBucket[%u] = %u\n", i, SumBucket[i]); 
  }
  for (register unsigned i(1); i <= N; ++i) {         // 从左到右扫 SA 数组 
    if(SA[i] && (SA[i] - 1)) {
//      printf("So What %u %u %u %u %u\n", i, SA[i], SA[i] - 1, Type[SA[i] - 1], S[SA[i] - 1]);
      if(!Type[SA[i] - 1]) {                            // Suff[SA[i] - 1] 是 L-Type 
        SA[++SumBucket[S[SA[i] - 1] - 1]] = SA[i] - 1; 
      }
    }
  }
//  printf("BooM?!\n");
//  printf("Sort After L-Type\n");
//  Print(IfLMS, Address, Type, SA, S, S_S1, N);
  SumBucket[0] = 1;
  for (register unsigned i(1); i <= bucketSize; ++i) {  // 重置每个栈的栈底 (右端) 
    SumBucket[i] = SumBucket[i - 1] + Bucket[i];
//    printf("SumBucket[%u] = %u\n", i, SumBucket[i]); 
  }
  for (register unsigned i(N); i >= 1; --i) {         // 从右往左扫 SA 数组 
    if(SA[i] && (SA[i] - 1)) {
      if(Type[SA[i] - 1]) {                             // Suff[SA[i] - 1] 是 S-Type 
//        printf("WDNMD %u %u %u\n", SA[i] - 1, S[SA[i] - 1], SumBucket[S[SA[i] - 1]]);
        SA[SumBucket[S[SA[i] - 1]]--] = SA[i] - 1; 
      }
    }
  }
//  printf("Sort After S-Type\n");
//  Print(IfLMS, Address, Type, SA, S, S_S1, N);
//  printf("BooM?!\n");
  register char flg(0);
  register unsigned CntLMS(0)/**/, Pre(N), Pointer(N + 1);
  for (register unsigned i(2); i <= N; ++i) {         // 扫描找出 LMS, 判重并命名 
    if(IfLMS[SA[i]]) {
//      printf("LMS SA[%u] = %u\n", i, SA[i]);
      if(Pre ^ N && Equal(S, IfLMS, SA[i], Pre)) {          // 暴力判重
        if(!CntLMS) {
          printf("????SA[%u] = %u\n", i, SA[i]); 
        } 
        S[S_S1[SA[i]]] = CntLMS;                            // 命名 
        flg = 1;
      }
      else {
        S[S_S1[SA[i]]] = ++CntLMS;                          // 命名 
      }
      Pre = SA[i];                                          // 用来判重 
      SA[++Pointer] = S_S1[SA[i]] - N;                      // 记录 LMS 
//      if(i == 1003) {
//        Print(1003, 1273);
//      }
//      printf("SA[%u] %u, SA[%u] = S_S1 %u S[] = %u\n", i, SA[i], Pointer, S_S1[SA[i]], S[S_S1[SA[i]]]);
    }
  }
//  for (register unsigned i(N + 1); i <= LMSR; ++i) {
//    printf("S[%u] = %u\n", i - N, S[i]);
//  }
//  printf("BooM?!\n");
  S[LMSR] = 0;
  SA[N + 1] = LMSR - N;
  if(LMSR == N) {
    printf("WDNMD\n");
  }
//  printf("Here %u N %u SA[%u] = %u\n", S - SPool, N, N + 1, LMSR - N);
//  printf("BooM?!\n");
  if(flg) {//排序 LMS 子串, 返回是否重复 
//    printf("Do down\n");
    Induc(IfLMS + N, Address + N, Type + N, SA + N, S + N, S_S1 + N, Bucket + bucketSize + 1, SumBucket + bucketSize + 1, LMSR - N); //有重复, 先诱导 SA1, 新的 Bucket 直接接在后面 
  }
//  Print(SR + 1, LMSR);
  return;//这时保证 SA1 是对的 
}
void Induc (char *IfLMS, unsigned *Address, char *Type, unsigned *SA, unsigned *S, unsigned *S_S1, unsigned *Bucket, unsigned *SumBucket, unsigned N) {// 诱导 SA
//  printf("Induc %u %u %u\n", N, Bucket - BucketPool, SumBucket - SumBucketPool);
//  printf("Firstly\n");
//  Print(IfLMS, Address, Type, SA, S, S_S1, N);
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
  register unsigned CntLMS(N);
//  if(Type[1]) {
//    Address[++CntLMS] = 1;
//    S_S1[1] = N + 1;
//    IfLMS[1] = 1;
//  }
  for (register unsigned i(1); i < N; ++i) {         // 找 LMS, 记录在 S 中地址, 统计 LMSR 
    if(!Type[i]) {
      if(Type[i + 1]) {
        Address[++CntLMS] = i + 1;
        S_S1[i + 1] = CntLMS;
        IfLMS[i + 1] = 1;
      }
    }
  }
//  Address[CntLMS] = N;
  register unsigned bucketSize(0);
  for (register unsigned i(1); i <= N; ++i) {         // 确定 Bucket
    ++Bucket[S[i]];
    bucketSize = bucketSize < S[i] ? S[i] : bucketSize; // 统计 Bucket 的空间范围 
  }
//  printf("Before Sort\n");
//  Print(IfLMS, Address, Type, SA, S, S_S1, N);
  Induced_Sort(IfLMS, Address, Type, SA, S, S_S1, Bucket, SumBucket, N, bucketSize, CntLMS);// 诱导排序 LMS 子串
//  printf("Continue\n");
//  printf("Memset BooM?!\n");
//  printf("Before SA[%u] %u\n", N + 1, SA[N + 1]); 
  for (register unsigned i(1); i <= N; ++i) {
//    printf("%u ", SA[i]);
    if(!SA[i]) {
      printf("Before 0 %u\n", i);
    }
  }
  memset(SA + 1, 0, sizeof(unsigned) * N);
//  printf("After SA[%u] %u\n", N + 1, SA[N + 1]);
//  printf("%u %u\n", N, CntLMS);
//  printf("It didn't\n");
  SumBucket[0] = 1;                                     // SA1 求出来了, 开始诱导 
  for (register unsigned i(1); i <= bucketSize; ++i) {  // 重置每个栈的栈底 (右端) 
    SumBucket[i] = SumBucket[i - 1] + Bucket[i];
//    printf("SumBucket[%u] = %u\n", i, SumBucket[i]);
  }
//  Address[N] = N;
  for (register unsigned i(CntLMS); i > N; --i) {      // 放长度为 1 的 LMS 前缀 
//    printf("Here %u Excuse me? Address[SA[%u] = %u] = %u\n", S - SPool, i, SA[i] + N, Address[SA[i] + N]);
    SA[SumBucket[S[Address[SA[i] + N]]]--] = Address[SA[i] + N];
  }
//  printf("BooM_Again?!\n");
//  printf("After LMS\n");
//  Print(IfLMS, Address, Type, SA, S, S_S1, N);
  SumBucket[0] = 1;
  for (register unsigned i(1); i <= bucketSize; ++i) {  // 重置每个栈的栈底 (左端) 
    SumBucket[i] = SumBucket[i - 1] + Bucket[i];
  }
  for (register unsigned i(1); i <= N; ++i) {         // 从左到右扫 SA 数组 
    if(SA[i] && (SA[i] - 1)) {
      if(!Type[SA[i] - 1]) {                            // Suff[SA[i] - 1] 是 L-Type 
//        printf("Insert L-Type %u\n", SA[i] - 1); 
        SA[++SumBucket[S[SA[i] - 1] - 1]] = SA[i] - 1; 
      }
    }
  }
//  printf("BooM_Again?!\n");
//  printf("After L-Type\n");
//  Print(IfLMS, Address, Type, SA, S, S_S1, N);
  SumBucket[0] = 1;
  for (register unsigned i(1); i <= bucketSize; ++i) {  // 重置每个栈的栈底 (右端) 
    SumBucket[i] = SumBucket[i - 1] + Bucket[i];
//    printf("SumBucket[%u] = %u\n", i, SumBucket[i]);
  }
//  Print(SL, SR);
  for (register unsigned i(N); i >= 1; --i) {         // 从右往左扫 SA 数组 
    if(SA[i] && (SA[i] - 1)) {
      if(Type[SA[i] - 1]) {                             // Suff[SA[i] - 1] 是 S-Type 
//        printf("Insert %u\n", SA[i] - 1);
        SA[SumBucket[S[SA[i] - 1]]--] = SA[i] - 1; 
      }
    }
  }
//  printf("BooM_Again?!\n");
//  printf("After S-Type\n");
//  Print(IfLMS, Address, Type, SA, S, S_S1, N);
  for (register unsigned i(1); i <= N; ++i) {
//    printf("%u ", SA[i]);
    if(!SA[i]) {
      printf("0 %u\n", i);
    }
  }
  return;
}
int main() {
  // double Ti(clock()), Mti(0);
  freopen("P3809_-3.in", "r", stdin);
  freopen("mystd.out", "w", stdout);
//   freopen("P3809.out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  fread(TypePool + 1, 1, 1000004, stdin);
  for (register unsigned i(1); ; ++i) {
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
  Induc (IfLMSPool, AddressPool, TypePool, SAPool, SPool, S_S1Pool, BucketPool, SumBucketPool, n);
//  printf("%u\n", n - 1);
  for (register unsigned i(2); i <= n; ++i) {
    printf("%u ", SAPool[i]);
  }
//  printf("%u", SAPool[n]); 
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}



