#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int n, m, q;
ll a[N], b[N], c[N << 1];
double ans;
void solve1(){
    int id; ll x;
    scanf("%d%lld", &id, &x);
    if (id == 1) for (int i = 1; i <= m; i++) a[i] += x;
    else for (int i = 1; i <= n; i++) b[i] += x;
    for (int i = 1; i <= m; i++) c[i] = a[i];
    for (int i = 1; i <= n; i++) c[m + i] = b[i];
    if (id == 1) for (int i = 1; i <= m; i++) a[i] -= x;
    else for (int i = 1; i <= n; i++) b[i] -= x;
    sort(c + 1, c + m + n + 1);
    if (n + m & 1) printf("%lld\n", c[(n + m >> 1) + 1]);
    else {
      if ((c[n + m >> 1] + c[(n + m >> 1) + 1]) & 1) printf("%lld.5\n", (c[n + m >> 1] + c[(n + m >> 1) + 1]) >> 1);        else printf("%lld\n", (c[n + m >> 1] + c[(n + m >> 1) + 1]) >> 1);
    }
}
int main(){
  freopen("C.in", "r", stdin);
  freopen("C.ans", "w", stdout);
    scanf("%d%d%d", &m, &n, &q);
    for (int i = 1; i <= m; i++) scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
    while (q--) solve1();
    return 0;
}
