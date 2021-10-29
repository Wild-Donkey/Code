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
#define Abs(x) ((x) > 0 ? (x) : -(x))
#define Do(x, y) (f[(x)] + Power(Abs(Sum[y] - Sum[x] - 1 - L), P))
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
inline long double Power(long double x, unsigned y) {
  if (!y) {
    return 1;
  }
  if (y & 1) {
    return Power(x * x, y >> 1) * x;
  }
  return Power(x * x, y >> 1);
}
bool flg;
int Prt[100005];
unsigned a[100005], n, Cnt(0), He, Ta, t, P;
long double L, Sum[100005], f[100005];
char Poem[100005][31];
struct Line {
  unsigned Adre, l, r;
} Li[100005];
inline void Clr() {
  n = RD();
  L = RD();
  P = RD();
  flg = 0;
  He = 1;  // ����
  Ta = 1;
  Li[1].Adre = 0;  // �� 0 ת��
  Li[1].l = 1;
  Li[1].r = n;
  f[0] = 0;  // �׶� 0 �� 0
  Sum[0] = 0;
  char chtmp(getchar());
  for (register unsigned i(1); i <= n; ++i) {
    while (chtmp < 33 || chtmp > 127) {
      chtmp = getchar();
    }
    a[i] = 0;
    while (chtmp >= 33 && chtmp <= 127) {
      Poem[i][a[i]++] = chtmp;
      chtmp = getchar();
    }
  }
  return;
}
inline void Bin(unsigned x /*�¾����±�*/, unsigned le,
                unsigned ri) {  // �����ڶ��ֲ���
  if (le == ri) {               // ����һ������
    Li[Ta].r = le - 1;
    Li[++Ta].l = le;
    Li[Ta].r = n;
    Li[Ta].Adre = x;
    return;
  }
  unsigned m((le + ri) >> 1);
  if (Do(x, m) <= Do(Li[Ta].Adre, m)) {  // x ��Ϊ�׶� mid �ľ��߸���
    return Bin(x, le, m);
  }
  return Bin(x, m + 1, ri);
}
void Best(unsigned x) {
  while (He < Ta && Do(Li[Ta].Adre, Li[Ta].l) >=
                        Do(x, Li[Ta].l)) {  // ���� x ������������ʾ�Ľ׶θ���
    --Ta;                                   // ������������
  }
  if (Do(Li[Ta].Adre, Li[Ta].r) >=
      Do(x, Li[Ta].r)) {  // ���� x ���������յ���� (����һ���׶θ� x)
    Bin(x, Li[Ta].l, Li[Ta].r);
  } else {
    if (Li[Ta].r != n) {
      ++Ta;
      Li[Ta].l = Li[Ta - 1].r + 1;
      Li[Ta].r = n;
      Li[Ta].Adre = x;
    }
  }
  while (He < Ta && Li[He].r <= x) {  // ��ʱ����
    ++He;
  }
  Li[He].l = x + 1;
  return;
}
inline void Back(unsigned x) {
  if (Prt[x]) {
    Back(Prt[x]);
  }
  for (register unsigned i(Prt[x] + 1); i < x; ++i) {
    for (register short j(0); j < a[i]; ++j) {
      putchar(Poem[i][j]);
    }
    putchar(' ');
  }
  for (register short i(0); i < a[x]; ++i) {
    putchar(Poem[x][i]);
  }
  putchar('\n');
}
inline void Print() {
  Cnt = 0;
  Prt[0] = 0;
  Back(n);
  return;
}
int main() {
  t = RD();
  for (register unsigned T(1); T <= t; ++T) {
    Clr();
    for (register unsigned i(1); i <= n; ++i) {
      Sum[i] = Sum[i - 1] + a[i] + 1;
    }
    for (register unsigned i(1); i < n; ++i) {
      f[i] = Do(Li[He].Adre, i);  // ���Ѿ���������ž���ת��
      Prt[i] = Li[He].Adre;
      Best(i);  // �������� p
    }
    f[n] = Do(Li[He].Adre, n);  // ���Ѿ���������ž���ת��
    Prt[n] = Li[He].Adre;
    if (f[n] > 1000000000000000000) {  // ֱ�����
      printf("Too hard to arrange\n");
    } else {
      printf("%lld\n", (long long)f[n]);
      Print();
    }
    for (register short i(1); i <= 20; ++i) {
      putchar('-');
    }
    if (T < t) {
      putchar('\n');
    }
  }
  return Wild_Donkey;
}
