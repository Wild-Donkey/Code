#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
unsigned long long Ans(0);
bitset<50005> States;
unsigned n, m, Cnt(0);
unsigned A, B, C, D;
unsigned Des[50005], *DTop(Des);
inline unsigned RD() {
  unsigned RTmp(0);
  char RChr(getchar());
  while ((RChr < '0') || (RChr > '9')) RChr = getchar();
  while ((RChr >= '0') && (RChr <= '9'))
    RTmp = (RTmp << 3) + (RTmp << 1) + RChr - 48, RChr = getchar();
  return RTmp;
}
set<pair<unsigned, unsigned> > S;
set<pair<unsigned, unsigned> >::iterator Cur, Lst, Nxt;
void Prt() {
  for (auto i : S) printf("[%u,%u]", i.first, i.second);
  putchar(0x0A);
}
signed main() {
  S.insert({1, n = RD()}), m = RD();
  for (unsigned i(1); i <= m; ++i) {
    char Op[2];
    scanf("%s", Op);
    if (Op[0] == 'R') {
      A = B = D = *(DTop--);
      Lst = Nxt = Cur = S.find({D, D});
      States[D] = 0;
      if ((D < n) && (!States[D + 1])) B = (++Nxt)->second, S.erase(Nxt);
      if ((D - 1) && (!States[D - 1])) A = (--Lst)->first, S.erase(Lst);
      S.erase(Cur), S.insert({A, B});
    } else {
      D = RD(), Cur = S.lower_bound({D, D});
      if (Cur == S.end() || Cur->first > D) --Cur;
      if (Op[0] == 'D') {
        States[*(++DTop) = D] = 1, A = Cur->first, B = Cur->second,
                           S.erase(Cur);
        if (A < D) S.insert({A, D - 1});
        if (D < B) S.insert({D + 1, B});
        S.insert({D, D});
      } else {
        if (States[D]) {
          printf("0\n");
          continue;
        }
        printf("%u\n", Cur->second - Cur->first + 1);
      }
    }
  }
  return 0;
}
/*
g++ P1503_Ghost_into_Village.cpp -o faq -std=c++14 -O2 && faq
*/