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
const unsigned MOD(1000000007);
const char _0(0), _26(26);
unsigned Log[1000005], Bin[25], ST[2000005][22], Nn, Len, m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
char b;
struct Node {
  unsigned Dep, Hash, DFSr;
  Node *To[26], *Fa, *Fail, *Son, *Bro;
}N[1000005], *CntN(N), *Now(N);
vector <unsigned> Pos[1000005];
struct Quu {
  Node *P;char Chr;
}Q[1000005], *Hd(Q), *Tl(Q);
void Add(char x) {
  if(!(Now->To[x])) Now->To[x] = ++CntN, CntN->Fa = Now;
  Now->To[x]->Hash = (((unsigned long long)26 * Now->Hash) + x) % MOD, Now = Now->To[x];
}
void Build() {
  (++Tl)->P = N;
  register Node *x, *Back;
  register char c; 
  while (Tl != Hd) {
    x = (++Hd)->P, c = Hd->Chr;  
    if(x->Fa) {
      Back = x->Fa->Fail;
      while (Back) {
        if(Back->To[c]) {
//          printf("Got %u %u\n", Back->To[c] - N, x - N);
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
    for (register char i(_0); i < _26; ++i) if(x->To[i]) (++Tl)->P = x->To[i], Tl->Chr = i;
  }
}
void DFS(Node *x) {
//  printf("DFS %u\n", x - N);
  ST[++Cnt][0] = x - N, x->DFSr = Cnt;
//  printf("%u DFSr = %u\n", x - N, Cnt);
  register Node *So(x->Son);
//  printf("%u's Son is %u\n", x - N, So - N);
  while (So) So->Dep = x->Dep + 1, DFS(So), So = So->Bro;
  ST[++Cnt][0] = x - N;
  return;
}
inline Node *LCA(Node *x, Node *y) {
//  printf("LCA %u %u\n", x - N, y - N);
//  printf("Dfs %u %u\n", x->DFSr, y->DFSr);
  if(x->DFSr > y->DFSr) swap(x, y);
  register unsigned TmpL(Log[y->DFSr - x->DFSr + 1]);
  register Node *TmpP;
  if(N[ST[x->DFSr][TmpL]].Dep < N[ST[y->DFSr - Bin[TmpL] + 1][TmpL]].Dep) TmpP = N + ST[x->DFSr][TmpL];
  else TmpP = N + ST[y->DFSr - Bin[TmpL] + 1][TmpL];
  if(TmpP == x) return x;
  return TmpP->Fail;
}
int main() {
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (register unsigned i(1); i <= n; ++i) {
    while ((b = getchar()) < 'a');
    Now = N;
    while (b >= 'a') Add(b - 'a'), Pos[i].push_back(Now - N), b = getchar();
  }
  Build(), N->Dep = 1, DFS(N), Nn = CntN - N + 1, Nn <<= 1;
//  printf("Tot %u\n", Nn);
  for (register unsigned i(1), j(0); i <= Nn; i <<= 1, ++j) Bin[j] = i, Log[i] = j;
  for (register unsigned i(3); i <= Nn; ++i) Log[i] = max(Log[i - 1], Log[i]);
  for (register unsigned i(1), j(0); i < Nn; i <<= 1, ++j) {
    for (register unsigned k(1); k + (i << 1) <= Nn + 1; ++k) {
//      printf("ST %u %u %u %u\n", k, k + i, ST[k][j] - N, ST[k + i][j] - N);
//      printf("Ed ST %u %u\n", k, j + 1);
      if(N[ST[k][j]].Dep < N[ST[k + i][j]].Dep) ST[k][j + 1] = ST[k][j];
      else ST[k][j + 1] = ST[k + i][j];
    }
  }
  m = RD();
//  printf("FAQ\n");
  for (register unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD(), C = RD(), D = RD();
//    printf("LCA Found %u\n", LCA(Pos[A][B], Pos[C][D]) - N);
    printf("%u\n", LCA(N + Pos[A][B - 1], N + Pos[C][D - 1])->Hash);
  }
  //  }
  return Wild_Donkey;
}

