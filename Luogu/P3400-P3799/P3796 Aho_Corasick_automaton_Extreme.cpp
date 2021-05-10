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
unsigned a[10005], n, Cnt(0), L(0), R(0), Tms[155], Include[155][155], Tmp(0), Mx;
bool b[10005];
char inch, List[155][75];
struct Node {
  Node *Son[26], *Fa, *Fail;
  char Ch;
  bool Exist;
  unsigned Val;
}N[20005], *Q[20005], *now(N), *Cntn(N), *Find(N);
inline void Clr() {
  n = RD();
  L = 0;
  R = 0;
  Mx = 0;
  Cntn = N;
  memset(List, 0, sizeof(List));
  memset(Tms, 0, sizeof(Tms));
  memset(N, 0, sizeof(N));
  memset(Include, 0, sizeof(0));
}
int main() {
  // double Ti(clock()), Mti(0);
   freopen("P3796_1.in", "r", stdin);
   freopen("P3796.out", "w", stdout);
//  t = RD();
  while (1){
    Clr();
    if(!n) {
      break;
    }
    for (register unsigned i(1); i <= n; ++i) {
      while (inch < 'a' || inch > 'z') {
        inch = getchar();
      }
      now = N;
      Cnt = 0;
      while (inch >= 'a' && inch <= 'z') {
        List[i][Cnt++] = inch;
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
      now->Exist = 1;
      now->Val = i;
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
          Find = now;
          while (Find) {
            if(Find->Exist) {
              ++(Tms[Find->Val]);
            }
            Find = Find->Fail;
          }
          break;
        }
        now = now->Fail;
      }
      inch = getchar();
    }
//    for (register Node *i(N); i <= Cntn; ++i) {
////      printf("%u %c %u %u %u\n", i - N, i->Ch + 'a', i->Exist, i->Fail - N, i->Val);
//    }
    for (register short i(1); i <= n; ++i) {
      Mx = max(Tms[i], Mx);
//      printf("%u %u\n", i, Tms[i]);
    }
    printf("%u\n", Mx);
    if(!Mx) {
      continue;
    }
    for (register unsigned i(1); i <= n; ++i) {
      if(Tms[i] == Mx) {
        printf("%s\n", List[i]);
      }
    }
  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
/*
Root b
b e
e t
t a
Root a_
a_ l
l p
p h
h a__
Root h_
h_ a___
a___ h__
h__ a____
Root d
d e_
e_ l_
l_ t_
t_ a_____
Root d
d e_
e_ d_
d_ e__
Root t__
t__ a______
a______ t___
t___ a_______

b Root
a_ Root
h_ Root
d Root
t__ Root
a___ a_
a______ a_
a a______
t t__
t___ t__
a_______ a______
d_ d
e__ e_
h h_
a__ a___
h__ h_
a____ a___
t_ t__
a_____ a______

*/
