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
const int N = 1e5 + 10, M = N << 1;

int a[N];
struct Node {
  vector<pair<Node*, unsigned> > Ed;
  unsigned Dis;
  bool Vis;
}Nd[N];
void solve(){
  int n, m, A, B, C;
  cin >> n >> m;
  for (int i = 0; i <= n; ++i) Nd[i].Ed.clear(), Nd[i].Dis = 0x3f3f3f3f, Nd[i].Vis = 0;
  for (int i = 0; i < n; ++i) {
    Nd[i].Ed.pb({Nd + i + 1, 1});
    Nd[i + 1].Ed.pb({Nd + i, 0});
  }
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= m; ++i){
    cin >> A >> B >> C;
    A = lower_bound(a + 1, a + n + 1, A) - a;
    B = upper_bound(a + 1, a + n + 1, B) - a - 1;
    C = B - A + 1 - C;
    Nd[A - 1].Ed.pb({Nd + B, C});
  }
  priority_queue<pair<unsigned, Node*>> Q;
  Nd[0].Dis = 0;
  Q.push({0x3f3f3f3f - 0, Nd});
  while(Q.size()) {
    Node* Cur = Q.top().second;
    Q.pop();
    if(Cur->Vis) continue;
    Cur->Vis = 1;
    for (auto i:Cur->Ed) {
      if(i.first->Dis > Cur->Dis + i.second) 
        i.first->Dis = Cur->Dis + i.second, Q.push({0x3f3f3f3f - i.first->Dis, i.first});
    }
  }
  printf("%u\n", Nd[n].Dis);
}

signed main(){
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);

  // codeforces;
  
  int t = 1;  cin >> t;
  while(t--) solve();
  return 0;
}