#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned m, n, Top(0), Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
char a[2005], b[2005], Stack[2005];
unsigned Print(unsigned x, char* y) {
  while (x) {
    Stack[++Top] = (x % 10) + '0';
    x /= 10;
  }
  register unsigned TmpTop(Top);
  while (Top) {
    *y = Stack[Top--];
    ++y;
  }
  return TmpTop;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), a[1] = '1', m = 1;
  for (register unsigned i(2), l(0); i <= n; ++i) {
    memcpy(b + 1, a + 1, m), l = 0;
    for (register unsigned j(1), k(1); j <= m; ++j, ++k) {
      // printf("b[%u] = %u\n", j, b[j] - '0');
      if (b[j] ^ b[j + 1]) {
        // printf("Now %u %u %u %u\n", i, l, j, k);
        l += Print(k, a + l + 1), k = 0;
        a[++l] = b[j];
      }
    }
    a[l + 1] = '0', m = l;
  }
  for (register unsigned i(1); i <= m; ++i) putchar(a[i]);
  putchar('\n');
  system("pause");
  return Wild_Donkey;
}
/*
1
11
21
1211
111221
312211
13112221
1113213211
31131211131221
.
.
.
13211311123113112211132113213221133112132123123112111311222112132113311213211231232112311311222112111312211311123113322112132113212231121113112221121321132132211231232112311321322112311311222113111231133221121113122113121113221112131221123113111231121123222112132113213221133112132123123112111312111312212231131122211311123113322112111312211312111322111213122112311311123112112322211211131221131211132221232112111312111213111213211231132132211211131221232112111312212221121123222112132113213221133112132123123112111311222112132113213221132213211321322112311311222113311213212322211211131221131211221321123113213221121113122113121132211332113221122112133221123113112221131112311332111213122112311311123112111331121113122112132113121113222112311311221112131221123113112221121113311211131122211211131221131211132221121321132132212321121113121112133221123113112221131112212211131221121321131211132221123113112221131112311332211211133112111311222112111312211311123113322112111312211312111322212321121113121112133221121321132132211331121321231231121113112221121321132122311211131122211211131221131211322113322112111312211322132113213221123113112221131112311311121321122112132231121113122113322113111221131221
*/