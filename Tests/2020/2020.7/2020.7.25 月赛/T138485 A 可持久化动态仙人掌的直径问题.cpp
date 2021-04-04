#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
long long t, n, m, a[10005], ans = 0;
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
  cin >> n;
  cin >> m;
  ans = 1;
  while (pow(ans, m) <= n) {
  	ans++;
  }
  ans--;
  printf("%d\n", ans);
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}

