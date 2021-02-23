#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1024;
unsigned int x, y, n, m, l;
char a[105][105];
unsigned long long random(unsigned long long s, unsigned long long t)
{
    return ((long long)rand() * rand() * rand()) % (t - s) + s + 1;
}
int main()
{
  srand(time(0));
  freopen("P2657.in", "w", stdout);
  n = random(1, 1000000000);
  printf("%u %u\n", n, random(n, 2000000000));
  return 0;
}
