#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
struct Matrix {
  long long a[105][105];
} mtx;
long long k, N;
Matrix operator*(Matrix x, Matrix y) {
  Matrix ans;
  long long tmp;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      for (int k = 1; k <= N; k++) {
        tmp = x.a[k][j] * y.a[i][k];
        tmp %= 1000000007;
        ans.a[i][j] += tmp;
        ans.a[i][j] %= 1000000007;
      }
    }
  }
  return ans;
}
void print(Matrix x) {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      printf("%lld ", x.a[i][j]);
    }
    printf("\n");
  }
  return;
}
Matrix power(Matrix x, long long y) {
  Matrix ans;
  if (y == 0) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if (i == j) {
          ans.a[i][j] = 1;
        } else {
          ans.a[i][j] = 0;
        }
      }
    }
    return ans;
  }
  if (y == 1) {
    return x;
  }
  if (y == 2) {
    return (x * x);
  }
  if (y % 2) {  //奇次幂
    ans = power(x, y >> 1);
    return ans * ans * x;
  } else {
    ans = power(x, y >> 1);
    return ans * ans;
  }
  return ans;
}
int main() {
  scanf("%lld%lld", &N, &k);
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      scanf("%lld", &mtx.a[i][j]);
    }
  }
  print(power(mtx, k));
  return 0;
}