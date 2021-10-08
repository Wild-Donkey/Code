#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
long long n, m, ans = 0, two[70];
int t, bits;
bool flg;
char ch;
string s;
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
  two[0] = 1;
  for (int i = 1; i <= 62; i++) {
    two[i] = two[i - 1] << 1;
    // printf("%lld %lld\n", i, two[i]);
  }
  scanf("%d", &t);
  for (int T = 1; T <= t; T++) {
    ans = 0;
    scanf("%lld%lld", &n, &m);
    if (n == 1) {
      printf("0\n");
      continue;
    }
    for (register int i = 1; i <= 62; i++) {
      if ((n >= two[i - 1]) && (n < two[i])) {
        bits = i;
        break;
      }
    }
    ans = two[bits] - 1;
    ans %= 1000000007;
    bits--;
    long long tmp = m >> 1;
    m -= tmp;
    tmp *= m;
    tmp %= 1000000007;
    ans *= tmp;
    ans %= 1000000007;
    // printf("%d\n", bits);
    printf("%lld\n", ans);
  }
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}
