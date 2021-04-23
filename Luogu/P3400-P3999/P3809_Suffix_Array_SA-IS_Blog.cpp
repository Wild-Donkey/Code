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
unsigned Cnt(0), n, Ans(0), Tmp(0), SPool[2000005], SAPool[2000005], BucketPool[2000005], SumBucketPool[2000005], AddressPool[2000005], S_S1Pool[2000005];
char TypePool[2000005];
inline char Equal (unsigned *S, char *Type, unsigned x, unsigned y) {
  while (Type[x] & Type[y]) {     // 比较 S 区 
    if(S[x] ^ S[y]) {
      return 0;
    }
    ++x,++y;
  }
  if(Type[x] | Type[y]) {         // L 区起点是否整齐 
    return 0;
  }
  while (!(Type[x] | Type[y])) {  // 比较 L 区 
    if(S[x] ^ S[y]) {
      return 0;
    }
    ++x, ++y;
  }
  if(Type[x] ^ Type[y]) {         // 尾 S 位置是否对应 
    return 0;
  }
  if(S[x] ^ S[y]) {               // 尾 S 权值是否相等 
    return 0;
  }
  return 1;
}
void Induc (unsigned *Address, char *Type, unsigned *SA, unsigned *S, unsigned *S_S1, unsigned *Bucket, unsigned *SumBucket, unsigned N);// 诱导 SA
void Induced_Sort (unsigned *Address, char *Type, unsigned *SA, unsigned *S, unsigned *S_S1, unsigned *Bucket, unsigned *SumBucket, unsigned N, unsigned bucketSize, unsigned LMSR) {// 通过 S 求 SA
  SumBucket[0] = 1;
  for (register unsigned i(1); i <= bucketSize; ++i) {  // 重置每个栈的栈底 (右端) 
    SumBucket[i] = SumBucket[i - 1] + Bucket[i];
  }
  memset(SA + 1, 0, sizeof(unsigned) * N);              // 在上一层的诱导排序中, 填入了 SA, 这里进行清空 
  for (register unsigned i(LMSR); i > N; --i) {         // 放长度为 1 的 LMS 前缀 
    SA[SumBucket[S[Address[i]]]--] = Address[i];
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
  register char flg(0)/*是否有重*/;
  register unsigned CntLMS(0)/*本质不同的 LMS 子串数量*/, Pre(N)/*上一个 LMS 子串起点*/, *Pointer(SA + N + 1)/*LMS 子串的 SA 的头指针*/;
  for (register unsigned i(2); i <= N; ++i) {           // 扫描找出 LMS, 判重并命名 
    if(Type[SA[i]] && (!Type[SA[i] - 1])) {
      if(Pre ^ N && Equal(S, Type, SA[i], Pre)) {       // 暴力判重
        S[S_S1[SA[i]]] = CntLMS;                        // 命名 
        flg = 1;
      }
      else {
        S[S_S1[SA[i]]] = ++CntLMS;                      // 命名 
      }
      Pre = SA[i];                                      // 用来判重 
      *(++Pointer) = S_S1[SA[i]] - N;                   // 记录 LMS 
    }
  }
  S[LMSR] = 0;
  SA[N + 1] = LMSR - N;                                 // 末尾空串最小 
  if(flg) {                                             // 有重复 LMS 子串, 递归排序 S1 
    Induc(Address + N, Type + N, SA + N, S + N, S_S1 + N, Bucket + bucketSize + 1, SumBucket + bucketSize + 1, LMSR - N); //有重复, 先诱导 SA1, 新的 Bucket 直接接在后面 
  }
  return;                                               // 递归跳出, 保证 SA1 是严格的
}
void Induc (unsigned *Address, char *Type, unsigned *SA, unsigned *S, unsigned *S_S1, unsigned *Bucket, unsigned *SumBucket, unsigned N) {// 诱导 SA
  for (register unsigned i(1), j(1); i < N; ++i) {      // 定性 S/L 
    if(S[i] < S[i + 1]) {                               // Suff[j~i] 是 S-Type 
      while (j <= i) {
        Type[j++] = 1;
      }
    }
    if(S[i] > S[i + 1]) {                               // Suff[j~i] 是 L-Type 
      while (j <= i) {
        Type[j++] = 0;
      }
    }
  }
  Type[N] = 1;
  Type[0] = 1;
  register unsigned CntLMS(N)/*记录 LMS 字符数量*/;
  for (register unsigned i(1); i < N; ++i) {            // 记录 S1 中字符对应的 S 的 LMS 子串左端 LMS 字符的位置 Address[], 和 S 中的 LMS 子串在 S1 中的位置 S_S1[] 
    if(!Type[i]) {
      if(Type[i + 1]) {
        Address[++CntLMS] = i + 1;
        S_S1[i + 1] = CntLMS;
      }
    }
  }
  register unsigned bucketSize(0);                      // 本次递归字符集大小 
  for (register unsigned i(1); i <= N; ++i) {           // 确定 Bucket, 可以线性生成 SumBucket 
    ++Bucket[S[i]];
    bucketSize = bucketSize < S[i] ? S[i] : bucketSize; // 统计 Bucket 的空间范围 
  }
  Induced_Sort(Address, Type, SA, S, S_S1, Bucket, SumBucket, N, bucketSize, CntLMS);// 诱导排序 LMS 子串, 求 SA1 
  memset(SA + 1, 0, sizeof(unsigned) * N);              // 在求 SA1 时也填了一遍 SA, 这里进行清空 
  SumBucket[0] = 1;                                     // SA1 求出来了, 开始诱导 SA 
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
  SPool[n] = 0;// 最后一位存空串, 作为哨兵 
  Induc (AddressPool, TypePool, SAPool, SPool, S_S1Pool, BucketPool, SumBucketPool, n);
  for (register unsigned i(2); i <= n; ++i) { // SA[1] 是最小的后缀, 算法中将空串作为最小的后缀, 所以不输出 SA[1] 
    printf("%u ", SAPool[i]);
  }
  return Wild_Donkey;
}
