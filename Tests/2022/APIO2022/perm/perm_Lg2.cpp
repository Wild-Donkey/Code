#include "perm.h"
#include<vector>
#include<cstdio>
using namespace std;
inline unsigned Solve (vector<int> &x, long long k, unsigned Beg) {
  // printf("Solve %lld\n", k);
  if(k == 1) { x.push_back(0); return 1;}
  unsigned a[70], Cur(0), Cnt(0), Last(0);
  while (k) a[Cur] = (k & 1), ++Cur, k >>= 1;
  for (unsigned i(0); i < Cur; ++i) if(a[i]) Cnt += i, ++Last;
  // printf("Cnt %u\n", Cnt);
  unsigned Top(Cnt - 1);
  for (unsigned i(1); i < Cur; ++i) if(a[i]) {
    unsigned CR(Top - i + 1);
    for(unsigned j(0); j < i; ++j) x.push_back(CR++);
    Top -= i;
  }
  Last = Solve(x, Last, Beg + Cnt);
  for (unsigned i(0); i < Cnt; ++i) x[Beg + i] += Last;
  return Cnt += Last;
}
std::vector<int> construct_permutation(long long k) {
	vector<int> Rt;
  Solve(Rt, k - 1, 0);
  // for (auto i:Rt) printf("%u ", i); putchar(0x0A);
  return Rt;
}
//10000
//01100
//g++ -DEVAL -std=gnu++17 -O2 -pipe -static -s -o perm grader.cpp perm.cpp