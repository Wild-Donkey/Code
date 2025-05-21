#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <math.h>
#include <functional> 

#define endl '\n'
#define pii pair<int, int>
#define pdd pair<double, double> 
#define fi first
#define se second
// #define push push_back
#define eb emplace_back
#define codeforces cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false)
#define bendl(x) x.begin(), x.end()
#define siz(x) ((int)(x).size())
// #define int long long

using namespace std;

const int inf = 1 << 30;
const int mod = 998244353;
const int N = 2e5 + 10, M = N << 1;
// const int Dire[2][4] = {{}} 
struct Quest {
  int x, y;
  char z[2];
}a[N];
unsigned Ans[N];
char Mp[1005][1005], Out[1005][1005];
unsigned Let(int x, int y) {
  queue<pair<unsigned, unsigned> > Q;
  unsigned Rt = 0;
  Out[x][y] = 1, Q.push({x, y});
  while (Q.size()) {
    int Curx = Q.front().first, Cury = Q.front().second;
    Q.pop(), ++Rt;
    --Curx;
    if((!Out[Curx][Cury]) && (Mp[Curx][Cury] == 'D' || Mp[Curx][Cury] == '?')) Out[Curx][Cury] = 1, Q.push({Curx, Cury});
    Curx += 2;
    if((!Out[Curx][Cury]) && (Mp[Curx][Cury] == 'U' || Mp[Curx][Cury] == '?')) Out[Curx][Cury] = 1, Q.push({Curx, Cury});
    --Cury, --Curx;
    if((!Out[Curx][Cury]) && (Mp[Curx][Cury] == 'R' || Mp[Curx][Cury] == '?')) Out[Curx][Cury] = 1, Q.push({Curx, Cury});
    Cury += 2;
    if((!Out[Curx][Cury]) && (Mp[Curx][Cury] == 'L' || Mp[Curx][Cury] == '?')) Out[Curx][Cury] = 1, Q.push({Curx, Cury});
  }
  return Rt;
}
void solve(){
  int n, m;
  scanf("%d%d", &n, &m);
  memset(Mp, 0, n + 2);
  memset(Mp[n + 1], 0, n + 2);
  memset(Out, 0, n + 2);
  memset(Out[n + 1], 0, n + 2);
  for (unsigned i = 1; i <= n; ++i) {
    Mp[i][0] = Mp[i][n + 1] = 0;
    memset(Mp[i] + 1, '?', n);
    memset(Out[i], 0, n + 2);
  }
  for (unsigned i = 1; i <= m; ++i) {
    scanf("%d%d%s", &(a[i].x), &(a[i].y), a[i].z);
    Mp[a[i].x][a[i].y] = a[i].z[0];
  }
  // for (unsigned i = 1; i <= n; ++i) {
  //   printf("%s\n", Mp[i] + 1);
  // }
  queue<pair<unsigned, unsigned> > Q;
  for (unsigned i = 1; i <= n; ++i) {
    if(Mp[1][i] == 'U' || Mp[1][i] == '?') Out[1][i] = 1;
    if(Mp[n][i] == 'D' || Mp[n][i] == '?') Out[n][i] = 1;
    if(Mp[i][1] == 'L' || Mp[i][1] == '?') Out[i][1] = 1;
    if(Mp[i][n] == 'R' || Mp[i][n] == '?') Out[i][n] = 1;
  }
  for (unsigned i = 1; i <= n; ++i) {
    if(Out[1][i]) Q.push({1, i});
    if(Out[n][i]) Q.push({n, i});
  }
  for (unsigned i = 2; i < n; ++i) {
    if(Out[i][1]) Q.push({i, 1});
    if(Out[i][n]) Q.push({i, n});
  }
  Ans[n] = 0;
  while (Q.size()) {
    int Curx = Q.front().first, Cury = Q.front().second;
    Q.pop(), ++Ans[m];
    --Curx;
    if((!Out[Curx][Cury]) && (Mp[Curx][Cury] == 'D' || Mp[Curx][Cury] == '?')) Out[Curx][Cury] = 1, Q.push({Curx, Cury});
    Curx += 2;
    if((!Out[Curx][Cury]) && (Mp[Curx][Cury] == 'U' || Mp[Curx][Cury] == '?')) Out[Curx][Cury] = 1, Q.push({Curx, Cury});
    --Cury, --Curx;
    if((!Out[Curx][Cury]) && (Mp[Curx][Cury] == 'R' || Mp[Curx][Cury] == '?')) Out[Curx][Cury] = 1, Q.push({Curx, Cury});
    Cury += 2;
    if((!Out[Curx][Cury]) && (Mp[Curx][Cury] == 'L' || Mp[Curx][Cury] == '?')) Out[Curx][Cury] = 1, Q.push({Curx, Cury});
  }
  for (unsigned i = m; i > 1; --i) {
    Ans[i - 1] = Ans[i];
    Mp[a[i].x][a[i].y] = '?';
    if(Out[a[i].x][a[i].y]) continue;
    if(a[i].x == 1 || a[i].x == n || a[i].y == 1 || a[i].y == n 
          || Out[a[i].x - 1][a[i].y] || Out[a[i].x + 1][a[i].y]
          || Out[a[i].x][a[i].y - 1] || Out[a[i].x][a[i].y + 1]) Ans[i - 1] += Let(a[i].x, a[i].y); 
  }
  n *= n;
  for (unsigned i = 1; i <= m; ++i) printf("%u\n", n - Ans[i]);
}

signed main(){
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);

  // codeforces;
  
  int t = 1; //cin >> t;
  while(t--) solve();
  return 0;
}