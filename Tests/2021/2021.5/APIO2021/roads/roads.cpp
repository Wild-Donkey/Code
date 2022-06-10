#include "roads.h"

#include <vector>
#include <algorithm>


std::vector<long long> minimum_closure_costs(int N, std::vector<int> U, std::vector<int> V, std::vector<int> W) {
  std::vector<long long>ans(N);
  long long f[100005][2];
  for (int i(2); i < N; ++i) {
    ans[i] = 0;
  }
  ans[0] = 0; 
  for (int i(0); i < N - 1; ++i) {
    ans[0] += W[i];
  }
  f[0][0] = W[0];
  f[0][1] = 0;
  for (int i(1); i < N - 1; ++i) {
    f[i][0] = W[i] + ((f[i - 1][1] < f[i - 1][0]) ? f[i - 1][1] : f[i - 1][0]);
    f[i][1] = f[i - 1][0];
  }
  ans[1] = (f[N - 2][0] < f[N - 2][1]) ? f[N - 2][0] : f[N - 2][1];
  return ans;
}
