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
unsigned int m, n, Cnt(0), A, B, C, D, t;
bool b[10005];
char s[10005];
double a[15], Ans(0);
//inline void Clr() 
//{
//  n = RD();
//  memset(a, 0, sizeof(a));
//}
inline double Helen (double x, double y, double z) {
  double _, __;
  _ = (x + y + z) / 2;
  return sqrt(_ * (_ - x) * (_ - y) * (_ - z));
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  for (register unsigned int i(1); i <= 7; ++i) {
    a[i] = RD();
  }
  Ans += Helen(a[1], a[5], a[6]);
  Ans += Helen(a[2], a[6], a[7]);
  Ans += Helen(a[3], a[4], a[7]); 
  printf("%.2lf", Ans);
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}


