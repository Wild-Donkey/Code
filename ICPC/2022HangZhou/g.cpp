#include <bits/stdc++.h>
using namespace std;

unsigned long long Xorshift(unsigned long long x) {
  x ^= x << 13;
  x ^= x >> 7;
  x ^= x << 17;
  return x;
}

struct Node {
  vector<Node *> To;
  char Vis;
  void FindRing(Node *Come);
  unsigned long long Hash() {
    unsigned long long Rt = 19260817;
    Vis = 1;
    for (auto i : To)
      if (!(i->Vis)) Rt += Xorshift(i->Hash());
    // printf("%llu %llu\n", this, Rt);
    return Rt;
  }
} N[100005], *Ring[100005], **RingBegin, *RingHead;
unsigned long long HLst[100005];
char Flg;
unsigned Cnt;
void Node::FindRing(Node *Come) {
  Vis = 1, Ring[++Cnt] = this;
  for (auto i : To)
    if (i != Come) {
      if (i->Vis) {
        RingHead = i, Flg = 1;
        return;
      }
      i->FindRing(this);
      if (Flg) return;
    }
  --Cnt;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t-- > 0) {
    int n, m, A, B;
    cin >> n >> m;
    if (n < m) {
      for (unsigned i(1); i <= m; ++i) cin >> A >> B;
      printf("NO\n");
      continue;
    }
    if (n > m) {
      for (unsigned i(1); i <= m; ++i) cin >> A >> B;
      printf("YES\n");
      continue;
    }
    for (unsigned i(1); i <= n; ++i) { N[i].To.clear(), N[i].Vis = 0; }
    for (unsigned i(1); i <= m; ++i) {
      cin >> A >> B;
      N[A].To.push_back(N + B);
      N[B].To.push_back(N + A);
    }
    Flg = 0, Cnt = 0, N[1].FindRing(NULL), RingBegin = Ring;
    while (*RingBegin != RingHead) ++RingBegin;
    --RingBegin, Cnt -= (RingBegin - Ring);
    for (unsigned i(1); i <= n; ++i) N[i].Vis = 0;
    for (unsigned i(1); i <= Cnt; ++i) RingBegin[i]->Vis = 1;
    for (unsigned i(1); i <= Cnt; ++i) HLst[i] = RingBegin[i]->Hash();
    // for (unsigned i(1); i <= Cnt; ++i) printf("Hash %llu = %llu\n", Ring[i] -
    // N, HLst[i]);
    Flg = 0;
    if (Cnt & 1) {
      for (unsigned i(1); i < Cnt; ++i)
        if (HLst[i] != HLst[i + 1]) {
          Flg = 1;
          break;
        }
    } else {
      for (unsigned i(3); i <= Cnt; i += 2)
        if (HLst[i] != HLst[i - 2]) {
          Flg = 1;
          break;
        }
      if (Flg) {
        printf("NO\n");
        continue;
      }
      for (unsigned i(4); i <= Cnt; i += 2)
        if (HLst[i] != HLst[i - 2]) {
          Flg = 1;
          break;
        }
    }
    if (Flg)
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}
/*
9
7 6
1 2
2 3
3 4
4 5
5 6
3 7
3 3
1 2
2 3
3 1
5 5
1 2
2 3
3 4
4 1
1 5
1 0
7 6
1 2
2 3
3 4
4 5
5 6
3 7
3 3
1 2
2 3
3 1
5 5
1 2
2 3
3 4
4 1
1 5
1 0
18 18
1 2
2 3
3 1
1 4
1 5
4 6
6 7
5 8
2 9
2 10
10 11
10 12
11 13
3 14
14 15
14 16
15 17
16 18
*/