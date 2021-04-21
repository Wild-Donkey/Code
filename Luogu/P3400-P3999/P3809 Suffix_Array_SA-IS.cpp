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
unsigned Cnt(0), n, Ans(0), Tmp(0), S[2000005], SA[2000005], BucketPool[500005], SumBucketPool[500005], Address[2000005], S_S1[2000005];
char Type[1000005], IfLMS[2000005];
void Print(unsigned L, unsigned R) {
  printf("Address[%u, %u]\n", L, R);
  for (register unsigned i(L); i <= R; ++i) {
    printf("%3u", i);
  }
  putchar('\n');
  printf("S[%u, %u]\n", L, R);
  for (register unsigned i(L); i <= R; ++i) {
    printf("%3u", S[i]);
  }
  putchar('\n');
  printf("Type[%u, %u]\n", L, R);
  for (register unsigned i(L); i <= R; ++i) {
    printf("%3c", Type[i] ? 'S' : 'L');
  }
  putchar('\n');
  printf("SA[%u, %u]\n", L, R);
  for (register unsigned i(L); i <= R; ++i) {
    printf("%3u", SA[i]);
  }
  putchar('\n');
  printf("IfLMS[%u, %u]\n", L, R);
  for (register unsigned i(L); i <= R; ++i) {
    printf("%3u", IfLMS[i]);
  }
  putchar('\n');
  putchar('\n');
  putchar('\n');
  return;
}
inline char Equal (unsigned x, unsigned y) {
//  printf("Compare %u %u\n", x, y);
  if(S[x] ^ S[y]) {
    return 0;
  }
  while (!(IfLMS[++x] || IfLMS[++y])) {
    if(S[x] ^ S[y]) {
//      printf("%u %u %u %u\n", x, y, S[x], S[y]);
      return 0;
    }
  }
  if(IfLMS[x] ^ IfLMS[y]) {
    return 0;
  }
//  printf("Equal!!\n");
  return 1;
}
void Induc (unsigned SL, unsigned SR, unsigned *Bucket, unsigned *SumBucket);// 诱导 SA
void Induced_Sort (unsigned SL, unsigned SR, unsigned* Bucket, unsigned *SumBucket, unsigned bucketSize, unsigned LMSR) {// 通过 S 求 SA
  printf("Induced_Sort %u %u %u %u\n", SL, SR, bucketSize, LMSR);
  SumBucket[0] = 1;
  for (register unsigned i(1); i <= bucketSize; ++i) {// 重置每个栈的栈底 (右端) 
    SumBucket[i] = SumBucket[i - 1] + Bucket[i];
//    printf("SumBucket[%u] = %u\n", i, SumBucket[i]);
  }
  for (register unsigned i(LMSR); i > SR; --i) {// 放长度为 1 的 LMS 前缀 
    SA[SumBucket[S[Address[i]]]--] = Address[i];
  }
//  Print(SL, SR);
  printf("BooM?!\n");
  SumBucket[0] = 1;
  for (register unsigned i(1); i <= bucketSize; ++i) {  // 重置每个栈的栈底 (左端) 
    SumBucket[i] = SumBucket[i - 1] + Bucket[i];
  }
  for (register unsigned i(SL); i <= SR; ++i) {         // 从左到右扫 SA 数组 
    if(SA[i]) {
      if(!Type[SA[i] - 1]) {                            // Suff[SA[i] - 1] 是 L-Type 
        SA[++SumBucket[S[SA[i] - 1] - 1]] = SA[i] - 1; 
      }
    }
  }
  printf("BooM?!\n");
  SumBucket[0] = 1;
  for (register unsigned i(1); i <= bucketSize; ++i) {  // 重置每个栈的栈底 (右端) 
    SumBucket[i] = SumBucket[i - 1] + Bucket[i];
  }
  for (register unsigned i(SR); i >= SL; --i) {         // 从右往左扫 SA 数组 
    if(SA[i]) {
      if(Type[SA[i] - 1]) {                             // Suff[SA[i] - 1] 是 S-Type 
        SA[SumBucket[S[SA[i] - 1]]--] = SA[i] - 1; 
      }
    }
  }
//  Print(SL, SR);
  printf("BooM?!\n");
  register char flg(0);
  register unsigned CntLMS(0)/**/, Pre(SR), Pointer(SR + 1);
  for (register unsigned i(SL + 1); i <= SR; ++i) {         // 扫描找出 LMS, 判重并命名 
    if(IfLMS[SA[i]]) {
      if(Equal(i, Pre)) {                                   // 暴力判重 
        S[S_S1[SA[i]]] = CntLMS;                            // 命名 
        flg = 1;
      }
      else {
        S[S_S1[SA[i]]] = ++CntLMS;                          // 命名 
      }
      Pre = SA[i];                                          // 用来判重 
      SA[++Pointer] = S_S1[SA[i]];                          // 记录 LMS 
//      if(i == 1003) {
//        Print(1003, 1273);
//      }
      printf("SA[%u] %u, SA[%u] = S_S1 %u\n", i, SA[i], Pointer, S_S1[SA[i]]);
    }
  }
  printf("BooM?!\n");
  S[LMSR] = 0;
  SA[SR + 1] = LMSR;
  printf("BooM?!\n");
  if(flg) {//排序 LMS 子串, 返回是否重复 
    printf("Do down\n");
    Induc(SR + 1, LMSR, Bucket + bucketSize + 1, SumBucket + bucketSize + 1); //有重复, 先诱导 SA1, 新的 Bucket 直接接在后面 
  }
//  Print(SR + 1, LMSR);
  return;//这时保证 SA1 是对的 
}
void Induc (unsigned SL, unsigned SR, unsigned *Bucket, unsigned *SumBucket) {// 诱导 SA
  printf("Induc %u %u %u %u\n", SL, SR, Bucket - BucketPool, SumBucket - SumBucketPool);
  for (register unsigned i(SL), j(SL); i < SR; ++i) {    // 定性
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
  Type[SR] = 1;
  register unsigned CntLMS(SR);
  for (register unsigned i(SL); i < SR; ++i) {         // 找 LMS, 记录在 S 中地址, 统计 LMSR 
    if(!Type[i]) {
      if(Type[i + 1]) {
        Address[++CntLMS] = i + 1;
        S_S1[i + 1] = CntLMS;
        IfLMS[i + 1] = 1;
      }
    }
  }
  register unsigned bucketSize(0);
  for (register unsigned i(SL); i <= SR; ++i) {         // 确定 Bucket
    ++Bucket[S[i]];
    bucketSize = bucketSize < S[i] ? S[i] : bucketSize; // 统计 Bucket 的空间范围 
  }
  Induced_Sort(SL, SR, Bucket, SumBucket, bucketSize, CntLMS);// 诱导排序 LMS 子串
  printf("Continue\n");
  SumBucket[0] = 1;                                     // SA1 求出来了, 开始诱导 
  for (register unsigned i(1); i <= bucketSize; ++i) {  // 重置每个栈的栈底 (右端) 
    SumBucket[i] = SumBucket[i - 1] + Bucket[i];
//    printf("SumBucket[%u] = %u\n", i, SumBucket[i]);
  }
  printf("Memset BooM?!\n");
  printf("Before SA[%u] %u\n", CntLMS, SA[CntLMS]);
  memset(SA + SL, 0, sizeof(unsigned) * (SR - SL + 1));
  printf("After SA[%u] %u\n", CntLMS, SA[CntLMS]);
  printf("%u %u %u %u\n", SL, SR, (SR - SL + 1), CntLMS);
  printf("It didn't\n");
  for (register unsigned i(CntLMS); i > SR; --i) {      // 放长度为 1 的 LMS 前缀 
//    printf("Excuse me? SA[%u] %u Address %u\n", i, SA[i], Address[SA[i]]);
    SA[SumBucket[S[Address[SA[i]]]]--] = Address[SA[i]];
  }
  printf("BooM_Again?!\n");
//  Print(SL, SR);
  SumBucket[0] = 1;
  for (register unsigned i(1); i <= bucketSize; ++i) {  // 重置每个栈的栈底 (左端) 
    SumBucket[i] = SumBucket[i - 1] + Bucket[i];
  }
  for (register unsigned i(SL); i <= SR; ++i) {         // 从左到右扫 SA 数组 
    if(SA[i]) {
      if(!Type[SA[i] - 1]) {                            // Suff[SA[i] - 1] 是 L-Type 
//        printf("Insert L-Type %u\n", SA[i] - 1); 
        SA[++SumBucket[S[SA[i] - 1] - 1]] = SA[i] - 1; 
      }
    }
  }
//  Print(SL, SR);
  SumBucket[0] = 1;
  for (register unsigned i(1); i <= bucketSize; ++i) {  // 重置每个栈的栈底 (右端) 
    SumBucket[i] = SumBucket[i - 1] + Bucket[i];
//    printf("SumBucket[%u] = %u\n", i, SumBucket[i]);
  }
//  Print(SL, SR);
//  Print(SL, SR);
  for (register unsigned i(SR); i >= SL; --i) {         // 从右往左扫 SA 数组 
    if(SA[i]) {
      if(Type[SA[i] - 1]) {                             // Suff[SA[i] - 1] 是 S-Type 
//        printf("Insert %u\n", SA[i] - 1);
        SA[SumBucket[S[SA[i] - 1]]--] = SA[i] - 1; 
      }
    }
  }
//  Print(SL, SR);
  for (register unsigned i(SL); i <= SR; ++i) {
    printf("%u ", SA[i]);
  }
  return;
}
int main() {
  // double Ti(clock()), Mti(0);
   freopen("P3809_2.in", "r", stdin);
//   freopen("P3809.out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  fread(Type + 1, 1, 1000004, stdin);
  for (register unsigned i(1); ; ++i) {
    if(Type[i] <= '9' && Type[i] >= '0') {
      S[i] = Type[i] - 47;
      continue;
    }
    if(Type[i] <= 'Z' && Type[i] >= 'A') {
      S[i] = Type[i] - 53;
      continue;
    }
    if(Type[i] <= 'z' && Type[i] >= 'a') {
      S[i] = Type[i] - 59;
      continue;
    }
    n = i;
    break;
  }
//  printf("%u\n", n);
  S[n] = 0;
  Induc (1, n, BucketPool, SumBucketPool);
  for (register unsigned i(1); i <= n; ++i) {
    printf("%u ", SA[i]);
  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}



