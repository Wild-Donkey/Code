#include <cstdio>
#include <iostream>
using namespace std;
int n, a, b;
int main() {
  cin >> n;
  for (register int i(1); i <= n; ++i) {
    cin >> a >> b;
    if (a < b) {
      swap(a, b);
    }
    printf("%d\n", (a - b + 9) / 10);
  }
  return 0;
}