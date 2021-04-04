#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#define rint register int
#define ull unsigned long long
#define EdisonBa 0
using namespace std;
const int maxn = 1e6 + 5;
int n, m;
ull w[maxn];
int next[maxn << 1], head[maxn], to[maxn << 1];
inline int RD() {
  int intmp = 0, insign = 1;
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') {
    if (rdch == '-') {
      insign = -1;
    }
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp * insign;
}
int n, m, DW, A, B, C;
int main() {
  n = RD();
  for (register int i(1); i <= n; ++i) {
    }
  system("pause");
  return EdisonBa;
}
/*
// ??? ↓
// Don't Try to AC T2
//It's Really A Waste of Time <= 同意


//建议使用侧边批注 << 禁止
//Trust Me
//T3 is Easy
//so easy
//have hand is OK
禁止

*/