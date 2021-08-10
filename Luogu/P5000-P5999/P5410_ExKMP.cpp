#include <cstdio>
#include <cstring>
#include <iostream>
#define Wild_Donkey 0
using namespace std;
unsigned ZS[20000005], ZT[20000005], m, n, Cnt(0);
unsigned long long Ans1(0), Ans2(0);
char S[20000005], T[20000005];
void ExKMP(char *Mot, char *Mod, unsigned *Zot, unsigned *Zod, unsigned Lenot) {
  register unsigned i(1), a(1), p(1);
  while (i <= Lenot) {
    while (Mot[p] == Mod[p - a + 1]) ++p;
    if (p == a) {
      Zot[i] = 0, ++i, ++a, ++p;
      continue;
    }
    if(i >= p) {
      a = i;
      continue;
    }
    if (i + Zod[i - a + 1] == p) {
      if(p - i == m) Zot[i] = m, ++i, p = i;
      a = i;
      continue;
    }
    if(i + Zod[i - a + 1] < p) {
      Zot[i] = Zod[i - a + 1];
    } else {
      Zot[i] = p - i;
    }
    ++i;
  }
  return;
}
int main() {
  scanf("%s%s", S + 1, T + 1);
  n = strlen(S + 1), m = strlen(T + 1); 
  ZT[1] = m;
  ExKMP(T + 1, T, ZT + 1, ZT, m - 1);
  for (register unsigned long long i(1); i <= m; ++i) {
    Ans1 ^= i * (ZT[i] + 1);
  }
  ExKMP(S, T, ZS, ZT, n);
  for (register unsigned long long i(1); i <= n; ++i) {
    Ans2 ^= i * (ZS[i] + 1);
  }
  printf("%llu\n%llu\n", Ans1, Ans2); 
  return Wild_Donkey;
}
