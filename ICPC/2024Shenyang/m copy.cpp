#include <bits/stdc++.h>
using namespace std;
#define int int64_t
constexpr int maxn = 5e5 + 4;
vector<tuple<int, int, bool>> verts[maxn];
int regular(int64_t a, int n) {
  return (a % n + n) % n;
}
set<int> stk[maxn];
bool vis[maxn], inf[maxn];
vector<int> ls;
void dfs(int u, int cur) {
  stk[u].insert(cur);
  // ls.push_back(u);
  if (stk[u].size() > 1) {
    inf[u] = true;
    return;
  }
  for (auto& [v, b, vis] : verts[u]) {
    inf[u] |= inf[v];
    if (!stk[u].count(cur + b))
      dfs(v, cur + b);
    inf[u] |= inf[v];
  }
  stk[u].erase(cur);
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 1; i <= m; ++i) {
    int a, b;
    cin >> a >> b;
    verts[regular(a, n)].emplace_back(regular(a + b, n), b, false);
  }
  for (int i = 0; i < n; ++i) {
    dfs(i, 0);
  }
  for (int i = 1; i <= q; ++i) {
    int64_t x;
    cin >> x;
    cout << (inf[regular(x, n)] ? "Yes" : "No") << '\n';
  }
  return 0;
}