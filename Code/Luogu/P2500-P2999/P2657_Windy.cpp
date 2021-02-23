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
const unsigned Ten[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
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
unsigned int a[10005], f[11][11][11], m, n, Cnt(0), A, B, C, D, t, La, Lb, Ansa(0), Ansb(0), Ans(0);
bool b[10005];
char s[10005];
inline void Clr() {
  n = RD();
  memset(a, 0, sizeof(a));
}
inline unsigned Getlen (unsigned x) {
  unsigned tmp(0);
  while(x) {
    x /= 10;
    ++tmp;
  }
  return tmp;
}
inline bool Jdg (const unsigned &x, const unsigned &y) {
  if (x < y) {
    return y - x > 1;
  }
  return x - y > 1;
}
void Qry (unsigned &ans, unsigned x, const unsigned &Len) {
  if(!x) {
    ans = 0;
    return;
  }
  unsigned now(x / Ten[Len - 1]), tmp(11);
  for (register unsigned i(1); i < Len; ++i) {//len
    for (register unsigned j(1); j < 10; ++j) {//begin
      for (register unsigned k(0); k < 10; ++k) {//end
        ans += f[i][j][k];//shorter
      }
    }
  }
  for (register unsigned i(Len); i >= 1; --i) {//len
    now = x / Ten[i - 1];//this number
    for (register unsigned j(i == Len ? 1 : 0); (i == 1 ? j <= now : j < now); ++j) {//begin
      if(Jdg(j, tmp)) {//last
        for (register unsigned k(0); k < 10; ++k) {//end
          ans += f[i][j][k];
        }
      }
    }
    if(!Jdg(now, tmp)) {
      break;
    }
    x -= Ten[i - 1] * now;
    tmp = now;//this num
  }
//  ++ans;
}
int main() {
  // double Ti(clock()), Mti(0);
//   freopen("P2657.in", "r", stdin);
//   freopen("P2657.out", "w", stdout);
  A = RD() - 1;
  La = Getlen(A);
  B = RD();
  Lb = Getlen(B);
  memset(f, 0, sizeof(f));
//  memset()
//  printf("%u %u\n", La, Lb);
  for (register unsigned i(0); i < 10; ++i) {//begin & end
    f[1][i][i] = 1;
  }
  for (register unsigned i(2); i <= Lb; ++i) {//len
    for (register unsigned j(0); j < 10; ++j) {//begin
      for (register unsigned k(0); k < 10; ++k) {//end
        for (register unsigned i_(0); i_ < 10; ++i_) {//lastend
          if (Jdg(i_, k)) {
            f[i][j][k] += f[i - 1][j][i_];
          }
        }
//        printf("f[%u][%u][%u]%u ", i, j, k, f[i][j][k]);
      }
//      putchar('\n');
    }
  }
//  for (register unsigned i(1); i < 10; ++i) {
//    for (register unsigned j(0); j < 10; ++j) {
//      Ans += f[Lb][i][j];
//    }
//  }
  Qry (Ansa, A, La);
  Qry (Ansb, B, Lb);
//  printf("%u %u %u\n", Ansa, Ansb, Ansb - Ansa);
  printf("%u\n", Ansb - Ansa);
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
/*
25 50
18 38 20
*/
