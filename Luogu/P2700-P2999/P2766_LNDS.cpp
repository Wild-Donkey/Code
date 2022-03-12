#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int rd() {
  int res = 0, fl = 1; char c = getchar();
  while (!isdigit(c)) { if (c == '-') fl = -1; c = getchar(); }
  while (isdigit(c)) { res = (res << 3) + (res << 1) + c - '0'; c = getchar(); }
  return res * fl;
}
const unsigned maxn(1010);
unsigned Hd(0), Tl(0);
unsigned n, x[1005], en(1), fst[1005], S, T;
unsigned long long dep[1005], Flow, Tmp1, Tmpn, Tmp, f[1005], s;
struct Node;
struct Edge {
  Node* To;
  Edge* Nxt;
  unsigned Val;
  char Type;
}ed[100005];
struct Node {
  Edge* Fst;
}* Q[1005];
void add(int u, int v, ll w) {
  ed[++en].to = v, ed[en].c = w, ed[en].nxt = fst[u], fst[u] = en;
  ed[++en].to = u, ed[en].nxt = fst[v], fst[v] = en;
}
bool BFS() {
  memset(dep, 0, sizeof(dep));
  dep[S] = 1;
  Hd = Tl = 0, Q[++Tl] = S;
  while (Tl ^ Hd) {//手写队列可不可以/kk
    unsigned u(Q[++Hd]);
    for (unsigned e(fst[u]), v(ed[e].to); e; e = ed[e].nxt, v = ed[e].to)
      if ((!(dep[v])) && (ed[e].c > 0)) dep[v] = dep[u] + 1, Q[++Tl] = v;
  }
  return dep[T];
}
ll DFS(int u, ll flow) {//DFS 大成功 √
  //	printf("->%d ", u);
  if (u == T) return flow;//汇点, 来多少要多少
  if (!flow) return 0;//没有流量, 拉倒
  ll res = flow;//分配
  for (int e(fst[u]), v(ed[e].to); e; e = ed[e].nxt, v = ed[e].to) {
    if (!res) break;
    if ((dep[v] == dep[u] + 1) && (ed[e].c)) {//加个括号吧姐姐
      ll k(DFS(v, min(res, ed[e].c)));//实际上的流量
      if (!k) dep[v] = 0;//一点都流不得了
      res -= k;
      ed[e].c -= k, ed[e ^ 1].c += k;
    }
  }
  return flow - res;//这时剩余的和进来的差就是实际流量
}
signed main() {
  // freopen("P2766_12.in", "r", stdin);//要这个
  // freopen("P2766.out", "w", stdout);
  n = rd(); S = n * 2 + 3, T = n * 2 + 4;
  if (n == 1) { printf("1\n1\n1\n");return 0; }
  for (int i(1); i <= n; ++i) {
    x[i] = rd();
    f[i] = 1;
  }//2 ~ 2 * n + 1 // 自边 每一个点拆成两个点 二者连边? 用于限制每个数的使用次数
  for (int i(1); i <= n; ++i) for (int j(1); j < i; ++j)
    if (x[j] <= x[i]) f[i] = max(f[i], f[j] + 1);//DP 求最长
  for (int i(1); i <= n; ++i) s = max(s, f[i]);
  printf("%lld\n", s);
  for (int i(1); i <= n; ++i) if (f[i] == 1) add(S, i, 1);
  for (int i(1); i <= n; ++i) if (f[i] == s) add(i + n, T, 1);
  for (int i(1); i <= n; ++i) for (int j(1); j < i; ++j)
    if ((x[j] <= x[i]) && (f[j] + 1 == f[i])) add(j + n, i, 1);
  for (int i(1); i <= n; ++i) add(i, i + n, 1);//自边
  while (BFS()) Flow += DFS(S, inf); // 最大流
  printf("%lld\n", Flow);
  for (unsigned i(1); i <= en; ++i) ed[i].c = ((i & 1) ^ 1);
  for (unsigned e(fst[S]); e; e = ed[e].nxt) if (ed[e].to == 1) ed[e].c = inf;
  for (unsigned e(fst[n << 1]); e; e = ed[e].nxt) if (ed[e].to == T) ed[e].c = inf;
  ed[fst[1]].c = inf;
  ed[fst[n]].c = inf;
  Flow = 0;
  while (BFS()) Flow += DFS(S, inf); // 最大流
  printf("%lld\n", Flow);
  return 0;
}
