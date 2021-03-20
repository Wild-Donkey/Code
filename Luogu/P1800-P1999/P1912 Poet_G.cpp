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
#define unsigned int
using namespace std;
const long long INF(0x3f3f3f3f3f3f3f3f);
const long long List[11] = {1000000000000000000, 1000000000000000000, 1000000000, 1000000, 31622, 3981, 1000, 372, 177, 100, 63}; 
long long Power (long long x, unsigned y) {
  if (!y) {
    return 1;
  }
  long long tmp(Power(x * x, y >> 1));
  if(y & 1) {
    return tmp * x;
  }
  return tmp;
}
bool flg;
int Prt[100005];
unsigned a[100005], n, Cnt(0), He, Ta, t, L, P;
long long Sum[100005], f[100005];
char Poem[100005][31];
struct Line {
  unsigned Adre, l, r;
}Li[100005];
void Clr() {
//  n = RD();
//  L = RD();
//  P = RD();
  scanf("%u%u%u", &n, &L, &P);
  memset(Prt, 0, sizeof(Prt));
  memset(f, 0, sizeof(f));
  memset(Sum, 0, sizeof(Sum));
  memset(Poem, 0, sizeof(Poem));
  memset(a, 0, sizeof(a));
  memset(Li, 0, sizeof(Li));
  flg = 0;
  He = 1;         // ���� 
  Ta = 1;
  Li[1].Adre = 0; // �� 0 ת�� 
  Li[1].l = 1;
  Li[1].r = n; 
  f[0] = 0;       // �׶� 0 �� 0 
  Sum[0] = 0;
  for (register unsigned i(1); i <= n; ++i) {
    scanf("%s", Poem[i]);
    a[i] = strlen(Poem[i]);
  }
  return;
}
long long DoPower (long long x) { // ���жϵ����Ŀ�������� 
  if (x < 0) {
    x = -x;
  }
  if (x > List[P]) {
    flg = 1;
    return INF;
  }
  return Power(x, P);
}
long long Decision (unsigned x/*�׶�*/, unsigned y/*����*/) {
  if(x == y) {
    return INF;
  }
  long long tmp = DoPower(Sum[x] - Sum[y] - 1 - L); // ����ֵ��������Ķ���(Sum[i] != sum[i]) 
  if(tmp > 1000000000000000000) { // ��ը 
    flg = 1;
    return INF;
  }
  tmp += f[y]; 
  if (tmp > 1000000000000000000) {
    flg = 1;
    return INF;
  }
  return tmp; 
}
void Bin (unsigned x/*�¾����±�*/, unsigned le, unsigned ri) { // �����ڶ��ֲ��� 
  if (le == ri) {  // ����һ������ 
    Li[Ta].r = le - 1;
    Li[++Ta].l = le;
    Li[Ta].r = n;
    Li[Ta].Adre = x;
    return;
  }
  unsigned mid((le + ri) >> 1);
//  printf("(%u, %u) = %lld, (%u, %u) = %lld\n", mid, x, Decision(mid, x), mid, Li[Ta].Adre, Decision(mid, Li[Ta].Adre));
  if (Decision(mid, x) <= Decision(mid, Li[Ta].Adre)) { // x ��Ϊ�׶� mid �ľ��߸��� 
    return Bin(x, le, mid);
  }
  return Bin(x, mid + 1, ri);
}
void Best (unsigned x) {
  while (He < Ta && Decision(Li[Ta].l, Li[Ta].Adre) >= Decision(Li[Ta].l, x)) { // ���� x ������������ʾ�Ľ׶θ��� 
    --Ta; // ������������ 
  }
  if (Decision(Li[Ta].r, Li[Ta].Adre) >= Decision(Li[Ta].r, x)) { 
    Bin(x, Li[Ta].l, Li[Ta].r);
  }
  else {
    ++Ta;
    Li[Ta].l = Li[Ta - 1].r + 1;
//    printf("%u %u\n", Ta - 1, Li[Ta - 1].r, );
    Li[Ta].r = n;
    Li[Ta].Adre = x;
  }
  while (He < Ta && Li[He].r <= x) {  // ��ʱ���� 
    ++He;
  }
  return;
}
void Print () {
  int now(n);  // ��һ�е����һ�仰��� 
  Cnt = 0;
  Prt[0] = n + 1;
  while (now) { // ���о��� 
    while (Ta > 1 && Li[Ta].l > now) {  // �ҵ��׶� now �ľ��� 
      --Ta;
    }
//    printf("%lld %lld %u %u %u\n", now, Ta, Li[Ta].Adre, Li[Ta].l, Li[Ta].r);
    if(now == Li[Ta].Adre) {
      Sum[INF] = 0;
    }
    now = Li[Ta].Adre; // ��������һ�����һ�� 
    Prt[++Cnt] = now + 1; // ��һ�е�һ�� 
  }
  for (register unsigned i(Cnt); i >= 1; --i) {
    for (register int j(Prt[i]); j <= Prt[i - 1] - 2/*��һ�е����ڶ���*/; ++j) {
      printf("%s ", Poem[j]);
    }
    printf("%s", Poem[Prt[i - 1] - 1]); // ���һ���޿ո� 
    putchar('\n');
//    printf("")
  }
  return;
}
int main() {
  // double Ti(clock()), Mti(0);
   freopen("P1912_2.in", "r", stdin);
//   freopen("P1912.out", "w", stdout);
//  for (register unsigned i(0); i <= 10; ++i) {
//    printf("%lld %lld %lld\n", i, Power(List[i], i), List[i]);
//  }
  scanf("%u", &t);
  for (register unsigned T(1); T <= t; ++T){
    Clr();
    for (register unsigned i(1); i <= n; ++i) {
      Sum[i] = Sum[i - 1] + a[i] + 1;
    }
    for (register unsigned i(1); i < n; ++i) {
      f[i] = Decision(i, Li[He].Adre);  // ���Ѿ���������ž���ת�� 
      if (f[i] > 1000000000000000000) { // ֱ����� 
        break;
      }
//      printf ("%lld %lld %u %u %u %lld\n", i, He, Li[He].Adre, Li[He].l, Li[He].r, f[i]); 
      Best(i); // �������� p 
    }
    f[n] = Decision(n, Li[He].Adre);  // ���Ѿ���������ž���ת�� 
    if (f[n] > 1000000000000000000) { // ֱ����� 
      flg = 1;
    }
//    printf ("%lld %lld %lld %lld\n", He, Li[He].Adre, Li[He].l, Li[He].r); 
    if (flg) {
      printf("Too hard to arrange\n");
    }
    else {
      printf("%lld\n", f[n]);
      Print(); 
    }
    for (register unsigned i(1); i <= 20; ++i){
      putchar('-');
    }
    if(T < t) {
      putchar('\n');
    }
  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
