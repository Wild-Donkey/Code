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
long long CurC(0);
unsigned m, n, A, B, t;
char No(0);
struct St {
  map <long long, long long> S;
}SC[200005], * CntS(SC);
inline St* Mrg(St* x, St* y) {
//  printf("Merge %u %u\n", x - SC, y - SC);
  if (x->S.size() < y->S.size()) swap(x, y);
  for (auto i : y->S)
    if (x->S.find(i.first) != x->S.end()) x->S[i.first] += i.second;
    else x->S.insert(i);
  return x;
}
struct Node {
  vector <Node*> E;
  St* My;
  long long Val, Earn;
  char Im;
}N[200005], * Link[200005], * Des;
inline void Clr() {
  while (CntS > SC) CntS->S.clear(), --CntS;
  for (unsigned i(1); i <= n; ++i) N[i].E.clear();
  n = RD(), Des = N + RD(), No = m = CurC = 0;
}
inline char DFS1(Node* x, Node* Fa) {//Del Earn
//  printf("%u Now\n", x - N);
  x->Earn = 0;
  unsigned Lim(x->E.size());
  for (unsigned i(0); i < Lim; ++i) if ((x->E[i] != Fa) && (!(x->E[i]->Im))) {
    Node* Cur(x->E[i]);
    if (Cur->Val >= 0) {
      if (Cur == Des) Des = x;
      Cur->Im = 1;
      if (x->Val >= 0) x->Val += Cur->Val;
      else x->Earn += Cur->Val;
//      Cur->Val = 0;
      for (auto j : Cur->E) if (j != x) x->E.push_back(j), ++Lim;
    }
  }
  vector <Node*> Son;
  for (auto i : x->E) if ((i != Fa) && (!(i->Im))) Son.push_back(i);
  x->E.clear();
  char Flg(0);
  for (auto i : Son) {
    if (DFS1(i, x)) Flg = 1;
    else x->E.push_back(i);
  }
  if (x == Des) Flg = 1;
  if (Flg) Link[++m] = x;
  return Flg;
}
inline void DFS2(Node* x) {
  if(x->Val < 0) x->Val = -(x->Val);
  else x->Earn = x->Val, x->Val = 0;
  x->My = ++CntS;// if(x > N + 10000) return;
  for (auto i : x->E) DFS2(i), x->My = Mrg(x->My, i->My);
  long long Need(x->Earn - x->Val);
//  printf("Get %u Val %lld Er %lld Nd %lld ->", x - N, x->Val, x->Earn, Need);
//  printf("Sons %u\n", x->E.size());
//  for (auto i : x->E) printf("%u ", i - N); putchar(0x0A);
  for (map<long long, long long>::iterator i(x->My->S.begin()); x->My->S.size(); i = x->My->S.begin()) {
    if ((Need <= 0) || (i->first <= x->Earn)) {
      if (x->Earn >= i->first) x->Earn += i->second;
      else x->Val += i->first - x->Earn, x->Earn += i->first - x->Earn + i->second;
      Need += i->second, x->My->S.erase(i);
    }
    else break;
  }
//  printf("Backed %u %lld %lld %lld\n", x - N, x->Val, x->Earn, Need); 
//  for (auto i:x->My->S) printf("%lld,%lld ", i.first, i.second); putchar(0x0A);
//  printf("Pnt %u Size %u xDoor %lld Out %lld\n", x - N, x->My->S.size(), x->Val, Need);
//  putchar(0x0A);
  if (Need > 0) x->My->S[x->Val] = Need;
  else x->My->S.clear();
//  if(x->Val > 100000) {
//    printf("Size %u Val %lld Er %lld Nd %lld\n", x->My->S.size(), x->Val, x->Earn, Need);
//    for (auto i:x->My->S) printf("%lld,%lld ", i.first, i.second); putchar(0x0A);
//  }
//  printf("Val %lld Need %lld\n", x->Val, Need);
}
signed main() {
  freopen("e-spawned.in", "r", stdin);
//  freopen("e-built.in", "r", stdin);
//  freopen("E.in", "r", stdin);
  freopen("e.out", "w", stdout);
  t = RD();
//  A = 1, B = 1;
//  printf("%llu %llu\n", A, B);
  for (unsigned T(1); T <= t; ++T) {
//    printf("FAQ\n");
    Clr();
    for (unsigned i(1); i <= n; ++i) N[i].Val = RDsg(), N[i].Im = 0;
    CurC = 0;
//    for (unsigned i(1); i <= n; ++i) if(N[i].Val >= 0) CurC += N[i].Val;
//    printf("CurC %lld\n", CurC), CurC = 0;
//    for (unsigned i(1); i <= n; ++i) if(N[i].Val < 0) CurC += N[i].Val;
//    printf("CurC %lld\n", CurC), CurC = 0;
    for (unsigned i(1); i < n; ++i) {
      A = RD(), B = RD();
      N[A].E.push_back(N + B);
      N[B].E.push_back(N + A);
//      if((A ^ (B - 1)) && (A ^ (B + 1 ))) printf("Link (%u,%u)\n", A, B);
    }
//    DFS2(N + 1, NULL);
    St* All(SC);
    All->S.clear(), DFS1(N + 1, NULL), CurC = 0;
//    printf("Des %u\n", Des - N);
//    printf("m %u\n", m);
    for (unsigned i(m); i; --i) {
//      printf("Link %u = %u CyrC %lld\n", i, Link[i] - N, CurC);
      if (CurC < (-(Link[i]->Val))) { No = 1; break; }
      CurC += Link[i]->Val + Link[i]->Earn, Link[i]->Val = Link[i]->Earn = 0, DFS2(Link[i]);
//      printf("Got %u %u %lld\n", i, Link[i] - N, CurC);
      All = Mrg(All, Link[i]->My);
//      printf("Size %u %u %u\n", All->S.size(), All->S.begin(), All->S.end());
      for (map<long long, long long>::iterator j(All->S.begin()); All->S.size(); j = All->S.begin()) {
//        printf("(%lld, %lld) %lld\n", j->first, j->second, CurC);
        if (j->first <= CurC) CurC += j->second, All->S.erase(j);
        else break;
      }
    }
//    printf("%u ", T);  
    printf(No ? "trapped\n" : "escaped\n");
  }
  // system("pause");
  return Wild_Donkey;
}
