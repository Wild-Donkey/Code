#include "perm.h"
#include<vector>
#include<cstdio>
using namespace std;
long long List[70];
unsigned a[205], L(100), R(99), Mx(200);
inline void Pb() {/*printf("Pb %u", Mx - 1), */a[++R] = --Mx;}
inline void Pf() {/*printf("Pf %u", Mx - 1), */a[--L] = --Mx;}
std::vector<int> construct_permutation(long long k) {
	vector<int> Rt;
  unsigned b[70], Cur(0);
  L = 100, R = 99, Mx = 200;
  while (k) b[Cur] = (k & 1), k >>= 1, ++Cur; --Cur;
  // printf("Cur %u\n", Cur);
  Pb();
  if(b[Cur - 1]) Pb();
  for (unsigned i(Cur - 2); ~i; --i) {Pf(); if(b[i]) Pb();}
  for (unsigned i(L); i <= R; ++i) Rt.push_back(a[i] - Mx);
  // for (auto i:Rt) printf("%u ", i); putchar(0x0A);
  return Rt;
}
//1000000000000000000
//10000
//01100
//g++ -DEVAL -std=gnu++17 -O2 -pipe -static -s -o perm grader.cpp perm.cpp
//71.2