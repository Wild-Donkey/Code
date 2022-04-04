#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<algorithm>
#define inline  __inline__ __attribute__((always_inline)) 
using namespace std;
int n, m, p, a, b, c, d, ans, vis[20001], f[20001], head[20001], numedge, vis1[20001], q[20000001], qhead, qtail;
inline int read() {
  int x = 0;char ch = getchar();
  while (ch < '0' || ch>'9')ch = getchar();
  while (ch >= '0' && ch <= '9')x = x * 10 + ch - '0', ch = getchar();
  return x;
}
struct op {
  int a, b, c, d, id, ans;
}opt[200001], q1[200001], q2[200001], q3[200001];
unsigned Complexity(0);
inline bool cmp(const op& a, const op& b) { return a.id < b.id; }
struct edge { int next, to, data; }ed[80001];
inline void addedge(register int x, register int y, register int z) { ed[++numedge] = (edge){ head[x],y,z };head[x] = numedge; }
inline void spfa(register int l1, register int l2, register int r1, register int r2, register int x) {
  if (f[x] != 0) {
    for (register int i = l1;i <= r1;i++) {
      for (register int j = l2;j <= r2;j++) {
        if ((i - 1) * m + j != x)f[(i - 1) * m + j] += f[x];
        vis[(i - 1) * m + j] = 0;
      }
    }
  }
  else {
    for (register int i = l1;i <= r1;i++) {
      for (register int j = l2;j <= r2;j++) {
        f[(i - 1) * m + j] = 0x3fffffff;
        vis[(i - 1) * m + j] = 0;
      }
    }
  }
  f[x] = 0;qhead = qtail = 0;q[qtail++] = x;
  while (qhead < qtail) {
    ++Complexity;
    register int x = q[qhead];qhead++;vis[x] = 0;
    for (register int i = head[x];i;i = ed[i].next) {
      if (f[x] + ed[i].data < f[ed[i].to] && vis1[ed[i].to]) {
        f[ed[i].to] = f[x] + ed[i].data;
        if (!vis[ed[i].to])vis[ed[i].to] = 1, q[qtail++] = ed[i].to;
      }
    }
  }
}
void dfs(register int l1, register int l2, register int r1, register int r2, register int l, register int r) {
  if (l1 == r1 && l2 == r2 || l > r)return;
  if (r1 - l1 > r2 - l2) {
    register int mid = (l1 + r1) / 2;
    for (register int i = l1;i <= r1;i++)for (register int j = l2;j <= r2;j++)vis1[(i - 1) * m + j] = 1;
    for (register int i = l2;i <= r2;i++) {
      spfa(l1, l2, r1, r2, (mid - 1) * m + i);
      for (register int j = l;j <= r;j++) {
        opt[j].ans = min(opt[j].ans, f[(opt[j].a - 1) * m + opt[j].b] + f[(opt[j].c - 1) * m + opt[j].d]);
      }
    }
    for (register int i = l1;i <= r1;i++)for (register int j = l2;j <= r2;j++)f[(i - 1) * m + j] = vis1[(i - 1) * m + j] = 0;
    int q1top = 0, q2top = 0, q3top = 0;
    for (register int i = l;i <= r;i++) {
      if (opt[i].a <= mid && opt[i].c <= mid)q1[++q1top] = opt[i];
      else if (opt[i].a > mid && opt[i].c > mid)q2[++q2top] = opt[i];
      else q3[++q3top] = opt[i];
    }
    for (register int i = l;i <= l + q1top - 1;i++)opt[i] = q1[i - l + 1];
    for (register int i = l + q1top;i <= l + q1top + q2top - 1;i++)opt[i] = q2[i - l - q1top + 1];
    for (register int i = l + q1top + q2top;i <= r;i++)opt[i] = q3[i - l - q1top - q2top + 1];
    dfs(l1, l2, mid, r2, l, l + q1top - 1);
    dfs(mid + 1, l2, r1, r2, l + q1top, l + q1top + q2top - 1);
  }
  else {
    register int mid = (l2 + r2) / 2;
    for (register int i = l1;i <= r1;i++)for (register int j = l2;j <= r2;j++)vis1[(i - 1) * m + j] = 1;
    for (register int i = l1;i <= r1;i++) {
      spfa(l1, l2, r1, r2, (i - 1) * m + mid);
      for (register int j = l;j <= r;j++) {
        opt[j].ans = min(opt[j].ans, f[(opt[j].a - 1) * m + opt[j].b] + f[(opt[j].c - 1) * m + opt[j].d]);
      }
    }
    for (register int i = l1;i <= r1;i++)for (register int j = l2;j <= r2;j++)f[(i - 1) * m + j] = vis1[(i - 1) * m + j] = 0;
    register int q1top = 0, q2top = 0, q3top = 0;
    for (register int i = l;i <= r;i++) {
      if (opt[i].b <= mid && opt[i].d <= mid)q1[++q1top] = opt[i];
      else if (opt[i].b > mid && opt[i].d > mid)q2[++q2top] = opt[i];
      else q3[++q3top] = opt[i];
    }
    for (register int i = l;i <= l + q1top - 1;i++)opt[i] = q1[i - l + 1];
    for (register int i = l + q1top;i <= l + q1top + q2top - 1;i++)opt[i] = q2[i - l - q1top + 1];
    for (register int i = l + q1top + q2top;i <= r;i++)opt[i] = q3[i - l - q1top - q2top + 1];
    dfs(l1, l2, r1, mid, l, l + q1top - 1);dfs(l1, mid + 1, r1, r2, l + q1top, l + q1top + q2top - 1);
  }
}
int main() {
  freopen("P3350_19.in", "r", stdin);
  freopen("P3350.out", "w", stdout);
  n = read();m = read();
  for (register int i = 1;i <= n;i++)
    for (register int j = 1;j < m;j++) {
      register int x;x = read();
      addedge((i - 1) * m + j, (i - 1) * m + j + 1, x);
      addedge((i - 1) * m + j + 1, (i - 1) * m + j, x);
    }
  for (register int i = 1;i < n;i++)
    for (register int j = 1;j <= m;j++) {
      register int x;x = read();
      addedge((i - 1) * m + j, i * m + j, x);
      addedge(i * m + j, (i - 1) * m + j, x);
    }
  p = read();
  for (register int i = 1;i <= p;i++)opt[i] = (op){ read(),read(),read(),read(),i,0x7fffffff };
  dfs(1, 1, n, m, 1, p);
  sort(opt + 1, opt + p + 1, cmp);
  for (register int i = 1;i <= p;i++) {
    printf("%d\n", opt[i].ans);
  }
  printf("Comlexity %u\n", Complexity);
}