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
unsigned int a[11] = {1, 0, 2, 3, 4, 0, 5, 6, 7, 8, 9}, m, n, Cnt(0), A, B, C, D, t, Tmp(0);
bool b[10005];
char s[10005];
inline void Clr() {
  n = RD();
  memset(a, 0, sizeof(a));
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  cin.getline(s, 14);
//  printf("%s\n", s);
  for (register unsigned int i(0); i < 12; ++i) {
    if(s[i] >= '0' && s[i] <= '9') {
      Tmp += (s[i] - '0') * a[i];
    }
  }
  Tmp %= 11;
  if (Tmp == 10) {
    if (s[12] == 'X') {
      printf("Right\n"); 
    }
    else {
      s[12] = 'X';
      printf("%s\n", s);
    }
    return Wild_Donkey;
  } 
  if (s[12] == 'X') {
    if(Tmp != 10) {
      s[12] = Tmp + '0';
      printf("%s\n", s);
    }
    else {
      printf("Right\n"); 
    }
    return Wild_Donkey;
  }
//  printf("%u %u\n", Tmp + '0', s[12]);
  if (Tmp == s[12] - '0') {
    printf("Right\n");
  }
  else {
    s[12] = Tmp + '0';
    printf("%s\n", s);
  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
/*
0-670-82162-4
*/
