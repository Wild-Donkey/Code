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
inline unsigned long long RD() {
  unsigned long long intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
namespace Solve {
  unsigned a[10];
  inline void Init() {
    a[0] = 1;
    for (unsigned i(1); i <= 9; ++i) a[i] = a[i - 1] + i;
  }
  inline void Work(unsigned x) {
    if(x == 3 || x == 5 || x == 8) {printf("-1\n"); return;}
    if(x == 1) {printf("1\n1 1\n"); return;}
    if(x == 2) {printf("1\n2 2\n"); return;}
    if(x == 6) {printf("1\n3 6\n"); return;}
    unsigned B(upper_bound(a + 0, a + 10, x) - a - 1);
    if(x == a[B] + 1) {
      if(x == 12) {printf("2\n3 4\n4 8\n"); return;}
      printf("%u\n3 5\n", B - 2);
      for (unsigned i(4); i <= B - 2; ++i) printf("%u %u\n", i, i - 1);
      printf("%u %u\n%u %u\n", B - 1, B - 3, B, B << 1);
      return;
    }
    if(x == a[B] + 2) {
      printf("%u\n3 5\n", B - 1);
      for (unsigned i(3); i < B; ++i) printf("%u %u\n", i + 1, i);
      printf("%u %u\n", B + 1, B + 1); return;
    }
    printf("%u\n", B);
    if(x == a[B]) {
      for (unsigned i(1); i < B; ++i) printf("%u %u\n", i + 1, i);
      printf("%u %u\n", B + 1, B + 1); return;
    }
    x -= a[B];
    for (unsigned i(1); i + 2 <= x; ++i) printf("%u %u\n", i + 1, i);
    if(x == B) {printf("%u %u\n%u %u\n", B, B - 2, B + 1, (B + 1) << 1);return;}
    printf("%u %u\n%u %u\n", x, x - 2, x + 1, 1 + (x << 1));
    for (unsigned i(x + 1); i < B; ++i) printf("%u %u\n", i + 1, i);
    printf("%u %u\n", B + 1, B + 1);
  }
}
vector<unsigned> List[25];
unsigned long long a[25];
unsigned long long n, A, B, C;
inline void Do (unsigned x, unsigned long long y) {
  a[x] -= y, a[x + 1] += (x + 1) * y;
}
inline void Do (unsigned x) {return Do(x, 1);}
inline void Add(unsigned x) {for (auto i:List[x]) Do(i);}
inline void Prt() {
  unsigned Cnt(0);
  for (unsigned i(2); i <= 24; ++i) if(a[i]) ++Cnt;
  printf("%u\n", Cnt);
  for (unsigned i(2); i <= 24; ++i) if(a[i]) printf("%u %llu\n", i, a[i]);
}
//  inline void Clr() {}
signed main() {
//  freopen("split.in", "r", stdin);
//  freopen("split.out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  for (unsigned i(2); i <= 5; ++i) List[i].push_back(i);
  for (unsigned i(6); i <= 10; ++i) 
    List[i].push_back(i >> 1), List[i].push_back(i - List[i][0]);
  for (unsigned i(11); i <= 15; ++i) 
    List[i].push_back(i / 3), List[i].push_back((i - List[i][0]) >> 1),
    List[i].push_back(i - List[i][0] - List[i][1]);
  List[16].push_back(3), List[16].push_back(5);
  List[16].push_back(4), List[16].push_back(4);
  List[17].push_back(4), List[17].push_back(5);
  List[17].push_back(4), List[17].push_back(4);
  List[18].push_back(4), List[18].push_back(5);
  List[18].push_back(4), List[18].push_back(5);
  List[19].push_back(4), List[19].push_back(5);
  List[19].push_back(5), List[19].push_back(5);
  List[20].push_back(5), List[20].push_back(5);
  List[20].push_back(5), List[20].push_back(5);
  List[21].push_back(3), List[21].push_back(3);
  List[21].push_back(5), List[21].push_back(5), List[21].push_back(5);
  List[22].push_back(3), List[22].push_back(4);
  List[22].push_back(5), List[22].push_back(5), List[22].push_back(5);
  List[23].push_back(4), List[23].push_back(4);
  List[23].push_back(5), List[23].push_back(5), List[23].push_back(5);
  Solve::Init(), n = RD();
  for (unsigned i(1); i <= n; ++i) {
    A = RD();
    if(A < 40) {Solve::Work(A); continue;}
    memset(a, 0, sizeof(a));
    for (unsigned i(2); i <= 5; ++i) a[i] = i - 1; C = a[6] = 6, B = 10, A -= B;
    while ((C + 1) * a[C] <= A) Do(C, a[C]), ++C; A -= a[C];
//    printf("%llu %llu\n", A, a[C]);
    if((A % C) == 1) {
      B = A / C;
      if(B) Do(C, B - 1), Add(C + 1);
      else a[C] -= C, ++a[C - 1], Add(C);
    } else Do(C, A / C), Add(A % C);
    Prt();
  }
//  }
  return Wild_Donkey;
}

