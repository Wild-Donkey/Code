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
int Pre[1000005], Last(0x3f3f3f3f);
unsigned m, n(1), Sum[1000005], Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
char a[1000005];
int main() {
//  freopen("B.in", "r", stdin);
//  freopen("B.out", "w", stdout);
  fread(a + 2, 1, 1000001, stdin);
  for (; a[n + 1] >= 'A'; ++n) a[n] -= 'A';
  a[n] -= 'A';
  if(n == 1) {
    if(a[1] == 0) Ans = 1;
    printf("%u\n", Ans);
    return 0;
  }
  Pre[0] = 0x3f3f3f3f, Pre[1] = 1, Sum[0] = 0;
  for (register unsigned i(2); i <= n; ++i) {
    Sum[i] = Sum[i - 1];
    Pre[i] = Pre[i - 1];
    if(!a[i]) ++Sum[i];
    else {
      if(a[i] ^ 1) ++Pre[i];
      else --Pre[i];
    }
//    printf("%u Pre %d Sum %u\n", i, Pre[i], Sum[i]);
  }
  for (register unsigned i(1), j; i <= n; ++i) {
    if((Pre[i] < Pre[i - 1]) && (Pre[i] <= Pre[i + 1])) {
      if(Pre[i] <= Last) {
        Last = Pre[i];
        for (j = i; (j < n) && (Pre[j] >= Pre[i]); ++j);
//        printf("Faq %u %u\n", i, j);
        Ans = max(Ans, Sum[j] - Sum[i - 1]);
        if(j > i) i = j - 1;
        else i = j;
      }
    }
  }
  printf("%u\n", Ans);
//  }
  return Wild_Donkey;
}
/*
CCAACCCBCAABCAABCAABCBCBBBBCCBAAABCCCAABCAAABACBABBACCABACAABBBACABCCBCCAB
CCAACCCBCAABCAABCAABCBCBBBBCCBAAABCCCAABCAAABACBABBACCABACAABBBACABCCBCCABCAACBBABCCCACABACCAABACCAC
BBABACBCCACBBACCACACCCAACAAAACBBAAAACBACBCBCBACCCAAABCCBCCCAABABBCBABBCBABBAABBCABBABCCBAACAACCCABCB
AABAAABABAABBAAABBBBBBAABBBBABBBABABBAABBBBAABBAAAABABBABBBABBAABBBABBABBAAABAAABABABBBABABBAAAABBB
*/
