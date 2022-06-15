#include "perm.h"
#include<vector>
#include<cstdio>
using namespace std;
long long List[70];
std::vector<int> construct_permutation(long long k) {
	vector<int> Rt, Rev;
  int Cnt(0);
  List[0] = 1, --k;
  for(unsigned i(1); i < 64; ++i) List[i] = List[i - 1] << 1;
  for(unsigned i(0); i < 64; ++i) --List[i];
  // for(unsigned i(0); i < 64; ++i) printf("%u %lld\n", i, List[i]);
  for(unsigned i(63); i; --i) {
    while (k >= List[i]) {
      // printf("k %lld List %lld Cnt %d i %u\n", k, List[i], Cnt, i);
      k -= List[i];
      // printf("k Bec %lld\n", k);
      for (int j(Cnt + i - 1); j >= Cnt; --j) /*printf("j %d\n", j),*/ Rev.push_back(j);
      Cnt += i;
      // printf("Done Add %d\n", Cnt);
    }
  }
  // printf("Size %d\n", Rev.size());
  for (unsigned i(Rev.size() - 1); ~i; --i) Rt.push_back(Rev[i]);
  // for (auto i:Rt) printf("%u ", i); putchar(0x0A);
  return Rt;
}
//10000
//01100
//g++ -DEVAL -std=gnu++17 -O2 -pipe -static -s -o perm grader.cpp perm.cpp