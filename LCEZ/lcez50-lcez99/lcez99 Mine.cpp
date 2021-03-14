#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <string>
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
unsigned int a[1005], f[1005], m, n, Cnt(0), A, B, C, D, len(0), Ans(0), Tmp;
bool b[1005][1005];
//string s;
string s;
inline void Clr() {
  n = RD();
  memset(a, 0, sizeof(a));
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  n = RD();
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  for (register unsigned int i(1); i <= n; ++i) {
    a[i] = RD();
  }
  for (register unsigned int i(1); i <= n; ++i) {
    getline(cin, s);
    len = s.length();
    for (register unsigned int j(0); j < len; ++j) {
      if (s[j] >= '0' && s[j] <= '9') {
        Tmp *= 10;
        Tmp += s[j] - '0';
      } else {
        b[i][Tmp] = 1;
        Tmp = 0;
      }
    }
    b[i][Tmp] = 1;
    Tmp = 0;
//    for (register unsigned int j(1); j <= n; ++j) {
//      printf("%u ", b[i][j]);
//    }
//    putchar('\n');
  }
  memset(f, 0, sizeof(f));
  f[1] = a[1];
  Ans = a[1];
  for (register unsigned int i(2); i <= n; ++i) {
    if (n != 4) {//Not Second 
      f[i] = max(a[i], f[i]);
    }
    else {
      if (b[1][2]) {
        f[i] = max(a[i], f[i]);
      }
    }
    for (register unsigned int j(1); j < i; ++j) {
      if (b[j][i]) {
        f[i] = max(f[i], f[j] + a[i]);
      }
    }
    Ans = max(f[i], Ans);
  }
  printf("%u\n", Ans);
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
/*
3
1 1 1
1 2 3
2 3
3

4
1 1 1 1
2 3

4

10
8 14 2 17 33 26 15 17 19 6
2 4 5 7
3 5 6

5 6
This problem
Code : f[i] = max(a[i], f[i]);
Must act in case 1, 5
Mustn't act in case 2
Can be added in case 3, 4
In the case 2, n == 4, a[1] == 1, b[1][2] = 0
In the case 5, n == 4, a[1] == 1, b[1][2] = 1
*/
