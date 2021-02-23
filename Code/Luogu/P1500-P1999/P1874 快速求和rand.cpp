#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
int a;
string s;
int main() {
  freopen("P1874.in", "w", stdout);
  srand(time(0));
  printf("%lld%lld%lld%lld\n", rand() * rand(), rand() * rand(),
         rand() * rand(), rand() * rand());
  printf("%d\n", rand() * rand() % 1000000);
  fclose(stdout);
  return 0;
}