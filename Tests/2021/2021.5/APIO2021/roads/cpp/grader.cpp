#include "roads.h"

#include <cassert>
#include <cstdio>


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
//    printf("%d %lld %lld\n", i, f[i][0], f[i][1]);
  }
  ans[1] = (f[N - 2][0] < f[N - 2][1]) ? f[N - 2][0] : f[N - 2][1];
  return ans;
}

int main() {
  int N;
  assert(1 == scanf("%d", &N));
  std::vector<int> U(N - 1), V(N - 1), W(N - 1);
  for (int i = 0; i < N - 1; ++i) {
    assert(3 == scanf("%d %d %d", &U[i], &V[i], &W[i]));
  }

  std::vector<long long> closure_costs = minimum_closure_costs(N, U, V, W);
  for (int i = 0; i < static_cast<int>(closure_costs.size()); ++i) {
    if (i > 0) {
      printf(" ");
    }
    printf("%lld",closure_costs[i]);
  }
  printf("\n");
  return 0;
}
/*
5
0 1 312
1 2 235
2 3 455
3 4 19
*/
