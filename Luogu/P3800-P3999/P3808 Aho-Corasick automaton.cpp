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
unsigned a[10005], m, n, Cnt(0), L(0), R(0), t, Ans(0), Tmp(0);
bool b[10005];
char inch;
inline void Clr() {}
struct Node {
  Node *Son[26], *Fa, *Fail;
  char Ch;
  unsigned Val;
}N[1000005], *Q[1000005], *now(N), *Cntn(N), *Find(N);
int main() {
  // double Ti(clock()), Mti(0);
//   freopen("P3808_2.in", "r", stdin);
  // freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (register unsigned i(1); i <= n; ++i) {
    while (inch < 'a' || inch > 'z') {
      inch = getchar();
    }
    now = N;
    while (inch >= 'a' && inch <= 'z') {
      inch -= 'a';
      if(!(now->Son[inch])) {
        now->Son[inch] = ++Cntn;
        Cntn->Ch = inch;
        Cntn->Fail = N;
        Cntn->Fa = now;
      }
      now = now->Son[inch];
      inch = getchar();
    }
    ++(now->Val);
  }
  Q[0] = N;
  while (L <= R) {
    now = Q[L++];
//    printf("%u %u\n", now, now->Ch);
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
    while(now) {
      if(now->Son[inch]) {
        now = now->Son[inch];
        Ans += now->Val;
        now->Val = 0;
        break;
      }
      now = now->Fail;
    }
    inch = getchar();
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



