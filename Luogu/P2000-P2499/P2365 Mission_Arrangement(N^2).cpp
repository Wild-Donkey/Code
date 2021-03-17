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
struct Ms {
  long long C, T, SumC, SumT, f;
}M[5005]; // �������� 
struct Hull {
  long long x, y;
  unsigned Ad;
}H[5005], *Now, Then; // ��͹�� 
unsigned n, l(1), r(1);
long long S, Cst; 
int main() {
  n = RD();
  S = RD();
  M[0].SumT = S;
  for (register unsigned i(1); i <= n; ++i) {
    M[i].T = RD();
    M[i].C = RD();
    M[i].SumT = M[i - 1].SumT + M[i].T;
    M[i].SumC = M[i - 1].SumC + M[i].C; //Ԥ���� 
  }
  Cst = S * M[n].SumC;  // �ؾ��е�һ��� 
  for (register unsigned i(1); i <= n; ++i) {
    while (l < r && ((H[l + 1].y - H[l].y) < M[i].SumT * (H[l + 1].x - H[l].x))) {
      ++l; // �����������ߵ� 
    }
    M[i].f = M[H[l].Ad].f + (M[i].SumC - M[H[l].Ad].SumC) * M[i].SumT + Cst - M[i].SumC * S; // ת�� 
    Then.Ad = i;
    Then.x = M[i].SumC;
    Then.y = M[i].f;    // ���µ����� 
    while (l < r && ((Then.y - H[r].y) * (H[r].x - H[r - 1].x) <= (H[r].y - H[r - 1].y) * (Then.x - H[r].x))) {
      --r; // ά����͹ 
    }
    H[++r] = Then;      // ��� 
  }
  printf("%lld\n", M[n].f);
  return Wild_Donkey;
}



