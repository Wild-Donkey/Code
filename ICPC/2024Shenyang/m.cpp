#include<bits/stdc++.h>
using namespace std;
const int N = 500010;
int n, m, q;
int  dfn[N], low[N], st[N], f[N], fs, tp, id;
bool ed[N];
typedef pair<int, int> pii;
vector<pii> e[N];
int regular(int a, int n) {
  return (a % n + n) % n;
}
void tarjan(int u)
{
  dfn[u] = low[u] = ++id;
  ed[u] = 1; st[++tp] = u;
  for (pii vv : e[u])
  {
    int v = vv.first;
    if (dfn[u])
    {
      if (ed[v])low[u] = min(low[u], dfn[v]);
    } else tarjan(v), low[u] = min(low[u], low[v]);
  }
  if (dfn[u] == low[u])
  {
    ++fs;
    do
    {
      f[st[tp]] = fs;
      ed[st[tp]] = 0;
    } while (st[tp--] != u);
  }
}
int vis[N], ans[N];
long long num[N];
void dfs(int k)
{
  vis[k] = 1;
  for (auto& x : e[k])
  {
    int v = x.first;
    if (f[k] == f[v] && vis[v] && num[k] + x.second != num[v])
      ans[v] = 1;
    num[v] = num[k] + x.second;
    if (!vis[v])dfs(v);
    ans[k] |= ans[v];
  }
}
int main()
{
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1;i <= m;i++)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    e[regular(a, n)].push_back(make_pair(regular(a + b, n), b));
  }
  for (int i = 0;i < n;i++)
    if (!dfn[i])
      tarjan(i);
  for (int i = 0;i < n;i++)
    if (!vis[i])
      dfs(i);
  while (q--)
  {
    int x;
    scanf("%d", &x);
    puts(ans[regular(x, n)] ? "Yes" : "No");
  }
  return 0;
}