#include <bits/stdc++.h>

using namespace std;

inline long long read() {
  long long x = 0;
  int f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
void write(const long long &x) {
  if (!x) {
    putchar('0');
    return;
  }
  char f[100];
  long long tmp = x;
  if (tmp < 0) {
    tmp = -tmp;
    putchar('-');
  }
  long long s = 0;
  while (tmp > 0) {
    f[s++] = tmp % 10 + '0';
    tmp /= 10;
  }
  while (s > 0) {
    putchar(f[--s]);
  }
}
inline double dread() {
  double r;
  double x = 0, t = 0;
  int s = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar()) {
    if (c == '-') {
      f = -1;
    }
    if (c == '.') {
      goto readt;
    }
  }
  for (; isdigit(c) && c != '.'; c = getchar()) {
    x = x * 10 + c - '0';
  }
readt:
  for (; c == '.'; c = getchar())
    ;
  for (; isdigit(c); c = getchar()) {
    t = t * 10 + c - '0';
    ++s;
  }
  r = (x + t / pow(10, s)) * f;
  return r;
}

inline void dwrite(long long x) {
  if (x == 0) {
    putchar(48);
    return;
  }
  int bit[20], p = 0, i;
  for (; x; x /= 10)
    bit[++p] = x % 10;
  for (i = p; i > 0; --i)
    putchar(bit[i] + 48);
}
inline void write(double x, int k) {
  static int n = pow(10, k);
  if (x == 0) {
    putchar('0');
    putchar('.');
    for (int i = 1; i <= k; ++i)
      putchar('0');
    return;
  }
  if (x < 0)
    putchar('-'), x = -x;
  long long y = (long long)(x * n) % n;
  x = (long long)x;
  dwrite(x), putchar('.');
  int bit[10], p = 0, i;
  for (; p < k; y /= 10)
    bit[++p] = y % 10;
  for (i = p; i > 0; i--)
    putchar(bit[i] + 48);
}

int totN;

struct Edge {
  int nxt;
  int to;
} edges[190],SCC_edges[190];
int head[190];
int SCC_head[190];
int cnt_edges;
int Hd(0);
int cnt_SCC_edges;
void add_edges(int x,int y) {
  ++cnt_edges;
  edges[cnt_edges].nxt=head[x];
  head[x]=cnt_edges;
  edges[cnt_edges].to=y;
}
void add_SCC_edges(int x,int y) {
  ++cnt_SCC_edges;
  edges[cnt_SCC_edges].nxt=SCC_head[x];
  SCC_head[x]=cnt_SCC_edges;
  SCC_edges[cnt_edges].to=y;
}
int dfn[190];
int low[190];
int ins[190];
vector<int> SCC[190];
int S[105];
int dfs_cnt(0);
int cnt_SCCs(0);
int in_SCC[190] = {0};
bool Idg[190] = {0};
bool Odg[190] = {0};
int IN0,OUT0;

void Tarjan(int x) {
  //printf("To %d %d\n", x, dfs_cnt);
  dfn[x] = ++dfs_cnt;
  low[x] = dfn[x];
  ins[x] = 1;
  S[++Hd] = x;
  int Sid(head[x]);
  while (Sid) {
    if (in_SCC[edges[Sid].to]) {
      Sid = edges[Sid].nxt;
      continue;
    }
    if (dfn[edges[Sid].to]) {
      low[x] = min(low[x], dfn[edges[Sid].to]);
    } else {
      Tarjan(edges[Sid].to);
      low[x] = min(low[x], low[edges[Sid].to]);
    }
    Sid = edges[Sid].nxt;
  }
  if(low[x] == dfn[x]) {
    ++cnt_SCCs;
    while (S[Hd] != x) {
      in_SCC[S[Hd]] = cnt_SCCs;
      ins[S[Hd]] = 0;
      --Hd;
    }
    in_SCC[S[Hd]]= cnt_SCCs;
    ins[S[Hd--]] = 0;
  }
  return;
}

int main() {
  freopen("P2746_3.in", "r", stdin);
  totN=read();
  for(int i=1; i<=totN; ++i) {
    int x=read();
    while(x) {
      add_edges(i,x);
      x=read();
    }
  }
  for(int i=1; i<=totN; ++i) {
    if(!dfn[i]) {
      Tarjan(i);
    }
    printf("%d %d\n", i, in_SCC[i]);
  }
  memset(Idg, 0, sizeof(Idg));
  for(int i=1; i<=totN; ++i) {
    if(Odg[i]) {
      continue;
    }
    for(int j=head[i]; j; j=edges[j].nxt) {
      if(Idg[edges[j].to]) {
        continue;
      }
      if(in_SCC[i]!=in_SCC[edges[j].to]) {
        printf("%d -> %d\n", i, edges[j].to);
        Odg[i] = 1;
        Idg[edges[j].to] = 1;
      }
    }
  }
  IN0 = 0;
  for(int i=1; i<=cnt_SCCs; ++i) {
    if(!Idg[i]) {
      ++IN0;
    }
    if(!Odg[i]) {
      ++OUT0;
    }
  }
  if(cnt_SCCs==1) {
    putchar('1');
    putchar('\n') ;
    putchar('0');
  } else {
    write(IN0);
    putchar('\n');
    write(max(IN0,OUT0));
  }
  return 0;
} //ROSMONTIS Code
