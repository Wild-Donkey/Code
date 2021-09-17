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
unsigned m, n, Cnt(0), A, B, C, t, Ans(0), Fa[150050];
inline unsigned Find (unsigned x) {
  register unsigned now(x);
  while (Fa[now] ^ now) now = Fa[now];
  return Fa[x] = now; // ·��ѹ�� 
}
int main() {
  n = RD(), m = RD();
  t = n * 3 + 3;  // �ܵ��� 
  for (register unsigned i(1); i <= t; ++i) { // ��ʼ�� 
    Fa[i] = i;
  }
  for (register unsigned i(1); i <= m; ++i) {
    if(RD() & 1) {
      A = RD(), B = RD();
      if(A > n || B > n) {
        ++Ans;
        continue;
      }
      if(A == B) {
        continue;
      }
      C = Find(A * 3);
      if (C == Find((B * 3) + 1) || C == Find((B * 3) + 2)) { // A eat B or B eat A ��ϵ���� 
        ++Ans;
        continue;
      }
      if (C ^ Find(B * 3)) {  // ������ϵ 
        Fa[C] = Fa[B * 3];                      // �ҵ�ͬ���ͬ�������Լ�, �� A �ĵ�һ����� B �ĵ�һ����ϲ�
        Fa[Find((A * 3) + 1)] = Fa[(B * 3) + 1];// �ҵ�ͬ���������ҵ����, �� A �ĵڶ������ B �ĵڶ�����ϲ� 
        Fa[Find((A * 3) + 2)] = Fa[(B * 3) + 2];// �ҵ�ͬ���ʳ�����ҵ�ʳ��, �� A �ĵ�������� B �ĵ�������ϲ� 
      }
    } else {
      A = RD(), B = RD();
      if(A == B || A > n || B > n) {  // �ҳ����Լ��򳬳���Χ
        ++Ans;
        continue;
      }
      C = Find(A * 3);
      if (C == Find(B * 3) || C == Find((B * 3) + 2)) { // A �� B ��ͬ���ʳ��, ��ϵ���� 
        ++Ans;
        continue;
      }
      if (C ^ Find((B * 3) + 1)) {  // ������ϵ 
        Fa[C] = Fa[(B * 3) + 1];                // �ҵ�ʳ�����������Լ�, �� A �ĵ�һ����� B �ĵڶ�����ϲ�
        Fa[Find((A * 3) + 2)] = Fa[B * 3];      // �ҵ�ʳ���ͬ�����ҵ�ʳ��, �� A �ĵ�������� B �ĵ�һ����ϲ�
        Fa[Find((A * 3) + 1)] = Fa[(B * 3) + 2];// �ҵ�ʳ���ʳ�����ҵ����, �� A �ĵڶ������ B �ĵ�������ϲ�
      }
    }
  }
  printf("%u\n", Ans);
  return Wild_Donkey;
}
