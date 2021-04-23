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
  while (Type[x] & Type[y]) {     // �Ƚ� S �� 
    if(S[x] ^ S[y]) {
      return 0;
    }
    ++x,++y;
  }
  if(Type[x] | Type[y]) {         // L ������Ƿ����� 
    return 0;
  }
  while (!(Type[x] | Type[y])) {  // �Ƚ� L �� 
    if(S[x] ^ S[y]) {
      return 0;
    }
    ++x, ++y;
  }
  if(Type[x] ^ Type[y]) {         // β S λ���Ƿ��Ӧ 
    return 0;
  }
  if(S[x] ^ S[y]) {               // β S Ȩֵ�Ƿ���� 
    return 0;
  }
  return 1;
}
void Induc (unsigned *Address, char *Type, unsigned *SA, unsigned *S, unsigned *S_S1, unsigned *Bucket, unsigned *SumBucket, unsigned N);// �յ� SA
void Induced_Sort (unsigned *Address, char *Type, unsigned *SA, unsigned *S, unsigned *S_S1, unsigned *Bucket, unsigned *SumBucket, unsigned N, unsigned bucketSize, unsigned LMSR) {// ͨ�� S �� SA
  SumBucket[0] = 1;
  for (register unsigned i(1); i <= bucketSize; ++i) {  // ����ÿ��ջ��ջ�� (�Ҷ�) 
    SumBucket[i] = SumBucket[i - 1] + Bucket[i];
  }
  memset(SA + 1, 0, sizeof(unsigned) * N);              // ����һ����յ�������, ������ SA, ���������� 
  for (register unsigned i(LMSR); i > N; --i) {         // �ų���Ϊ 1 �� LMS ǰ׺ 
    SA[SumBucket[S[Address[i]]]--] = Address[i];
  }
  SumBucket[0] = 1;
  for (register unsigned i(1); i <= bucketSize; ++i) {  // ����ÿ��ջ��ջ�� (���) 
    SumBucket[i] = SumBucket[i - 1] + Bucket[i];
  }
  for (register unsigned i(1); i <= N; ++i) {           // ������ɨ SA ���� 
    if(SA[i] && (SA[i] - 1)) {
      if(!Type[SA[i] - 1]) {                            // Suff[SA[i] - 1] �� L-Type 
        SA[++SumBucket[S[SA[i] - 1] - 1]] = SA[i] - 1; 
      }
    }
  }
  SumBucket[0] = 1;
  for (register unsigned i(1); i <= bucketSize; ++i) {  // ����ÿ��ջ��ջ�� (�Ҷ�) 
    SumBucket[i] = SumBucket[i - 1] + Bucket[i];
  }
  for (register unsigned i(N); i >= 1; --i) {           // ��������ɨ SA ���� 
    if(SA[i] && (SA[i] - 1)) {
      if(Type[SA[i] - 1]) {                             // Suff[SA[i] - 1] �� S-Type 
        SA[SumBucket[S[SA[i] - 1]]--] = SA[i] - 1; 
      }
    }
  }
  register char flg(0)/*�Ƿ�����*/;
  register unsigned CntLMS(0)/*���ʲ�ͬ�� LMS �Ӵ�����*/, Pre(N)/*��һ�� LMS �Ӵ����*/, *Pointer(SA + N + 1)/*LMS �Ӵ��� SA ��ͷָ��*/;
  for (register unsigned i(2); i <= N; ++i) {           // ɨ���ҳ� LMS, ���ز����� 
    if(Type[SA[i]] && (!Type[SA[i] - 1])) {
      if(Pre ^ N && Equal(S, Type, SA[i], Pre)) {       // ��������
        S[S_S1[SA[i]]] = CntLMS;                        // ���� 
        flg = 1;
      }
      else {
        S[S_S1[SA[i]]] = ++CntLMS;                      // ���� 
      }
      Pre = SA[i];                                      // �������� 
      *(++Pointer) = S_S1[SA[i]] - N;                   // ��¼ LMS 
    }
  }
  S[LMSR] = 0;
  SA[N + 1] = LMSR - N;                                 // ĩβ�մ���С 
  if(flg) {                                             // ���ظ� LMS �Ӵ�, �ݹ����� S1 
    Induc(Address + N, Type + N, SA + N, S + N, S_S1 + N, Bucket + bucketSize + 1, SumBucket + bucketSize + 1, LMSR - N); //���ظ�, ���յ� SA1, �µ� Bucket ֱ�ӽ��ں��� 
  }
  return;                                               // �ݹ�����, ��֤ SA1 ���ϸ��
}
void Induc (unsigned *Address, char *Type, unsigned *SA, unsigned *S, unsigned *S_S1, unsigned *Bucket, unsigned *SumBucket, unsigned N) {// �յ� SA
  for (register unsigned i(1), j(1); i < N; ++i) {      // ���� S/L 
    if(S[i] < S[i + 1]) {                               // Suff[j~i] �� S-Type 
      while (j <= i) {
        Type[j++] = 1;
      }
    }
    if(S[i] > S[i + 1]) {                               // Suff[j~i] �� L-Type 
      while (j <= i) {
        Type[j++] = 0;
      }
    }
  }
  Type[N] = 1;
  Type[0] = 1;
  register unsigned CntLMS(N)/*��¼ LMS �ַ�����*/;
  for (register unsigned i(1); i < N; ++i) {            // ��¼ S1 ���ַ���Ӧ�� S �� LMS �Ӵ���� LMS �ַ���λ�� Address[], �� S �е� LMS �Ӵ��� S1 �е�λ�� S_S1[] 
    if(!Type[i]) {
      if(Type[i + 1]) {
        Address[++CntLMS] = i + 1;
        S_S1[i + 1] = CntLMS;
      }
    }
  }
  register unsigned bucketSize(0);                      // ���εݹ��ַ�����С 
  for (register unsigned i(1); i <= N; ++i) {           // ȷ�� Bucket, ������������ SumBucket 
    ++Bucket[S[i]];
    bucketSize = bucketSize < S[i] ? S[i] : bucketSize; // ͳ�� Bucket �Ŀռ䷶Χ 
  }
  Induced_Sort(Address, Type, SA, S, S_S1, Bucket, SumBucket, N, bucketSize, CntLMS);// �յ����� LMS �Ӵ�, �� SA1 
  memset(SA + 1, 0, sizeof(unsigned) * N);              // ���� SA1 ʱҲ����һ�� SA, ���������� 
  SumBucket[0] = 1;                                     // SA1 �������, ��ʼ�յ� SA 
  for (register unsigned i(1); i <= bucketSize; ++i) {  // ����ÿ��ջ��ջ�� (�Ҷ�) 
    SumBucket[i] = SumBucket[i - 1] + Bucket[i];
  }
  for (register unsigned i(CntLMS); i > N; --i) {       // �� LMS ��׺ 
    SA[SumBucket[S[Address[SA[i] + N]]]--] = Address[SA[i] + N];
  }
  SumBucket[0] = 1;
  for (register unsigned i(1); i <= bucketSize; ++i) {  // ����ÿ��ջ��ջ�� (���) 
    SumBucket[i] = SumBucket[i - 1] + Bucket[i];
  }
  for (register unsigned i(1); i <= N; ++i) {           // ������ɨ SA ���� 
    if(SA[i] && (SA[i] - 1)) {
      if(!Type[SA[i] - 1]) {                            // Suff[SA[i] - 1] �� L-Type 
        SA[++SumBucket[S[SA[i] - 1] - 1]] = SA[i] - 1; 
      }
    }
  }
  SumBucket[0] = 1;
  for (register unsigned i(1); i <= bucketSize; ++i) {  // ����ÿ��ջ��ջ�� (�Ҷ�) 
    SumBucket[i] = SumBucket[i - 1] + Bucket[i];
  }
  for (register unsigned i(N); i >= 1; --i) {           // ��������ɨ SA ���� 
    if(SA[i] && (SA[i] - 1)) {
      if(Type[SA[i] - 1]) {                             // Suff[SA[i] - 1] �� S-Type 
        SA[SumBucket[S[SA[i] - 1]]--] = SA[i] - 1; 
      }
    }
  }
  return;
}
int main() {
  fread(TypePool + 1, 1, 1000004, stdin);
  for (register unsigned i(1); ; ++i) {   // ����ѹ���ַ��� 
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
  SPool[n] = 0;// ���һλ��մ�, ��Ϊ�ڱ� 
  Induc (AddressPool, TypePool, SAPool, SPool, S_S1Pool, BucketPool, SumBucketPool, n);
  for (register unsigned i(2); i <= n; ++i) { // SA[1] ����С�ĺ�׺, �㷨�н��մ���Ϊ��С�ĺ�׺, ���Բ���� SA[1] 
    printf("%u ", SAPool[i]);
  }
  return Wild_Donkey;
}
