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
unsigned m, n, Hor[105][10005], Ver[105][10005];
unsigned long long Tmp(0);
unsigned q, A, B, Cnt(0);
namespace Gen {
  unsigned SA, SB, SC, lim;
  inline unsigned getweight() {
    SA ^= (SA << 16), SA ^= (SA >> 5), SA ^= (SA << 1);
    unsigned t(SA);
    SA = SB, SB = SC, SC ^= (t ^ SA);
    return SC % lim + 1;
  }
  inline void gen() {
    n = RD(), m = RD(), SA = RD(), SB = RD(), SC = RD(), lim = RD();
    for(unsigned i(1); i <= n; ++i) for(unsigned j(1); j <= m; ++j) Hor[i][j] = getweight();
    for(unsigned i(1); i < n; ++i) for(unsigned j(1); j <= m; ++j) Ver[i][j] = getweight();
  }
  inline void Prt() {
    printf("Hor:\n");
    for (unsigned i(1); i <= n; ++i) {
      for (unsigned j(1); j <= m; ++j) printf("%3u", Hor[i][j]); putchar(0x0A);
    }
    printf("Ver:\n");
    for (unsigned i(1); i < n; ++i) {
      for (unsigned j(1); j <= m; ++j) printf("%3u", Ver[i][j]); putchar(0x0A);
    }
  }
}
struct Node {
  vector<pair<Node*, unsigned> > E;
  Node* Bel;
  inline unsigned GetCol();
  inline Node* Find();
  inline void DFS(Node* Fa);
}N[1000005], *Stack[805], **STop(Stack), *Cur;
inline Node* Node::Find() {
  Node* x(this);
  while (x->Bel != x) *(++STop) = x, x = x->Bel;
  while (STop > Stack) (*(STop--))->Bel = x;
  return x; 
}
inline unsigned Node::GetCol() { return 1 + ((this - N) / n); }
struct Edge {
  Node *End[2];
  unsigned long long Val;
  inline const char operator< (const Edge& x) const {return Val < x.Val;}
  inline char Add() {
    Node *Set[2];
    Set[0] = End[0]->Find(), Set[1] = End[1]->Find();
    if(Set[0] == Set[1]) return 0;
    Set[0]->Bel = Set[1];
//    printf("Add %u-%u %u\n", End[0] - N, End[1] - N, Val);
    return 1;
  }
};
vector<Edge> Greenwich;
struct Block {
  vector<Node*> Nd;
  vector<Edge> Eg;
  unsigned long long Val;
  inline void Build() {
    for (auto i:Nd) i->E.clear();
    for (auto i:Eg) {
      i.End[0]->E.push_back({i.End[1], i.Val});
      i.End[1]->E.push_back({i.End[0], i.Val});
    }
  }
  inline void Virtualize (unsigned L, unsigned R);
}Pre[10005], Suf[10005], Ans;
inline void Merge(Block* x, Block* y, Block* z) {
  vector<Edge> AllEg;
  vector<Node*> AllNd;
  Cnt = 0;
  for (auto i:x->Eg) AllEg.push_back(i);
  for (auto i:y->Eg) AllEg.push_back(i);
  if(z != y) for (auto i:z->Eg) AllEg.push_back(i);
  sort(AllEg.begin(), AllEg.end());
  for (auto i:x->Nd) i->Bel = i, AllNd.push_back(i);
  for (auto i:y->Nd) i->Bel = i, AllNd.push_back(i);
  z->Eg.clear(), Cnt = AllNd.size();
  for (auto i:AllEg) {
    if(i.Add()) --Cnt, z->Eg.push_back(i);
    if(Cnt == 1) break;
  }
  z->Val = x->Val + y->Val, z->Nd.clear();
  for (auto i:AllNd) z->Nd.push_back(i);
//  printf("Merged %u Nodes Deleted %llu\n", z->Nd.size(), z->Val);
}
Block *Blc;
inline void Block::Virtualize (unsigned L, unsigned R) {
  Node* Root(N + (n * (L - 1)));
  Build(), Cnt = 0, Blc = this, A = L, B = R;
  Eg.clear(), Nd.clear(), Root->DFS(NULL);
//  printf("Val %llu\n", Val);
//  for (auto i:Eg) printf("%u-%u:%u ", i.End[0] - N, i.End[1] - N, i.Val); putchar(0x0A);
}
Node* Down(NULL);
unsigned Mx(0);
inline void Node::DFS(Node* Fa) {
  char Flg(0);
  Node* SonDown(NULL);
  unsigned SonMx(0), Col(GetCol());
  Down = NULL, Mx = 0;
  for (auto i:E) if(i.first != Fa) {
    i.first->DFS(this);
    if(Down) {
      Blc->Val += min(Mx, i.second), Mx = max(i.second, Mx);
      if(SonDown) Flg = 1, Blc->Eg.push_back({this, SonDown, SonMx});
      SonDown = Down, SonMx = Mx;
    } else Blc->Val += i.second;
  }
  if((Col == A) || (Col == B)) Flg = 1;
  if(Flg) {
    if(SonDown) Blc->Eg.push_back({this, SonDown, SonMx});
    Blc->Nd.push_back(this), Down = this, Mx = 0;
    return;
  }
  Down = SonDown, Mx = SonMx; 
}
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  Gen::gen();// Gen::Prt();
  for (unsigned i(1); i <= m; ++i) Pre[i].Val = 0;
  Cur = N;
  for (unsigned i(1); i <= m; ++i) {
    for (unsigned j(1); j < n; ++j, ++Cur)
      Pre[i].Nd.push_back(Cur), Pre[i].Eg.push_back({Cur, Cur + 1, Ver[j][i]});
    Pre[i].Nd.push_back(Cur++);
  }
  Cur = N;
  for (unsigned i(2); i <= m; ++i) {
    for (unsigned j(1); j <= n; ++j, ++Cur) Pre[i].Eg.push_back({Cur, Cur + n, Hor[j][i - 1]});
    Merge(Pre + i - 1, Pre + i, Pre + i), Pre[i].Virtualize(1, i);
  }
  for (unsigned i(1); i <= m; ++i) Suf[i].Val = 0;
  Cur = N;
  for (unsigned i(1); i <= m; ++i) {
    for (unsigned j(1); j < n; ++j, ++Cur)
      Suf[i].Nd.push_back(Cur), Suf[i].Eg.push_back({Cur, Cur + 1, Ver[j][i]});
    Suf[i].Nd.push_back(Cur++);
  }
  Cur = N + (n * m) - 1;
  for (unsigned i(m - 1); i; --i) {
    for (unsigned j(n); j; --j, --Cur) Suf[i].Eg.push_back({Cur, Cur - n, Hor[j][i]});
    Merge(Suf + i + 1, Suf + i, Suf + i), Suf[i].Virtualize(i, m);
  }
  for (unsigned i(0); i < n; ++i) 
    Greenwich.push_back({N + i, N + (n * (m - 1)) + i, Hor[i + 1][m]});
  for (unsigned i(RD()); i; --i) {
    Ans.Eg.clear(); for (auto j:Greenwich) Ans.Eg.push_back(j);
    A = RD() - 1, B = RD() + 1, Merge(Pre + A, Suf + B, &Ans);
    Tmp = Ans.Val;
    for (auto j:Ans.Eg) Tmp += j.Val;
    printf("%llu\n", Tmp);
  }
//  }
  return Wild_Donkey;
}

