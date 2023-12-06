#include <bits/stdc++.h>
using namespace std;
const unsigned long long Mod(998244353);
unsigned long long Ans(0);
unsigned n;
char a[6000005];
struct Node {
  Node *To[10], *Link;
  vector<Node *> Sons;
  unsigned Oc, Sumn, Sum2n;
  int Len;
  inline void DFS1() {
    Sumn = Oc;
    for (auto i : Sons) i->DFS1(), Sumn += i->Sumn;
  }
  inline void DFS2() {
    Sum2n = Oc;
    for (auto i : Sons) i->DFS2(), Sum2n += i->Sum2n;
  }
} N[6000005], *CntN(N + 1), *Last(N + 1), *HisCnt;
void Add(char c, int Cur) {
  Node *Jump(Last), *Nw;
  while (Jump->Len + 1 > Cur) Jump = Jump->Link;
  while (a[Cur - 1 - Jump->Len] != a[Cur]) Jump = Jump->Link;
  if (Jump->To[c])
    Nw = Jump->To[c];
  else {
    Jump->To[c] = Nw = ++CntN, Nw->Len = Jump->Len + 2;
    Jump = Jump->Link;
    while (Jump && (!((Jump->To[c]) && (a[Cur - Jump->Len - 1] == a[Cur]))))
      Jump = Jump->Link;
    if (!Jump)
      Nw->Link = N + 1;
    else
      Nw->Link = Jump->To[c];
  }
  ++(Nw->Oc), Last = Nw;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> a;
  memcpy(a + n, a, n);
  N[0].Len = -1;
  N[1].Link = N, N[1].Len = 0;
  for (unsigned i(0); i < n; ++i) Add(a[i] - '0', i);
  for (Node *i(N + 1); i <= CntN; ++i) i->Link->Sons.push_back(i);
  N->DFS1(), HisCnt = CntN;
  for (unsigned i(0); i < n; ++i) Add(a[i] - '0', i + n);
  for (Node *i(HisCnt + 1); i <= CntN; ++i) i->Link->Sons.push_back(i);
  N->DFS2();
  for (Node *i(N + 2); i <= CntN; ++i)
    if (i->Len <= n) {
      unsigned long long Tmp(i->Sum2n - i->Sumn);
      Ans = (Ans + (Tmp * Tmp % Mod) * (unsigned)i->Len) % Mod;
    }
  cout << Ans << endl;
  return 0;
}
/*
5
01010

8
866776677
*/