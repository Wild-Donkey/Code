#include <cstdio>
using namespace std;
int main() {
  int t, n;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    scanf("%d", &n);
    int a = 0;
    for (int j = 1; j <= n; j++) {
      int h, l;
      scanf("%d%d", &h, &l);
      if (h > l) a++;
    }
    printf("%d\n", a);
  }
  return 0;
}