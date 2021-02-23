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
inline unsigned int RD() {
  unsigned int intmp = 0;
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
unsigned int a[10005], m, n, Cnt(0), A, B, C, D, t;
bool b[10005];
char s[10005];
float f, f_;
inline void Clr() {
  n = RD();
  memset(a, 0, sizeof(a));
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  A = RDsg();
  B = RDsg();
  C = RDsg();
  if(A >= B && A >= C) {
    printf("%d ", A);
    if(B >= C) {
      printf("%d %d\n", B, C);
    }
    else {
      printf("%d %d\n", C, B);
    }
  }
  else {
    if(B >= C) {
      printf("%d ", B);
      if(A >= C) {
        printf("%d %d\n", A, C);
      }
      else {
        printf("%d %d\n", C, A);
      }
    }
    else {
      printf("%d ", C);
      if(A >= B) {
        printf("%d %d\n", A, B);
      }
      else {
        printf("%d %d\n", B, A);
      }
    }
  }
//  freopen("julian3.in", "r", stdin);
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}


