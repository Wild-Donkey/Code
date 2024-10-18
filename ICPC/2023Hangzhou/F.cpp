#include <bits/stdc++.h>
using namespace std;
int t, n, m, Limn;
struct Node {
  Node *Fa;
  unsigned Dep;
  unsigned long long DDep;
  vector<pair<Node *, unsigned>> Ed;
  void DFS() {
    for (unsigned i(0); Fa[i]; ++i) { Fa[i + 1] = Fa[i]->Fa[i]; }
    for (auto i : Ed)
      if (i.first != Fa[0]) {
        i.first->Fa[0] = this;
        i.first->Dep = Dep + 1, i.first->DDep = DDep + i.second;
        i.first->DFS();
      }
  }
} N[500005], *Lst[500005];
pair<pair<Node *, unsigned long long>, pair<Node *, unsigned long long>>
    Cor[500005];
Node *LCA(Node *x, Node *y) {
  if (x->Dep < y->Dep) swap(x, y);
  for (unsigned i(18); ~i; --i)
    if (x->Fa[i] && x->Fa[i]->Dep >= y->Dep) x = x->Fa[i];
  if (x == y) return x;
  for (unsigned i(18); ~i; --i)
    if (x->Fa[i] != y->Fa[i]) x = x->Fa[i], y = y->Fa[i];
  return x->Fa[0];
}
unsigned long long Dist(Node *x, Node *y, Node *LCA) {
  return x->DDep + y->DDep - ((LCA->DDep) << 1);
}
pair<pair<Node *, unsigned long long>, pair<Node *, unsigned long long>> Mid(
    Node *x, Node *y, Node *LCA, unsigned long long Di) {
  unsigned long long Sum = 0, Hlf = (Di >> 1);
  if (x->DDep < y->DDep) swap(x, y);
  const auto ox = x;
  for (unsigned i(18); ~i; --i)
    if (x->Fa[i] && x->Fa[i]->Dep >= LCA->Dep &&
        ox->DDep - x->Fa[i]->DDep <= Hlf)
      x = x->Fa[i];
  Sum = ox->DDep - x->DDep;
  if (x != LCA) return {{x, Di - Sum}, {x->Fa[0], ox->DDep - x->Fa[0]->DDep}};
  return {{LCA, Sum}, {LCA, Sum}};
}
pair<Node *, Node *> Add(Node *x, Node *y, unsigned z) {
  Node *LCAx(LCA(x, y)), *LCAy(LCA(x, Lst[z])), *LCAz(LCA(y, Lst[z]));
  unsigned long long Tx(Dist(x, y, LCAx)), Ty(Dist(x, Lst[z], LCAy)),
      Tz(Dist(y, Lst[z], LCAz));
  if (Tx >= Ty && Tx >= Tz) {
    Cor[z] = Cor[z - 1];
    return {x, y};
  }
  if (Ty > Tz)
    y = Lst[z], Cor[z] = Mid(x, y, LCAy, Ty);
  else
    x = Lst[z], Cor[z] = Mid(x, y, LCAz, Tz);
  return {x, y};
}
int main() {
  scanf("%d%d", &n, &m);
  for (unsigned i(1); i <= n; ++i) {
    scanf("%u", &t);
    if (t <= n) Lst[t] = N + i;
  }
  for (unsigned i(1); i < n; ++i) {
    unsigned A, B, C;
    scanf("%u%u%u", &A, &B, &C);
    N[A].Ed.push_back({N + B, C});
    N[B].Ed.push_back({N + A, C});
  }
  // printf("Hello\n");
  N[1].Dep = 1, N[1].Fa[0] = NULL, N[1].DFS();
  if (Lst[0]) {
    pair<Node *, Node *> Cur = {Lst[0], Lst[0]};
    Cor[0] = {{Lst[0], 0}, {Lst[0], 0}};
    for (Limn = 1; Limn <= n; ++Limn) {
      if (!Lst[Limn]) break;
      Cur = Add(Cur.first, Cur.second, Limn);
    }
  }
  // printf("Limn %u\n", Limn);
  for (unsigned i(1); i <= m; ++i) {
    unsigned long long A, B, TmpD;
    scanf("%llu%llu", &A, &B);
    Node *Sta(N + A);
    unsigned L(0xffffffff), R(Limn - 1), Mid;
    while (L ^ R) {
      Mid = ((L + R + 1) >> 1);
      // printf("[%u %u], %u\n", L, R, Mid);
      TmpD = min(
          Dist(Sta, Cor[Mid].first.first, LCA(Sta, Cor[Mid].first.first)) +
              Cor[Mid].first.second,
          Dist(Sta, Cor[Mid].second.first, LCA(Sta, Cor[Mid].second.first)) +
              Cor[Mid].second.second);
      if (TmpD <= B)
        L = Mid;
      else
        R = Mid - 1;
    }
    printf("%u\n", L + 1);
  }
  return 0;
}
/*
5 4
3 9 0 1 2
1 2 10
3 1 4
3 4 3
3 5 2
3 0
1 0
4 6
4 7
*/