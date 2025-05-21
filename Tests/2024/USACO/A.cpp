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
const int Ten[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
int Up(int Digi, int Limi) {
  // printf("U(%d, %d)\n", Digi, Limi);
  if(Digi == 0) return 0;
  int Fst = Limi / Ten[Digi - 1];
  if(Fst < 4) return 0;
  Limi -= Fst * Ten[Digi - 1];
  int Rt = 0;
  if(Fst == 4) return Up(Digi - 1, Limi);
  return (Limi + 1) + Up(Digi - 1, Ten[Digi - 1] - 1) + (Fst - 5) * Ten[Digi - 1];
}
int Calc(int Digi, int Limi) {
  // printf("C(%d, %d)\n", Digi, Limi);
  if(Digi <= 1) return 0;
  int Fst = Limi / Ten[Digi - 1];
  Limi -= Fst * Ten[Digi - 1];
  if(!Fst) return Calc(Digi - 1, Limi);
  int Rt = Calc(Digi - 1, Ten[Digi - 1]);
  if(Fst < 4) return Rt;
  if(Fst == 4) Rt += Up(Digi - 1, Limi);
  else Rt += Up(Digi - 1, Ten[Digi - 1] - 1);
  // printf("=%d\n", Rt);
  return Rt;
}
void solve(){
  int n, Tmpn, Cntn = 0;
  cin >> n;
  Tmpn = n;
  while(Tmpn > 1) Tmpn /= 10, ++Cntn;
  cout << Calc(Cntn, n) << endl;
}

signed main(){
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);

  // codeforces;
  
  int t = 1; cin >> t;
  while(t--) solve();
  return 0;
}