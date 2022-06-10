#include "roads.h"

#include <vector>
#include <algorithm>

std::vector<long long> minimum_closure_costs(int N, std::vector<int> U, std::vector<int> V, std::vector<int> W) {
  std::vector<long long>ans(N);
  int Edge[100005];
  for (int i(0); i < N - 1; ++i) {
    Edge[i] = W[i];
  }
  std::sort(Edge, Edge + N - 1);
  ans[N - 1] = 0;
  for (int i(N - 2); i >= 0; --i) {
    ans[i] = ans[i + 1] + Edge[N - i - 2];
  }
  return ans;
}
