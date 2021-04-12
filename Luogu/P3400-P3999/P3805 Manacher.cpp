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
unsigned m, n, Cnt(0), Frontier(0), t, Ans(0), Tmp(0), f1[11000005], f2[11000005];
bool b[10005];
char a[11000005];
inline void Clr() {}
int main() {
  // double Ti(clock()), Mti(0);
//   freopen("P3805_1.in", "r", stdin);
  // freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
	fread(a+1,1,11000000,stdin);        // fread �Ż� 
  n = strlen(a + 1);                  // �ַ������� 
  a[0] = 'A';
  a[n + 1] = 'B';                     // �ڱ� 
  for (register unsigned i(1); i <= n; ++i) { // ���� f1 
    if(i + 1 > Frontier + f1[Frontier]) {     // ���� 
      while (!(a[i - f1[i]] ^ a[i + f1[i]])) {
        ++f1[i];
      }
      Frontier = i;
    }
    else {
      register unsigned Reverse((Frontier << 1) - i), A(Reverse - f1[Reverse]), B(Frontier - f1[Frontier]);
      f1[i] = Reverse - ((A < B) ? B : A);
      if (!(Reverse - f1[Reverse] ^ Frontier - f1[Frontier])) { // ������� 
        while (!(a[i - f1[i]] ^ a[i + f1[i]])) {
          ++f1[i];
        }
        Frontier = i;
      }
    }
    Ans = ((Ans < f1[i]) ? f1[i] : Ans);
  }
  Ans = (Ans << 1) - 1;
  Frontier = 0;
  for (register unsigned i(1); i <= n; ++i) {
    if(i + 1 > Frontier + f2[Frontier]) {
      while (!(a[i - f2[i] - 1] ^ a[i + f2[i]])) {
        ++f2[i];
      }
      Frontier = i;
    }
    else {
      register unsigned Reverse ((Frontier << 1) - i - 1), A(Reverse - f2[Reverse]), B(Frontier - f2[Frontier]);
        f2[i] = Reverse - ((A < B) ? B : A);
      if (A == B) { // ������� 
        while (a[i - f2[i] - 1] == a[i + f2[i]]) {
          ++f2[i];
        }
        Frontier = i;
      }
    }
//    printf("i:%u f2:%u\n", i, f2[i]);
    Tmp = ((Tmp < f2[i]) ? f2[i] : Tmp);
  }
  printf("%u\n", max(Ans, (Tmp << 1)));
  return Wild_Donkey;
}


