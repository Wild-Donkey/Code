#include<bits/stdc++.h>
using namespace std;
unsigned a[100005], Pos[100005];
// unsigned ST[][100005];
unsigned n;

pair<unsigned, unsigned> DFS(unsigned L, unsigned R, unsigned Max) {
  if (L == R) return { Max, Max };
  if (L > R) return { 0, 0 };
  if (L == R - 1) return { min(a[L], a[R]), max(a[L], a[R]) };
  unsigned Mid = Pos[Max];
  if (Pos[Max - 1] < Mid) DFS(L, Mid - 1);
  else DFS(Mid + 1, R)
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  unsigned t = 1;
  cin >> t;
  while (t--) {
    cin >> n;
    for (unsigned i = 1; i <= n; ++i) {
      cin >> a[i];
      Pos[a[i]] = i;
    }

  }
  return 0;
}
/*
2
3 4
12 20

114 514
*/