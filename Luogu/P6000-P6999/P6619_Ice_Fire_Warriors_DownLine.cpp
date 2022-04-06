#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') rdsg = -1, rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0', rdch = getchar();
  return rdtp * rdsg;
}
struct Infor {
  unsigned x, y;
  char Ty;
}Tip[2000005];
struct Node {
  Node *LS, *RS;
  unsigned ValI, ValF;
  inline void Build(unsigned L, unsigned R);
  inline void AddI (unsigned L, unsigned R);
  inline void AddF (unsigned L, unsigned R);
  inline void DelI (unsigned L, unsigned R);
  inline void DelF (unsigned L, unsigned R);
}N[4000005], *CntN(N);
unsigned Li[2000005], *CntL(Li);
unsigned n, m, A, B, C, D;
unsigned Cnt(0), Ans(0), Tmp(0);
inline void Node::Build(unsigned L, unsigned R) {
  if(L == R) return;
  unsigned Mid((L + R) >> 1);
  (LS = ++CntN)->Build(L, Mid);
  (RS = ++CntN)->Build(Mid + 1, R);
}
inline void Node::AddI(unsigned L, unsigned R) {
  ValI += B; if(L == R) return;
  unsigned Mid((L + R) >> 1);
  if(A <= Mid) LS->AddI(L, Mid);
  else RS->AddI(Mid + 1, R);
}
inline void Node::AddF(unsigned L, unsigned R) {
  ValF += B; if(L == R) return;
  unsigned Mid((L + R) >> 1);
  if(A <= Mid) LS->AddF(L, Mid);
  else RS->AddF(Mid + 1, R);
}
inline void Node::DelI(unsigned L, unsigned R) {
  ValI -= B;
  if(L == R) return;
  unsigned Mid((L + R) >> 1);
  if(A <= Mid) LS->DelI(L, Mid);
  else RS->DelI(Mid + 1, R);
}
inline void Node::DelF(unsigned L, unsigned R) {
  ValF -= B;
  if(L == R) return;
  unsigned Mid((L + R) >> 1);
  if(A <= Mid) LS->DelF(L, Mid);
  else RS->DelF(Mid + 1, R);
}
inline void Qry1(Node* x, unsigned L, unsigned R) {
  if(L == R) {
    unsigned L1(min(A, B + x->ValF)), L0(min(A + x->ValI, B));
    if(L1 > L0) D = 1, C = L1;
    else D = 0, C = L0;
    Ans = L;
    return;
  }
  unsigned Mid((L + R) >> 1), CurA(A), CurB(B);
  CurA += x->LS->ValI, CurB += x->RS->ValF;
  if(CurA <= CurB) A = CurA, Qry1(x->RS, Mid + 1, R);
  else B = CurB, Qry1(x->LS, L, Mid);
}
inline void Qry2(Node* x, unsigned L, unsigned R) {
  if(L == R) {Ans = L; return;}
  unsigned Mid((L + R) >> 1), CurA(A + x->RS->ValF);
  if(CurA < C) A = CurA, Qry2(x->LS, L, Mid);
  else Qry2(x->RS, Mid + 1, R);
}
char buf[300000], *Top(buf + 300000),*P3(buf);
inline void pc(char c){
	if(P3==Top) fwrite(buf,1,300000,stdout),P3=buf;
	*(P3++)=c;
}
inline void print(unsigned x){
	static char st[10],tp;
	while(x) st[++tp]=x%10, x/=10;
	while(tp)pc('0'+st[tp--]);
}
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) {
    if(RD() & 1) C = Tip[i].Ty = RD(), *(CntL++) = Tip[i].x = (RD() + C), Tip[i].y = RD();
    else Tip[i] = Tip[D = RD()], Tip[i].Ty |= 2;
  }
  sort(Li, CntL), CntL = unique(Li, CntL), N->Build(1, m = CntL - Li);
//  printf("m = %u\n", m);
  for (unsigned i(1); i <= n; ++i) {
    A = lower_bound(Li, CntL, Tip[i].x) - Li + 1, B = Tip[i].y;
    if(Tip[i].Ty & 2) {if(Tip[i].Ty & 1) N->DelF(1, m); else N->DelI(1, m);}
    else              {if(Tip[i].Ty) N->AddF(1, m);     else N->AddI(1, m);}
    A = B = C = Ans = 0;
    Qry1(N, 1, m);
    if(!D) A = 0, Qry2(N, 1, m);
    if(!C) pc('P'), pc('e'), pc('a'), pc('c'), pc('e');
    else print(Li[Ans - 1] - 1), pc(' '), print(C << 1);
    pc(0x0A);
  }
  fwrite(buf,1,P3 - buf,stdout);
//  }
  return Wild_Donkey;
}

