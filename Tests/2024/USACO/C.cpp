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
// #define int long long

using namespace std;

const int inf = 1 << 30;
const int mod = 998244353;
const int N = 2e4 + 10, M = N << 1;

void Udt(int &x, int y) {x = max(x, y);}

int f[N][3][2];
char Ans[700][4], Cnt = 0;
void solve(){
  int n, m;
  string a;
  cin >> n >> m >> a;
  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < 26; ++j) if(j != i) {
      memset(f[0], 0xaf, 24);
      f[0][0][0] = 0;
      for (int k = 0; k < n; ++k) {
        memset(f[k + 1], 0xaf, 24);

        if(i == a[k] - 'a') {
          f[k + 1][1][0] = f[k][0][0];
          f[k + 1][1][1] = f[k][0][1];
        } else {
          f[k + 1][1][1] = f[k][0][0];
          f[k + 1][0][0] = f[k][0][0];
          f[k + 1][0][1] = f[k][0][1];
        }

        if(j == a[k] - 'a') {
          f[k + 1][2][0] = f[k][1][0];
          f[k + 1][2][1] = f[k][1][1];
          Udt(f[k + 1][0][0], f[k][2][0] + 1);
          Udt(f[k + 1][0][1], f[k][2][1] + 1);
        } else {
          f[k + 1][2][1] = f[k][1][0];
          Udt(f[k + 1][0][1], f[k][2][0] + 1);
          if(i == a[k] - 'a') {
            Udt(f[k + 1][1][0], f[k][1][0]);
            Udt(f[k + 1][1][0], f[k][2][0]);
            Udt(f[k + 1][1][1], f[k][1][1]);
            Udt(f[k + 1][1][1], f[k][2][1]);
          } else {
            Udt(f[k + 1][0][0], f[k][1][0]);
            Udt(f[k + 1][0][0], f[k][2][0]);
            Udt(f[k + 1][0][1], f[k][1][1]);
            Udt(f[k + 1][0][1], f[k][2][1]);
          }
        }
      }
      Udt(f[n][0][0], f[n][2][0]);
      Udt(f[n][0][0], f[n][1][0]);
      Udt(f[n][0][1], f[n][2][1]);
      Udt(f[n][0][1], f[n][1][1]);
      Udt(f[n][0][1], f[n][0][0]);
      if(f[n][0][1] >= m) {
        // printf("%c And %c %d\n", i + 'a', j + 'a', f[n][0][1]);
        ++Cnt;
        Ans[Cnt][0] = 'a' + i;
        Ans[Cnt][1] = 'a' + j;
        Ans[Cnt][2] = 'a' + j;
        Ans[Cnt][3] = 0;
      }
    }
  }
  printf("%d\n", Cnt);
  for (int i = 1; i <= Cnt; ++i) printf("%s\n", Ans[i]);
}

signed main(){
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);

  // codeforces;
  
  int t = 1; // cin >> t;
  while(t--) solve();
  return 0;
}