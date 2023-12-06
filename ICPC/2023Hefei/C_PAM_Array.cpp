#include <bits/stdc++.h>
using namespace std;
unsigned n;
char a[500005];
struct Node {
  unsigned To[26];
  Node *Link;
  vector<Node *> Sons;
  unsigned Dep;
  int Len;
} N[500005], *CntN(N + 1), *Last(N + 1);
void Add(char c, int Cur) {
  Node *Jump(Last), *Nw;
  while (Jump->Len + 1 > Cur) Jump = Jump->Link;
  while (a[Cur - 1 - Jump->Len] != a[Cur]) Jump = Jump->Link;
  if (Jump->To[c] ^ 0xffffffff)
    Nw = N + Jump->To[c];
  else {
    Jump->To[c] = (Nw = ++CntN) - N, Nw->Len = Jump->Len + 2;
    Jump = Jump->Link;
    memset(Nw->To, 0xff, 104);
    while (Jump && (!((Jump->To[c] ^ 0xffffffff) &&
                      (a[Cur - Jump->Len - 1] == a[Cur]))))
      Jump = Jump->Link;
    if (!Jump)
      Nw->Link = N + 1;
    else
      Nw->Link = N + Jump->To[c];
    Nw->Dep = Nw->Link->Dep + 1;
  }
  Last = Nw;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> a;
  n = strlen(a);
  N[0].Len = -1;
  N[1].Link = N, N[1].Len = 0;
  memset(N[0].To, 0xff, 104);
  memset(N[1].To, 0xff, 104);
  for (unsigned i(0), Ans(0); i < n; ++i) {
    a[i] = (a[i] - 'a' + Ans) % 26;
    Add(a[i], i), printf("%u ", Ans = Last->Dep);
  }
  putchar(0x0A);
  return 0;
}
/*
5
01010

8
866776677
*/