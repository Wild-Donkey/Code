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
const char _0(0), _10(10);
unsigned Len, TLen, m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
char L[105], R[105], a[105];
struct Node {
  Node *To[10], *Fa, *Fail, *Son, *Bro;
  unsigned f[105][32][2], Sum[105][32][2];
  char End;
}N[1005], *Last(N), *CntN(N);
struct Quee {
  Node *Nd;
  char Chr;
}Q[1005], *Hd(Q), *Tl(Q);
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
//    printf("BFS %u\n", x - N);
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
      if(!(x->Fail)) {
        x->Fail = N;
        x->Bro = N->Son; 
        N->Son = x;
      }
    }
    for (register char i(_0); i < _10; ++i) if(x->To[i]) (++Tl)->Nd = x->To[i], Tl->Chr = i;
  } 
}
void DFS(Node *x) {
//  printf("DFS %u\n", x - N);
  register Node *So(x->Son);
  while (So) So->End |= x->End, DFS(So), So = So->Bro;
}
void ReLink(Node *x) {
  register Node *Back; 
  for (register char i(_0); i < _10; ++i) {
    if(!(x->To[i])) {
      Back = x->Fail;
      while (Back) {
        if(Back->To[i]) {
          x->To[i] = Back->To[i];
          break;
        }
        Back = Back->Fail;
      }
      if(!(x->To[i])) x->To[i] = N;;
    } else {
      ReLink(x->To[i]);
    }
  }
}  
void DP (char *x) {
//  register unsigned long long Now(0);
  N->f[0][0][1] = 1;
  for (register unsigned i(0); i < Len; ++i) {
//    Now = Now * 10 % MOD;
    for (register unsigned j(0); j < m; ++j) {
//      printf("DPing %u %u a = %u\n", i, j, x[i]);
      for (register Node *k(N); k <= CntN; ++k) {
//        printf("K %u\n", k - N);
        register unsigned *Des;
        for (register char l(_0); l < x[i]; ++l) {
//          printf("to %u = %u Have %u\n", l, k->To[l] - N, k->To[l]->End);
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
  for (register Node *k(N); k <= CntN; ++k) {
    register unsigned *Des(k->Sum[Len][m - 1]);
    Tmp += *Des; if(Tmp >= MOD) Tmp -= MOD;
    Tmp += *(Des + 1); if(Tmp >= MOD) Tmp -= MOD;
//    printf("f[%u][0] = %u, [1] = %u\n", k - N, *Des, *(Des + 1));
  }
  for (register unsigned i(0); i <= Len; ++i) {
    for (register unsigned j(0); j < m; ++j) {
      for (register Node *k(N); k <= CntN; ++k) {
//        printf("f[%u][%u][%u] %u %u\n", k - N, i, j, k->f[i][j][0], k->f[i][j][1]);
        k->f[i][j][0] = k->f[i][j][1] = k->Sum[i][j][0] = k->Sum[i][j][1] = 0;
      }
    }
  }
  printf("DPed %u\n", Tmp);
}
int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = (1 << n), scanf("%s%s", L, R), TLen = strlen(L), Len = strlen(R);
  for (register unsigned i(TLen - 1); i < 0x3f3f3f3f; --i) L[Len - TLen + i] = L[i] - '0';
  for (register unsigned i(0); i < Len - TLen; ++i) L[i] = 0;
  for (register unsigned i(0); i < Len; ++i) R[i] = R[i] - '0';
//  for (register unsigned i(0); i < Len; ++i) printf("L[%u] %u\n", i, L[i]);
  TLen = Len - 1; while (!L[TLen]) L[TLen] = 9, --TLen; --L[TLen];
//  for (register unsigned i(0); i < Len; ++i) printf("L[%u] %u\n", i, L[i]);
  for (register unsigned i(0), j; i < n; ++i) {
    memset(a, 0, sizeof(a)), scanf("%s", a), j = strlen(a), Last = N;
    for (register unsigned k(0); k < j; ++k) Add(a[k] - '0');
    Last->End = 1 << i;
  }
  Build(), DFS(N), ReLink(N), DP(R), Ans = Tmp, Tmp = 0, DP(L), Ans += MOD - Tmp;
  if(Ans >= MOD) Ans -= MOD; printf("%u\n", Ans);
  return Wild_Donkey;
}
/*
1 1 10
0
2 1000 3000
01
2
*/
