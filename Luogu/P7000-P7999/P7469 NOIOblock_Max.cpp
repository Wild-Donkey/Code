#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#define Wild_Donkey 0
using namespace std;
const unsigned SEED1(157), SEED2(161), MOD1(4294967291), MOD2(4294967279);
inline unsigned RD() {
  unsigned intmp = 0;
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
unsigned a[10005], n(0), m, Cnt(0), A, B, C, D, t, Ans(0), f[3005];
char inputCharacter, S1[10005], S2[10005];
unsigned long long Hash[3005][3005], List[9000005];
void Calc() {
  for (register short l(0); l < n; ++l) {
    unsigned long long Tmp1(S2[l]), Tmp2(S2[l]);
    Hash[l][l] = Tmp1 + (unsigned long long)(Tmp2 << 32);
    for (register short r(l + 1); r < n; ++r) {
      Tmp1 = (Hash[l][r - 1] * SEED1 + S2[r]) % MOD1;
      Tmp2 = ((Hash[l][r - 1] >> 32) * SEED2 + S2[r]) % MOD2;
      Hash[l][r] = Tmp1 + (Tmp2 << 32);
    }
  }
  return; 
}
inline void Clr() {}
int main() {
  // double Ti(clock()), Mti(0);
//   freopen("block.in", "r", stdin);
//   freopen("block.out", "w", stdout);
  n = RD();
  while (inputCharacter < 'a' || inputCharacter > 'z') {
    inputCharacter = getchar(); 
  }
  while (inputCharacter >= 'a' && inputCharacter <= 'z') {
    S1[Cnt++] = inputCharacter;
    inputCharacter = getchar();
  }
  Cnt = 0;
  while (inputCharacter < 'a' || inputCharacter > 'z') {
    inputCharacter = getchar(); 
  }
  while (inputCharacter >= 'a' && inputCharacter <= 'z') {
    S2[Cnt++] = inputCharacter;
    inputCharacter = getchar();
  }
  Cnt = 0;
  Calc();
  for(register unsigned l(0); l < n; ++l) {
    f[l] = 0;
    for (register unsigned r(l); r < n; ++r) {
      if(f[r] == n) {
        break; 
      }
      for (register unsigned i(f[r]); i < n; ++i) {
        if(S2[r] == S1[i]) {
          f[r + 1] = i + 1;
          List[++Cnt] = Hash[l][r];
          break;
        }
        if(i == n - 1) {
          f[r + 1] = n;
          break;
        }
      }
    }
  }
  sort(List + 1, List + Cnt + 1);
//  a[0x3f3f3f3f] = 0;
  for(register unsigned i(1); i <= Cnt; ++i) {
    Ans += (List[i - 1] < List[i]);
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
5
bcabc
bbcca

20
egebejbhcfabgegjgiig
edfbhhighajibcgfecef

*/
