#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
const unsigned Ans[120] = {11, 10, 9, 14, 13, 12, 11, 9, 8, 14, 13, 11, 10, 9, 8, 13, 12, 11, 10, 8, 14, 13, 12, 10, 9, 8, 14, 12, 11, 10, 9, 14, 13, 12, 11, 9, 8, 14, 13, 11, 10, 9, 8, 13, 12, 11, 10, 8, 14, 13, 12, 10, 9, 8, 14, 12, 11, 10, 9, 14, 13, 12, 11, 9, 8, 14, 13, 11, 10, 9, 8, 13, 12, 11, 10, 8, 14, 13, 12, 10, 9, 8, 14, 12, 11, 10, 9, 14, 13, 12, 11, 9, 8, 14, 13, 11, 10, 9, 8, 13, 12, 11, 10, 8, 14, 13, 12};
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
//  n = RD();
//  printf("BC %u\n", BC);
  printf("%u\n", Ans[RD() - 1913]);
//  }
//  system("pause");
  return Wild_Donkey;
}

