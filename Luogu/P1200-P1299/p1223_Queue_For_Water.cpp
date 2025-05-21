#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
pair<int, int>a[1005];
int A, B, n, sum(0);
double ans = 0;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> A;
    a[i] = { A, i };
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    cout << a[i].second << " ";
  }
  for (int i = 1; i <= n; i++) {
    ans += sum;
    sum += a[i].first;
  }
  ans /= n;
  printf("\n%.2lf\n", ans);
  return 0;
}