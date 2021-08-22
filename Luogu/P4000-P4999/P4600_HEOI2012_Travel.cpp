#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
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
unsigned Nn, CntS(0), Len, m, n, Cnt(0), A, B, C, D, FindL, FindR, t, Ans(0), Tmp[2000005];
char b, Addx;
struct Node {
  unsigned Dep, Hash, DFSr, SubDFSr, To[26], Fa, Fail, Son, Bro;
}N[1000005], *CntN(N), *Now(N);
struct Sg {
  unsigned LS, RS, Val;
}S[4000005];
void Qry(Sg *x, unsigned L, unsigned R) {
//  printf("Qry %u [%u, %u]\n", x - S, L, R);
  if((FindL <= L) && (R <= FindR)) {
    if(Now->Dep > N[x->Val].Dep) Now = N + x->Val; 
    return; 
  }
  register unsigned Mid((L + R) >> 1);
  if(Mid >= FindL) Qry(S + x->LS, L, Mid);
  if(Mid < FindR) Qry(S + x->RS, Mid + 1, R);
}
void BuildSg(Sg *x, unsigned L, unsigned R) {
//  printf("Build %u [%u, %u]\n", x - S, L, R);
  if(L == R) {x->Val = Tmp[L];return;}
  register unsigned Mid((L + R) >> 1);
  BuildSg(S + (x->LS = ++CntS), L, Mid);
  BuildSg(S + (x->RS = ++CntS), Mid + 1, R);
  if(N[S[x->LS].Val].Dep < N[S[x->RS].Val].Dep) x->Val = S[x->LS].Val;
  else x->Val = S[x->RS].Val;
//  printf("%u is for %u\n", x->Val - N, x - S);
}
unsigned Pool[20000005], *Pos[1000005], Top(0);
struct Quu {
  unsigned P; char Chr;
}TmpQ;
queue<Quu> Q;
void Add() {
//  printf("%u at %u Size %u Find %u %u\n", Now - N, CntN - N, Now->To.size(), distance(Now->To.begin(), Now->To.find(Addx)), distance(Now->To.begin(), Now->To.end()));
  if(!Now->To[Addx]) Now->To[Addx] = ++CntN - N, CntN->Fa = Now - N, CntN->Son = 0x3f3f3f40;
//  printf("%u at %u Size %u Find %u %u\n", Now - N, CntN - N, Now->To.size(), distance(Now->To.begin(), Now->To.find(Addx)), distance(Now->To.begin(), Now->To.end()));
  N[Now->To[Addx]].Hash = (((unsigned long long)26 * Now->Hash) + Addx) % MOD, Now = N + Now->To[Addx];
}
void Build() {
  TmpQ.P = 0;
  Q.push(TmpQ);
  register Node *x, *Back;
  register char c; 
  while (Q.size()) {
//    printf("Q.size %u\n", Q.size());
    TmpQ = Q.front(), Q.pop();
    x = N + TmpQ.P, c = TmpQ.Chr;
//    printf("BFS %u\n", x - N);
    if(x->Fa < 0x3f3f3f3f) {
      Back = N + N[x->Fa].Fail;
//      printf("Back %llu %u\n", Back - N, N[x->Fa].Fail);
      while (Back < N + 0x3f3f3f3f) {
        if(Back->To[c]) {
//          printf("Got %u %u\n", Back->To[c], x - N);
          x->Fail = Back->To[c];
          x->Bro = N[Back->To[c]].Son;
          N[Back->To[c]].Son = x - N;
          break; 
        }
        Back = N + Back->Fail;
      }
      if(!(x->Fail)) {
        x->Fail = 0;
        x->Bro = N->Son;
        N->Son = x - N;
      }
    }
    for (register char i(_0); i < _26; ++i) if(x->To[i]) TmpQ.P = x->To[i], TmpQ.Chr = i, Q.push(TmpQ);
  }
}
void DFS(Node *x) {
//  printf("DFS %u\n", x - N);
  Tmp[++Cnt] = x - N, x->DFSr = Cnt;
//  printf("%u DFSr = %u\n", x - N, Cnt);
  register Node *So(N + x->Son);
//  printf("%u's Son is %u\n", x - N, So - N);
  while (So < N + 0x3f3f3f3f) So->Dep = x->Dep + 1, DFS(So), So = N + So->Bro;
  Tmp[++Cnt] = x - N, x->SubDFSr = Cnt;
//  printf("Out %u\n", x - N);
  return;
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
    Now = N, Pos[i] = Pool + Top + 1;
    while (b >= 'a') Addx = b - 'a', Add(), Pool[++Top] = Now - N, b = getchar();
  }
  N[0].Son = N[0].Fa = N[0].Fail = 0x3f3f3f40, Build(), N->Dep = 1, DFS(N), Nn = CntN - N + 1, Nn <<= 1, BuildSg(S, 1, Nn);
  m = RD(), N[Nn + 1].Dep = 0x3f3f3f3f;
//  printf("FAq\n");
  for (register unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD(), C = RD(), D = RD();
    FindL = N[Pos[A][B - 1]].DFSr, FindR = N[Pos[C][D - 1]].DFSr;
    if(FindL > FindR) swap(FindL, FindR);
    if(N[Tmp[FindL]].SubDFSr > FindR) Now = N + Tmp[FindL];
    else Now = N + Nn + 1, Qry(S, 1, Nn), Now = N + Now->Fail;
//    printf("Find %u %u at %u %u\n", Tmp[FindL], Tmp[FindR], FindL, FindR);
//    printf("%u =? %u\n", Now->DFSr, FindL);
//    printf("Found %u\n", Now - N);
    printf("%u\n", Now->Hash);
  }
  //  }
  return Wild_Donkey;
}


