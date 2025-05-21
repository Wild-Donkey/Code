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
#define int long long

using namespace std;

const int inf = 1ll << 60;
const int mod = 998244353;
const int N = 5e5 + 10, M = N << 1;

int a[N];
void solve(){
  int n, m, Ans = inf;
  cin >> n, m = n >> 1;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) a[i] += a[i - 1];
  for (int i = 0; i < m; ++i) Ans = min(Ans, a[i + m + 1] - a[i]);
  cout << Ans << ' ' << a[n] - Ans << endl;
}

signed main(){
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);

  // codeforces;
  
  int t = 1;  cin >> t;
  while(t--) solve();
  return 0;
}