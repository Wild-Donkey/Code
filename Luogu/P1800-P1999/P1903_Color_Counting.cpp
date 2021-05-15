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
unsigned a[140005], b[280005], m, n, N, CntQ(0), Cnt[280005], C, D, t, Ans[140005], Tmp(0), Time(1), BlockLen, Num(0), List[280005];
char B;
struct Query {
  unsigned L, R, Ti, LBelongBlock, RBelongBlock, Rank;
  inline const char operator<(const Query &x) {
    return (this->LBelongBlock ^ x.LBelongBlock) ? (this->LBelongBlock < x.LBelongBlock) : ((this->RBelongBlock ^ x.RBelongBlock) ? (this->RBelongBlock < x.RBelongBlock) : x.Ti < this->Ti);
  }
}Q[140005];
struct Edit {
  unsigned Address, Value, Origin;
}E[140005];
int main() {
  N = n = RD(), m = RD(); // N �ǵ�ɫ��Ĵ�С, ֮����� n �Ļ��������� 
  for (register unsigned i(1); i <= n; ++i) a[i] = RD();
  memcpy(b, a, (n + 1) * sizeof(unsigned)); // ��ʱ�� a[] ��û��û�޸� 
  for (register unsigned i(1); i <= m; ++i) {
    scanf("\n"), B = getchar();
    if(B ^ 'Q') {
      E[++Time].Address = RD();
      b[++N] = E[Time].Value = RD();        // ����ɫ�����ɫ�� 
      E[Time].Origin = a[E[Time].Address];  // ��¼�޸�ǰ����ɫ 
      a[E[Time].Address] = E[Time].Value;   // �� a[] ���޸���ɫ 
    } else {
      Q[++CntQ].L = RD();
      Q[CntQ].R = RD();
      Q[CntQ].Rank = CntQ;
      Q[CntQ].Ti = Time;
    }
  }
  BlockLen = (pow((unsigned long long)n * n * Time / m, 1.0/3) * 3.125) + 1; // ���ſ鳤 
//  printf("BlockLen %u\n", BlockLen); 
  sort(b + 1, b + N + 1);
  for (register unsigned i(1); i <= N; ++i) // ��ɢ����ȥ�� 
    if(b[i] ^ b[i - 1])
      List[++Num] = b[i];
  for (register unsigned i(1); i <= n; ++i) {
    a[i] = lower_bound(List + 1, List + Num + 1, a[i]) - List;
  }
  for (register unsigned i(1); i <= Time; ++i) {
    E[i].Origin = lower_bound(List + 1, List + Num + 1, E[i].Origin) - List;
    E[i].Value = lower_bound(List + 1, List + Num + 1, E[i].Value) - List;
  }
  for (register unsigned i(1); i <= CntQ; ++i) {
    Q[i].LBelongBlock = (Q[i].L + BlockLen - 1) / BlockLen;
    Q[i].RBelongBlock = (Q[i].R + BlockLen - 1) / BlockLen;
  }
  sort(Q + 1, Q + CntQ + 1);
  Q[0].Ti = Time, Q[0].L = 1, Q[0].R = 1, Ans[0] = 1, Cnt[a[1]] = 1;
  for (register unsigned i(1); i <= CntQ; ++i) {
    while(Q[0].Ti < Q[i].Ti) {  // ʱ������ 
      if(E[++Q[0].Ti].Address <= Q[0].R && E[Q[0].Ti].Address >= Q[0].L) {
        Ans[0] -= !(--Cnt[a[E[Q[0].Ti].Address]]); // ���һ����ɫ a[E[Q[0].Ti].Address]
        a[E[Q[0].Ti].Address] = E[Q[0].Ti].Value;
        Ans[0] += !(Cnt[a[E[Q[0].Ti].Address]]++);// �׸���ɫ a[E[Q[0].Ti].Address]
      } else {
        a[E[Q[0].Ti].Address] = E[Q[0].Ti].Value;
      }
    }
    while(Q[0].Ti > Q[i].Ti) {  // ʱ�䵹�� 
      if(E[Q[0].Ti].Address <= Q[0].R && E[Q[0].Ti].Address >= Q[0].L){
        Ans[0] -= !(--Cnt[a[E[Q[0].Ti].Address]]);
        a[E[Q[0].Ti].Address] = E[Q[0].Ti].Origin;
        Ans[0] += !(Cnt[a[E[Q[0].Ti].Address]]++);
      }
      else {
        a[E[Q[0].Ti].Address] = E[Q[0].Ti].Origin;
      }
      --(Q[0].Ti); 
    }
    while(Q[0].L > Q[i].L) Ans[0] += !(Cnt[a[--Q[0].L]]++); // ��˵�����
    while(Q[0].R < Q[i].R) Ans[0] += !(Cnt[a[++Q[0].R]]++); // �Ҷ˵�����
    while(Q[0].L < Q[i].L) Ans[0] -= !(--Cnt[a[Q[0].L++]]); // ��˵�����
    while(Q[0].R > Q[i].R) Ans[0] -= !(--Cnt[a[Q[0].R--]]); // �Ҷ˵�����
    Ans[Q[i].Rank] = Ans[0];  // ͳ�ƴ� 
  }
  for (register unsigned i(1); i <= CntQ; ++i) {
    printf("%u\n", Ans[i]);
  }
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}


