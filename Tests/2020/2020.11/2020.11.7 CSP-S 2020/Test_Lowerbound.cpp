#include <cstdio>
#include <algorithm>
using namespace std;
int A[10005];
int main() {
  for (register int i (1); i <= 100; ++i) {
    A[i] = i << 1;
  }
  printf("%d %d %d\n", lower_bound(A + 1, A + 5 + 1, 1000) - A, A[lower_bound(A + 1, A + 5 + 1, 1000) - A], A[6]);
}
