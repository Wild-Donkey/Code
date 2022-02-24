#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
const int N = 500005;
int n;
struct Node
{
  int a[31];
  Node()
  {
    memset(a, 0, sizeof(a));
  };
}T;
struct qq
{
  int l, r;
  int s1, s2;
  vector<int> t;
}tr[N * 2];int num;
set<pair<int, int> > s;
void bt(int l, int r)
{
  int a = ++num;
  tr[a].l = l;tr[a].r = r;
  if (l == r) return;
  int mid = (l + r) >> 1;
  tr[a].s1 = num + 1;bt(l, mid);
  tr[a].s2 = num + 1;bt(mid + 1, r);
}
void change(int now, int l, int r, int x)
{
  if (tr[now].l == l && tr[now].r == r)
  {
    tr[now].t.push_back(x);
    return;
  }
  int s1 = tr[now].s1, s2 = tr[now].s2;
  int mid = (tr[now].l + tr[now].r) >> 1;
  if (r <= mid) change(s1, l, r, x);
  else if (l > mid) change(s2, l, r, x);
  else change(s1, l, mid, x), change(s2, mid + 1, r, x);
}
Node add(Node o, int x)
{
  for (int u = 30;u >= 0;u--)
  {
    if ((x >> u) & 1)
    {
      if (o.a[u] == 0) { o.a[u] = x;break; }
      x ^= o.a[u];
    }
  }
  return o;
}
void solve(int now, Node t)
{
  for (int u = 0;u < tr[now].t.size();u++)
    t = add(t, tr[now].t[u]);
  /*  printf("%d %d\n",tr[now].l,tr[now].r);
      for (int u=0;u<=30;u++)
          printf("%d ",t.a[u]);
      system("pause");*/
  if (tr[now].l == tr[now].r)
  {
    /*  for (int u=0;u<=30;u++)
        printf("%d ",t.a[u]);*/

    int ans = 0;
    for (int u = 30;u >= 0;u--)
      if ((ans ^ (t.a[u])) > ans)
        ans ^= t.a[u];
    printf("%d\n", ans);
    return;
  }
  solve(tr[now].s1, t);
  solve(tr[now].s2, t);
}
int main() {
  freopen("P4184.in", "r", stdin);
  freopen("P4184.out", "w", stdout);
  scanf("%d", &n);
  bt(1, n);
  for (int u = 1;u <= n;u++)
  {
    int x;
    scanf("%d", &x);
    if (x > 0) s.insert(make_pair(x, u));
    else
    {
      pair<int, int> o = *s.lower_bound(make_pair(-x, 0));
      change(1, o.second, u - 1, -x);
      s.erase(o);
    }
  }
  set<pair<int, int> >::iterator i;
  for (i = s.begin();i != s.end();i++) change(1, (*i).second, n, (*i).first);
  solve(1, T);
  return 0;
}