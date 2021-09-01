#include <bits/stdc++.h>
using namespace std;
#define pb emplace_back
int n;
const int maxn = 1e6 + 61;
char s[maxn], buf[maxn];

struct PII {
  int x, y;
  bool operator<(const PII o) const { return x == o.x ? y > o.y : x < o.x; }
};

int rt[maxn];
struct SegMentTree {
  int ls[maxn << 5], rs[maxn << 5], cnt = 0;
  PII mx[maxn << 5], zero;

  SegMentTree() { zero.x = zero.y = 0; }

  void ins(int& p, int l, int r, int x) {
    if (!p) p = ++cnt;
    if (l == r) {
      mx[p].x++, mx[p].y = l;
      return;
    }
    int mid = l + r >> 1;
    if (x <= mid)
      ins(ls[p], l, mid, x);
    else
      ins(rs[p], mid + 1, r, x);
    mx[p] = max(mx[ls[p]], mx[rs[p]]);
  }

  int merge(int x, int y, int l, int r) {
    if (!x || !y) return x | y;
    int qwq = ++cnt;
    if (l == r) {
      mx[qwq] = mx[x];
      mx[qwq].x += mx[y].x;
      return qwq;
    }
    int mid = l + r >> 1;
    ls[qwq] = merge(ls[x], ls[y], l, mid);
    rs[qwq] = merge(rs[x], rs[y], mid + 1, r);
    mx[qwq] = max(mx[ls[qwq]], mx[rs[qwq]]);
    return qwq;
  }

  PII qry(int p, int a, int b, int l, int r) {
    if (!p) return zero;
    if (a <= l && r <= b) return mx[p];
    int mid = l + r >> 1;
    PII ans = zero;
    if (a <= mid) ans = max(ans, qry(ls[p], a, b, l, mid));
    if (b > mid) ans = max(ans, qry(rs[p], a, b, mid + 1, r));
    return ans;
  }
} smt;

vector<int> g[maxn];
int ed[maxn], mxl[maxn];

struct SAM {
  int ch[maxn][26], fa[maxn], len[maxn];
  int las, cnt;
  SAM() { las = cnt = 1; }

  void ins(int c, int id) {
    int p = las, np = las = ++cnt;
    smt.ins(rt[np], 1, n, id);
    len[np] = len[p] + 1;
    for (; p && !ch[p][c]; p = fa[p]) ch[p][c] = np;
    if (!p) {
      fa[np] = 1;
    }
    else {
      int q = ch[p][c];
      if (len[q] == len[p] + 1) {
        fa[np] = q;
      }
      else {
        int nq = ++cnt;
        memcpy(ch[nq], ch[q], sizeof(ch[q]));
        fa[nq] = fa[q], fa[q] = fa[np] = nq, len[nq] = len[p] + 1;
        for (; p && ch[p][c] == q; p = fa[p]) ch[p][c] = nq;
      }
    }
  }

  void build() {
    for (int i = 2; i <= cnt; i++) g[fa[i]].pb(i);
  }

  void init() {
    int p = 1, l = 0, now = 0;
    char* cur = s;
    while (*cur) {
      ++now;
      int c = (*cur++) - 'a';
      while (p && !ch[p][c]) p = fa[p], l = len[p];
      if (ch[p][c]) {
        p = ch[p][c], ++l;
      }
      else {
        p = 1, l = 0;
      }
      ed[now] = p, mxl[now] = l;
    }
  }
} sam;

int fa[maxn][18];
void dfs(int u) {
  for (int v : g[u]) {
    fa[v][0] = u;
    dfs(v);
    rt[u] = smt.merge(rt[u], rt[v], 1, n);
  }
}

PII qry(int l, int r, int pl, int pr) {
  if (pr - pl + 1 > mxl[pr]) return { l, 0 };
  int p = ed[pr];
  for (int i = 17; ~i; i--)
    if (fa[p][i] && sam.len[fa[p][i]] >= pr - pl + 1) p = fa[p][i];
  PII ans = smt.qry(rt[p], l, r, 1, n);
  if (!ans.x) ans.y = l;
  return { ans.y, ans.x };
}

signed main() {
  // code begin.
  scanf("%s", s), scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    sam.las = 1, scanf("%s", buf);
    char* cur = buf;
    while (*cur) sam.ins((*cur++) - 'a', i);
  }
  sam.build(), sam.init(), dfs(1);
  for (int j = 1; j <= 17; j++)
    for (int i = 1; i <= sam.cnt; i++) fa[i][j] = fa[fa[i][j - 1]][j - 1];
  int _;
  scanf("%d", &_);
  while (_--) {
    int l, r, pl, pr;
    scanf("%d %d %d %d", &l, &r, &pl, &pr);
    PII ans = qry(l, r, pl, pr);
    printf("%d %d\n", ans.x, ans.y);
  }
  system("pause");
  return 0;
  // code end.
}

/*
jhadsaksjdghfadsfkj
4
aksjfbd
askdjfh
asekehgf
waieugu
10
1 4 8 8
1 4 8 9
1 4 9 11
1 4 11 12
1 4 3 5
1 4 2 3
1 4 17 18
1 4 14 16
1 4 12 12
1 4 13 16
*/