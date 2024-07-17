#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
struct Sug {
  int L, R, Num;
  const char operator<(const Sug &x) const { return R < x.R; }
} a[5005];
int h, n, ans = 0;
bool tr[30005] = {0};
int main() {
  cin >> n >> h;
  for (int i = 1; i <= h; i++) cin >> a[i].L >> a[i].R >> a[i].Num;
  sort(a + 1, a + 1 + h);
  for (int i = 1; i <= h; i++) {
    int cnt = 0;
    for (int j = a[i].L; j <= a[i].R; j++) cnt += tr[j];
    if (cnt >= a[i].Num) continue;

    for (int j = a[i].R; j >= a[i].L && cnt < a[i].Num; --j) {
      if (tr[j]) continue;
      tr[j] = 1;
      ++cnt, ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}