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
const short MOD(10007);
const char _0(0), _26(26);
short Ans(0);
char m, n, a[105];
struct Node {
  Node *To[26], *Fail, *Fa, *Bro, *Son;
  char Ava;
  short f[105];
}N[6005], *CntN(N), *Now(N);
struct Sc {
  Node *Am;char Chr;
}Q[600005], *Hd(Q), *Tl(Q);
short Power(unsigned x, char y) {
  unsigned AnsP(1);
  while (y) {
    if(y & 1) AnsP = AnsP * x % MOD;
    y >>= 1, x = x * x % MOD; 
  }
  return AnsP; 
}
void DFS1(Node *x) {
  register Node *So(x->Son);
  if(x->Fail) if(x->Fail->Ava) x->Ava = 1;
  while (So) DFS1(So), So = So->Bro;
}
void DFS2(Node *x) {
  for (register char i(_0); i < _26; ++i) if(x->To[i]) DFS2(x->To[i]); else {
    register Node *Back(x->Fail);
    while (Back) {
      if(Back->To[i]) {
        x->To[i] = Back->To[i];
        break;
      }
      Back = Back->Fail;
    }
    if(!x->To[i]) x->To[i] = N;
  }
}
void Add(char x) {
  if(!(Now->To[x])) Now->To[x] = ++CntN, CntN->Fa = Now; 
  Now = Now->To[x];
}
void Build() {
  (++Tl)->Am = N;
  register Node *x;
  register char c;
  while (Hd != Tl) {
    x = (++Hd)->Am, c = Hd->Chr;
    if(x->Fa) {
      register Node *Back(x->Fa->Fail);
      while (Back) {
        if(Back->To[c]) {
          x->Fail = Back->To[c];
          x->Bro = Back->Son;
          Back->Son = x; 
          break;
        }
        Back = Back->Fail;
      }
      if(!(x->Fail)) x->Fail = N, x->Bro = N->Son, N->Son = x;
    }
    for (register char i(_0); i < _26; ++i) if(x->To[i]) (++Tl)->Am = x->To[i], Tl->Chr = i;
  }
}
int main() {
  n = RD(), m = RD();
  for (register char i(1); i <= n; ++i) {
    memset(a, 0, sizeof(a)), scanf("%s", &a[1]);
    a[0] = strlen(a + 1), Now = N;
    for (register unsigned j(1); j <= a[0]; ++j) Add(a[j] -= 'A');
    Now->Ava = 1;
  }
  Build(), DFS1(N), DFS2(N), N->f[0] = 1;
  for (register char i(1); i <= m; ++i) {
    for (register Node *j(N); j <= CntN; ++j) if(!(j->Ava)) {
      for (register char k(_0); k < _26; ++k) {
        j->To[k]->f[i] += j->f[i - 1];
        if(j->To[k]->f[i] >= MOD) j->To[k]->f[i] -= MOD; 
      }
    }
  }
  for (register Node *i(N); i <= CntN; ++i) {
    Ans += ((i->Ava) ? 0 : (i->f[m])); 
    if(Ans >= MOD) Ans -= MOD;
  }
  printf("%u\n", (MOD + Power(26, m) - Ans) % MOD);
  return Wild_Donkey;
}
