#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#define fys 0;
using namespace std;
inline unsigned int IN() {
  unsigned int Itmp(0);
  char Ichr(getchar());
  while (Ichr > '9' || Ichr < '0') {
    Ichr = getchar();
  }
  while (Ichr <= '9' && Ichr >= '0') {
    Itmp *= 10;
    Itmp += Ichr - '0';
    Ichr = getchar();
  }
  return Itmp;
}
unsigned int n, m, ans, Lans(0), Tag(0), a[1005], p, x, Mi(0x3f3f3f3f), Ma(0),
    JI(0), YH(0);
// multiset<long long> N;
// multiset<long long>::iterator It;
inline int Clr() { return fys; }
int find() {
  unsigned it(0);
  for (register unsigned int i(1); i <= n; ++i) {
    unsigned int tmp = 0;
    for (register unsigned int j(i); j <= n; ++j) {
      tmp ^= a[j];
      if (tmp == 0) {
        ++it;
      }
    }
  }
  return it;
}
int main() {
  freopen("sohard.in", "r", stdin);
  freopen("sohard.out", "w", stdout);
  n = IN();
  m = IN();
  for (register unsigned int i(1); i <= n; ++i) {
    a[i] = IN();
  }
  for (register unsigned int i(1); i <= m; ++i) {
    // printf("%u\n", IN());
    // printf("i = %u, DoWt = %lld, Lans = %lld, TT = %lld\n", i, DoWt, Lans,
    // TT);
    p = IN();
    x = IN();
    a[p] ^= x;
    a[p + 1] ^= x;
    ans = find();
    Ma = max(ans, Ma);
    Mi = min(ans, Mi);
    YH ^= ans;
    if (ans % 2) {
      ++JI;
    }
  }
  printf("%d\n%d\n%d\n%d\n", YH, JI, Ma, Mi);
  return fys;
}
/*
5
1 1
1 1
1 2
7 114513
5 114520
*/
