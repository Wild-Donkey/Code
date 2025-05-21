#include <iostream>
#include <algorithm>
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
#define pb push_back
#define eb emplace_back
#define codeforces cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false)
#define bendl(x) x.begin(), x.end()
#define siz(x) ((int)(x).size())
// #define int long long

using namespace std;

const int inf = 1 << 30;
const int mod = 998244353;
const int N = 2e5 + 10, M = N << 1;

short X[1005][1005], Y[1005][1005], Z[1005][1005];

void solve(){
  int n, m, A, B, C, Ans = 0;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) 
    for(int j = 0; j < n; ++j)
      X[i][j] = n;
  for (int i = 0; i < n; ++i) 
    for(int j = 0; j < n; ++j)
      Y[i][j] = n;
  for (int i = 0; i < n; ++i) 
    for(int j = 0; j < n; ++j)
      Z[i][j] = n;
  for (int i = 0; i < m; ++i) {
    cin >> A >> B >> C;
    Ans += ((--X[B][C]) == 0);
    Ans += ((--Y[A][C]) == 0);
    Ans += ((--Z[A][B]) == 0);
    printf("%d\n", Ans);
  }
}

signed main(){
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);

  // codeforces;
  
  int t = 1; // cin >> t;
  while(t--) solve();
  return 0;
}