#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1024;
int n, l;
int random(int s, int t)
{
    return rand() % (t - s) + s + 1;
}
int main()
{
    freopen("1282.in", "w", stdout);
    srand(time(0));
    n = 100;
    printf("%d\n", n);
    for (register int i(1); i <= n; ++i) {
      for (register int j(1); j <= n; ++j) {
        printf("%d ", random(1, 255) - 128);
      }
      putchar('\n');
    }
    return 0;
}

