#include <bits/stdc++.h>
using namespace std;
long long N, M, n, A(0), B(0), m;
int main() {
  cin >> n, m = pow(n, (double)1 / 3);
  for (int i(1); i <= m; ++i) { M = sqrt(N = n / i);for (int j(i + 1); j <= M; ++j) A += (N / j) - j; B += ((n / i) / i) - i + (int)sqrt(n / i) - i; }
  printf("%lld\n", A * 6 + B * 3 + m);
  return 0;
}