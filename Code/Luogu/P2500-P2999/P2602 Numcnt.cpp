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
const unsigned long long Ten[14] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000, 100000000000, 1000000000000, 10000000000000},
Nine[14] = {0, 9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999, 9999999999, 99999999999, 999999999999, 9999999999999};
inline unsigned long long RD() {
  unsigned long long intmp = 0;
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
unsigned long long a[10005], f[14][2], fsum[14][2], A, B, Ansa[10], Ansb[10];
unsigned La, Lb;
bool b[10005];
char s[10005];
inline unsigned Getlen (unsigned long long x) {
  unsigned tmp(0);
  while(x) {
    x /= 10;
    ++tmp;
  }
  return tmp;
}
void Qry (unsigned long long ans[], unsigned long long x, const unsigned &Len) {
  if(!x) {
    return;
  }
  unsigned long long now, tmp;
  for (unsigned i(Len); i > 1; --i) {//now 
//    printf("RE?%u\n", i);
    
    tmp = x / Ten[i - 1]; //the max ith num
    if (tmp) {
      if(i != Len) {
        ans[0] += Ten[i - 1] + fsum[i - 1][1];
      }
      else {
        ans[0] += fsum[i - 1][0];
      }
      for (unsigned j(1); j < 10; ++j) {//xxxx0000~xxxx0999
        ans[j] += fsum[i - 1][1];
      }
      for (unsigned j(0); j < 10; ++j) {//1 ~ i - 1
        ans[j] += fsum[i - 1][1] * (tmp - 1);//0 is the same as 1 ~ 9 at the 1 ~ Len - 1 site
      }
      for (unsigned j(1); j < tmp; ++j) {//ith num
        ans[j] += Ten[i - 1];
      }
    }
    x -= tmp * Ten[i - 1];
    ans[tmp] += x + 1;
  }
  for (register unsigned i((Len == 1 ? 1 : 0)); i <= x; ++i) {
    ++ans[i];
  }
  return;
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  A = RD() - 1;
  La = Getlen(A);
  B = RD();
  Lb = Getlen(B);
  memset(f, 0, sizeof(0));
  memset(Ansa, 0, sizeof(Ansa));
  memset(Ansb, 0, sizeof(Ansb));
  f[1][1] = 1;
  fsum[1][1] = 1;
  for (register unsigned i(2); i <= Lb; ++i) {
    f[i][1] = fsum[i - 1][1] * 9 + Ten[i - 1];
    fsum[i][1] = fsum[i - 1][1] + f[i][1];
//    printf("%u %llu %llu\n", i, f[i][1], fsum[i][1]); 
  }
  for (register unsigned i(2); i <= Lb; ++i) {
    f[i][0] = fsum[i - 1][1] * 9;
    fsum[i][0] = fsum[i - 1][0] + f[i][0];
//    printf("%u %llu %llu\n", i, f[i][0], fsum[i][0]);
  }
  Qry(Ansa, A, La);
  Qry(Ansb, B, Lb);
  for (register unsigned i(0); i < 10; ++i) {
//    printf("%u %llu %llu %llu\n", i, Ansa[i], Ansb[i], Ansb[i] - Ansa[i]);
    printf("%llu ", Ansb[i] - Ansa[i]);
  }
//  for (register unsigned i(900); i <= 1000; ++i) {
//    memset(Ansa, 0, sizeof(Ansa));
//    Qry(Ansa, i, Getlen(i));
//    printf("%u  ", i);
//    for (register unsigned j(0); j < 10; ++j) {
//      printf("%u ", Ansa[j]);
//    }
//    putchar('\n');
//  }
  

  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
////////////////  RD();
//////////////  RD();
////////////  RD();
//////////  RD();
////////  RD();
//////  RD();
////  RD();
//  RD();
}
/*
1 1000
192 301 300 300 300 300 300 300 300 300
1 999
189 300 300 300 300 300 300 300 300 300
1 99
9 20 20 20 20 20 20 20 20 20
1 100
11 21 20 20 20 20 20 20 20 20
1 1000000000000
1088888888901 1200000000001 1200000000000 1200000000000 1200000000000 1200000000000 1200000000000 1200000000000 1200000000000 1200000000000
*/
