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
const unsigned MOD(998244353);
const char _0(0), _1(1), _10(10);
char Len, TLen, m, n;
unsigned Ans(0), Tmp(0);
char L[105], R[105], a[105];
struct Node {
  Node *To[10], *Fa, *Fail, *Son, *Bro;
  unsigned f[105][32][2], Sum[105][32][2];
  char End;
}N[105], *Last(N), *CntN(N);
struct Quee {
  Node *Nd;
  char Chr;
}Q[105], *Hd(Q), *Tl(Q);
void Add(char c) {
  if(!(Last->To[c])) Last->To[c] = ++CntN, CntN->Fa = Last;
  Last = Last->To[c];
}
void Build() {
  (++Tl)->Nd = N;
  register Node *x, *Back;
  register char c; 
  while (Hd != Tl) {
    x = (++Hd)->Nd, c = Hd->Chr;
    if(x->Fa) {
      Back = x->Fa->Fail;
      while (Back) {
        if(Back->To[c]) {
          x->Fail = Back->To[c];
          x->Bro = Back->To[c]->Son;
          Back->To[c]->Son = x;
          break;
        }
        Back = Back->Fail; 
      }
      if(!(x->Fail)) x->Fail = N, x->Bro = N->Son, N->Son = x;
    }
    for (register char i(_0); i < _10; ++i) if(x->To[i]) (++Tl)->Nd = x->To[i], Tl->Chr = i;
  } 
}
void DFS(Node *x) {
  register Node *So(x->Son);
  while (So) So->End |= x->End, DFS(So), So = So->Bro;
}
void ReLink(Node *x) {
  register Node *Back; 
  for (register char i(_0); i < _10; ++i) {
    if(!(x->To[i])) {
      Back = x->Fail;
      while (Back) {
        if(Back->To[i]) {x->To[i] = Back->To[i];break;}
        Back = Back->Fail;
      }
      if(!(x->To[i])) x->To[i] = N;;
    } else {
      ReLink(x->To[i]);
    }
  }
}  
void DP (char *x, char Lead) {
  for (register char j(_1); j <= (x[Lead]); ++j)
    ++(N->To[j]->f[Lead + 1][N->To[j]->End][(j == x[Lead]) ? _1 : _0]),
    N->To[j]->Sum[Lead + 1][N->To[j]->End][(j == x[Lead]) ? _1 : _0] += j;
  for (register char i(Lead + _1); i < Len; ++i) {
    for (register char j(_1); j < _10; ++j)
      ++(N->To[j]->f[i + 1][N->To[j]->End][0]),
      N->To[j]->Sum[i + 1][N->To[j]->End][0] += j;
    for (register char j(_0); j < m; ++j) {
      for (register Node *k(N); k <= CntN; ++k) {
        register unsigned *Des;
        for (register char l(_0); l < x[i]; ++l) {
          Des = k->To[l]->f[i + 1][j | k->To[l]->End];
          *Des += k->f[i][j][0]; if(*Des >= MOD) *Des -= MOD;
          *Des += k->f[i][j][1]; if(*Des >= MOD) *Des -= MOD;
          Des = k->To[l]->Sum[i + 1][j | k->To[l]->End];
          *Des = (((unsigned long long)k->Sum[i][j][0] + k->Sum[i][j][1]) * 10 + ((unsigned long long)k->f[i][j][0] + k->f[i][j][1]) * l + *Des) % MOD;
        }
        Des = k->To[x[i]]->f[i + 1][j | k->To[x[i]]->End];
        *(Des + 1) += k->f[i][j][1]; if(*(Des + 1) >= MOD) *(Des + 1) -= MOD;
        *Des += k->f[i][j][0]; if(*Des >= MOD) *Des -= MOD;
        Des = k->To[x[i]]->Sum[i + 1][j | k->To[x[i]]->End];
        *Des = ((unsigned long long)k->Sum[i][j][0] * 10 + (unsigned long long)k->f[i][j][0] * x[i] + *Des) % MOD;
        *(Des + 1) = ((unsigned long long)k->Sum[i][j][1] * 10 + (unsigned long long)k->f[i][j][1] * x[i] + *(Des + 1)) % MOD;
        for (register char l(x[i] + 1); l < _10; ++l) {
          Des = k->To[l]->f[i + 1][j | k->To[l]->End];
          *Des += k->f[i][j][0]; if(*Des >= MOD) *Des -= MOD;
          Des = k->To[l]->Sum[i + 1][j | k->To[l]->End];
          *Des = ((unsigned long long)k->Sum[i][j][0] * 10 + (unsigned long long)k->f[i][j][0] * l + *Des) % MOD;
        }
      }
    }
  }
  for (register Node *k(N); k <= CntN; ++k){
    register unsigned *Des(k->Sum[Len][m - 1]);
    Tmp += *Des; if(Tmp >= MOD) Tmp -= MOD;
    Tmp += *(Des + 1); if(Tmp >= MOD) Tmp -= MOD;}
  for (register char i(_1); i <= Len; ++i)
    for (register char j(_0); j < m; ++j)
      for (register Node *k(N); k <= CntN; ++k)
        k->f[i][j][0] = k->f[i][j][1] = k->Sum[i][j][0] = k->Sum[i][j][1] = 0;
}
int main() {
  n = RD(), m = (1 << n), scanf("%s%s", L, R), TLen = strlen(L), Len = strlen(R);
  for (register unsigned i(TLen - 1); i < 0x3f3f3f3f; --i) L[Len - TLen + i] = L[i] - '0';
  for (register char i(_0); i < Len - TLen; ++i) L[i] = 0;
  for (register char i(_0); i < Len; ++i) R[i] = R[i] - '0';
  TLen = Len - 1; while (!L[TLen]) L[TLen] = 9, --TLen; --L[TLen], TLen = 0, L[Len] = 1; 
  while(!L[TLen]) ++TLen;
  for (register char i(_0), j; i < n; ++i) {
    memset(a, 0, sizeof(a)), scanf("%s", a), j = strlen(a), Last = N;
    for (register char k(0); k < j; ++k) Add(a[k] - '0');
    Last->End = 1 << i;
  }
//  printf("Faq\n");
  Build(), DFS(N), ReLink(N), DP(R, 0), Ans = Tmp, Tmp = 0, DP(L, TLen), Ans += MOD - Tmp;
  if(Ans >= MOD) Ans -= MOD; printf("%u\n", Ans);
  return Wild_Donkey;
}
/*
1 1 10
0
2 1000 3000
01
2
5 1 82540359441923000806680947120299532358523806017903538046977923087700401067103002913474448
21
213
4325
345
243
*/
