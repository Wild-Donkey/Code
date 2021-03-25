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
unsigned n, Cnt(0), L(0), R(0), Tms[200005], Tmp(0), Multi[200005];
char inch;
struct Node {
  Node *Son[26], *Fa, *Fail;
  char Ch;
  bool Exist;
  unsigned Val, Former;
}N[200005], *Q[200005], *now(N), *Cntn(N), *Find(N);
inline void Clr() {}
int main() {
  // double Ti(clock()), Mti(0);
//   freopen("P3796_1.in", "r", stdin);
//   freopen("P3796.out", "w", stdout);
//  t = RD();
//  while (1){
//    Clr();
//    if(!n) {
//      break;
//    }
  n = RD();
  for (register unsigned i(1); i <= n; ++i) {
    while (inch < 'a' || inch > 'z') {
      inch = getchar();
    }
    now = N;
    Cnt = 0;
    while (inch >= 'a' && inch <= 'z') {
      inch -= 'a';
      if(!(now->Son[inch])) {
        now->Son[inch] = ++Cntn;
        Cntn->Ch = inch;
        Cntn->Fail = N;
        Cntn->Fa = now;
        Cntn->Former = 0x7f3f3f3f;
      }
      now = now->Son[inch];
      inch = getchar();
    }
    now->Exist = 1;
    now->Val = i;
    ++Multi[i];
  }
  Q[0] = N;
  while (L <= R) {
    now = Q[L++];
    for (register short i(0); i < 26; ++i) {
      if(now->Son[i]) {
        Q[++R] = now->Son[i];
      }
    }
    if(!(now->Fa)) {
      continue;
    }
    Find = now->Fa->Fail; 
    while (Find) {
      if(Find->Son[now->Ch]) {
        now->Fail = Find->Son[now->Ch];
        break;
      }
      Find = Find->Fail;
    }
  }
  while (inch < 'a' || inch > 'z') {
    inch = getchar();
  }
  now = N;
  while (inch >= 'a' && inch <= 'z') {
    inch -= 'a';
    if(!now) {
      now = N;
    }
    while(now) {
      if(now->Son[inch]) {
        now = now->Son[inch];
        if(now->Former > 0x3f3f3f3f) {
          now->Former = 0;
          Find = now;
          while (Find) {
            if(Find->Exist) {
              now->Former += Multi[Find->Val];
            }
            Find = Find->Fail;
          }
        }
        Tms[now->Val] += now->Former;
        break;
      }
      now = now->Fail;
    }
    inch = getchar();
  }
  for (register short i(1); i <= n; ++i) {
    printf("%u\n", Tms[i]);
  }
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
