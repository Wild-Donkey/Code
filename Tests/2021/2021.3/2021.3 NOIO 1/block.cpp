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
const unsigned MOD(1000000007);
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
unsigned a[10005], n(0), m, Cnt(0), A, B, C, D, t, Ans(0), f[3005][3005];
char inputCharacter, S1[10005], S2[10005];
string Left[30005];
struct Str {
  char Ch[3005];
  const bool operator< (const Str &x) const {
    short i(0);
    while (this->Ch[i] == x.Ch[i] && x.Ch[i]){
//      printf("Conpare %u\n", i);
      ++i;
    }
    if((!(this->Ch[i])) && (!(x.Ch[i]))) {
//      printf("???");
      return 0;
    }
    return this->Ch[i] < x.Ch[i];
  }
  void Print() {
    short i(0);
    while(Ch[i] <= 'z' && Ch[i] >= 'a') {
      putchar(Ch[i++]);
    }
    putchar('\n');
  }
}Sort[25005];
inline void Clr() {}
int main() {
  // double Ti(clock()), Mti(0);
   freopen("block.in", "r", stdin);
   freopen("block.out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
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
//  putchar('!');
  for(register unsigned l(0); l < n; ++l) {
    for (register unsigned r(l); r < n; ++r) {
//      printf("%u %u\n", l, r);
      memset(Sort[Cnt].Ch, 0, sizeof(Sort[Cnt].Ch));
      for (register unsigned i(l), j(0); j < n; ++j) {
        if(S2[i] == S1[j]) {
//          putchar(S1[i]);
          Sort[Cnt].Ch[i - l] = S1[i];
          ++i;
        }
        if (i == r) {
//          if(!(St)) {
//            St.push(Tmp);
//            ++Ans;
//          }
          ++Cnt;
          break;
        }
      }
    }
  }
  Ans = 1;
  sort(Sort, Sort + Cnt);
  for (register unsigned i(2); i < Cnt; ++i) {
//    printf("%u\n", i);
    if(Sort[i - 1] < Sort[i]) {
//      Sort[i].Print();
      ++Ans;
    }
  }
  printf("%u\n", Ans);
//  }
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
