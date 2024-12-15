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
#define pb push_back
#define eb emplace_back
#define codeforces cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false)
#define bendl(x) x.begin(), x.end()
#define siz(x) ((int)(x).size())
#define int long long

using namespace std;

const int inf = 1 << 30;
const int mod = 998244353;
const int N = 2e5 + 10, M = N << 1;

struct Node {
  int s, t;
  bool operator < (const Node & x) const {return s + t < x.s + x.t;}
}a[N];
void solve(){
  int n;
  cin >> n;
  for (unsigned i = 1; i <= n; ++i) cin >> a[i].s >> a[i].t;
  sort(a + 1, a + n + 1);
  int Cur = 0;
  priority_queue<int> Q;
  for (unsigned i = 1; i <= n; ++i) {
    Cur += a[i].t, Q.push(a[i].t);
    // printf("Cur %lld, %lld\n", Cur, a[i].s + a[i].t);
    if(Cur > a[i].s + a[i].t) {
      Cur -= Q.top(), Q.pop();
    }
  }
  // printf("(%u)\n", Q.size());
  printf("%u\n", Q.size());
}

signed main(){
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);

  // codeforces;
  
  int t = 1; cin >> t;
  while(t--) solve();
  return 0;
}