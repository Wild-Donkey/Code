#include <vector>
#include <iostream>
using namespace std;
int ans;
int n, m, lim;
int col[100], cnt[1000];
vector<int> e[1000];
bool check(int u, int fa) {
  for (auto v : e[u]) if (v != fa) {
    if (!check(v, u)) return false;
  }
  return col[u] != col[fa];
}

void dfs(int cur) {
  if (cur > n) {
    if (check(1, 0)) {
      int c1 = 0;
     for (int i = 1; i <= m; ++i) if (cnt[i] > lim) ++c1;
      if (true) ++ans;
      ans %= 998244353;
    }
    return;
  }
  for (int i = 1; i <= m; ++i) {
    col[cur] = i;
    if (++cnt[i] <= lim) 
    dfs(cur + 1);
    --cnt[i];
  }
}

int main() {
  freopen("data.in", "r", stdin);
  freopen("data.ans", "w", stdout);
  cin >> n >> m;
  lim = n / 3 + 1;
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(1);
  cout << ans << '\n';
  return 0;
}
