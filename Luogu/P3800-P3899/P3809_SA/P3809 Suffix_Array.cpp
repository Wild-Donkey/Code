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
unsigned m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0), Bucket[1000005], sumBucket[1000005], Tmpch[64], a[1000005], b[1000005];
char Inch[1000005];
struct Suffix {
  unsigned RK, SubRK;
}S[1000005], Stmp[1000005];
void RadixSort () {
  unsigned MX(0);                                     // ��¼����ֵ 
  for (register unsigned i(1); i <= n; ++i) {
    ++Bucket[S[i].SubRK];                             // �ڶ��ؼ�����Ͱ
    MX = max(S[i].SubRK, MX);
  }
  sumBucket[0] = 0;
  for (register unsigned i(1); i <= MX; ++i) {        // ��ǰ׺����ȷ���������������е�λ��
    sumBucket[i] = sumBucket[i - 1] + Bucket[i - 1];  // ��Ͱǰ׺��, ǰ׺���ұ߽��ǿ�����, ���Լ�����Ǳ������ֵС������Ԫ�ظ��� 
    Bucket[i - 1] = 0;                                // ���Ͱ 
  }
  Bucket[MX] = 0;
  for (register unsigned i(1); i <= n; ++i) {         // �źõ��±�浽 b ��, �� b[i] Ϊ�� i С�ĺ�׺��� 
    b[++sumBucket[S[i].SubRK]] = i;                   // ǰ׺����������Ϊ 
  }
  b[0] = 0;                                           // �߽� (�� 0 С�Ĳ�����) 
  for (register unsigned i(1); i <= n; ++i) {
    a[i] = b[i];
  }
  MX = 0; 
  for (register unsigned i(1); i <= n; ++i) {
    ++Bucket[S[i].RK];                                // ��һ�ؼ�����Ͱ
    MX = max(S[i].RK, MX);
  }
  sumBucket[0] = 0;
  for (register unsigned i(1); i <= MX; ++i) {
    sumBucket[i] = sumBucket[i - 1] + Bucket[i - 1];
    Bucket[i - 1] = 0;
  }
  Bucket[MX] = 0;
  for (register unsigned i(1); i <= n; ++i) {
    b[++sumBucket[S[a[i]].RK]] = a[i];                // ���� a[i] �� b[i] �Ŀ���, ��ʾ�� i С�ĺ�׺���, ����ö�� i һ���Ǵ���С�ĺ�׺��ʼ�����������µ� b 
  }
  b[0] = 0;
  Cnt = 0;                                            // ʹ RK ����ô��ɢ 
  for (register unsigned i(1); i <= n; ++i) {
    if(S[b[i]].SubRK != S[b[i - 1]].SubRK || S[b[i]].RK != S[b[i - 1]].RK) {
      a[b[i]] = ++Cnt;                                // �� i С�ĺ�׺�͵� i - 1 С�ĺ�׺������������ 
    }
    else {
      a[b[i]] = Cnt;                                  // �� i С�ĺ�׺�͵� i - 1 С�ĺ�׺�������Ҳ��� 
    }
  }
  for (register unsigned i(1); i <= n; ++i) {
    S[i].RK = a[i];                                   // �� a ���ݴ���´��򿽱����� 
  }
  return;
}
int main() {
  // double Ti(clock()), Mti(0);
//   freopen("P3809_2.in", "r", stdin);
//   freopen("P3809.out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  cin.getline(Inch, 1000001);
  n = strlen(Inch);
  for (register unsigned i(0); i < n; ++i) {
    if(Inch[i] <= '9' && Inch[i] >= '0') {
      Inch[i] -= 47;
      continue;
    }
    if(Inch[i] <= 'Z' && Inch[i] >= 'A') {
      Inch[i] -= 53;
      continue;
    }
    if(Inch[i] <= 'z' && Inch[i] >= 'a') {
      Inch[i] -= 59;
      continue;
    }
  }
  for (register unsigned i(0); i < n; ++i) {
    Bucket[Inch[i]] = 1;
  }
  for (register unsigned i(0); i < 64; ++i) {
    if(Bucket[i]) {
      Tmpch[i] = ++Cnt;                               // ��Ͱ�� 1 ��ʼ, �ճ� 0 ��λ��
      Bucket[i] = 0;
    }
  }
  for (register unsigned i(0); i < n; ++i) {          // ���ַ�����ɢ������������
      S[i + 1].RK = Tmpch[Inch[i]];                   // �ַ��������� [0, n) ��, �������ַ����� (0, n] �� 
  }
  for (register unsigned i(1); i <= n; i <<= 1) {     // ��ǰ��ǰ i ���ַ�������, ÿ�� i ����
    for (register unsigned j(1); j + i <= n; ++j) {   // ��Եڶ��ؼ��ֲ�Ϊ 0 �� 
      S[j].SubRK = S[j + i].RK;
    }
    for (register unsigned j(n - i + 1); j <= n; ++j) {  
      S[j].SubRK = 0;                                 // �ڶ��ؼ���Ϊ 0 
    }
    RadixSort();
  }
  for (register unsigned i(1); i <= n; ++i) {
    b[S[i].RK] = i;
  }
  for (register unsigned i(1); i <= n; ++i) {
    printf("%u ", b[i]);
  }
//  printf("%s\n", a);
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}



