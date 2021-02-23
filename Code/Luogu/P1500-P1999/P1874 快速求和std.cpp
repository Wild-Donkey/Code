#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#define ll unsigned long long
#define E 100007
using namespace std;
string sr;
ll a[E], s[43][43], f[43][E];  // 前 i 位数字 组成 j 的最少加法次数   f[i][j] =
                               // min { f[i-k][j-s[i-k+1][i]] + 1 , f[i][j] } ;
int main() {
  cin >> sr;
  ll len = sr.length();
  for (ll i = 0; i < len; i++) a[i + 1] = sr[i] - '0';
  for (ll i = 1; i <= len; i++) {
    s[i][i] = a[i];
    for (ll j = i; j - i <= 11 && j <= len; j++)
      s[i][j] = s[i][j - 1] * 10 + a[j];
  }
  ll n;
  cin >> n;
  for (ll i = 0; i <= len + 1; i++)
    for (ll j = 0; j <= n + 1; j++) f[i][j] = 0x7fffffff;
  f[0][0] = 0;
  for (ll i = 1; i <= len; i++)
    for (ll k = 1; k <= 11 && i + k <= len + 3; k++)
      if (i >= k)
        for (ll j = s[i - k + 1][i]; j <= n; j++)
          f[i][j] = min(f[i - k][j - s[i - k + 1][i]] + 1, f[i][j]);
  if (n == 0)
    cout << 0 << endl;
  else if (f[len][n] > len)
    cout << -1 << endl;
  else
    cout << f[len][n] - 1 << endl;
  return -0;
}