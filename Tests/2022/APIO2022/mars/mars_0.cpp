#include "mars.h"
unsigned Fa[16005], Stack[16005], *STop(Stack), Cnt(0), N;
inline unsigned Find(unsigned x) {
  while (Fa[x] ^ x) *(++STop) = x, x = Fa[x];
  while (STop > Stack) Fa[*(STop--)] = x;
  return x;
}
inline void Merge(unsigned x, unsigned y) { /*printf("Merge %u - %u\n", x, y);*/if(x ^ y) --Cnt, Fa[y] = x; }
inline unsigned Get(unsigned x, unsigned y) {/*printf("Get (%u, %u)\n", x, y);*/return x * N + y;}
std::string process(std::vector <std::vector<std::string>> a, int i, int j, int k, int n) {
  // printf("Here %u %u At %u Tot %u\n", i, j, k, N);
  // printf("%c %c %c\n%c %c %c\n%c %c %c\n", a[0][0][0], a[0][1][0], a[0][2][0], a[1][0][0], a[1][1][0], a[1][2][0], a[2][0][0], a[2][1][0], a[2][2][0]);
  if(!k) {
    unsigned Num;
	  if(!i) {
      if(!j) {
        N = (n << 1) + 1;
        if(a[0][0][0] == '1') ++Cnt, Num = Get(0, 0), Fa[Num] = Num;
        if(a[0][1][0] == '1') ++Cnt, Num = Get(0, 1), Fa[Num] = Num;
        if(a[1][0][0] == '1') ++Cnt, Num = Get(1, 0), Fa[Num] = Num;
        if(a[1][1][0] == '1') ++Cnt, Num = Get(1, 1), Fa[Num] = Num;
      }
      if(a[0][2][0] == '1') ++Cnt, Num = Get(0, j + 2), Fa[Num] = Num;
      if(a[1][2][0] == '1') ++Cnt, Num = Get(1, j + 2), Fa[Num] = Num;
    }
    if(!j) {
      if(a[2][0][0] == '1') ++Cnt, Num = Get(i + 2, 0), Fa[Num] = Num;
      if(a[2][1][0] == '1') ++Cnt, Num = Get(i + 2, 1), Fa[Num] = Num;
    }
    if(a[2][2][0] == '1') ++Cnt, Num = Get(i + 2, j + 2), Fa[Num] = Num;
    unsigned A, B;
    if(a[1][1][0] == '1') {
      A = Find(Get(i + 1, j + 1));
      if(a[1][0][0] == '1') Merge(A, Find(Get(i + 1, j)));
      if(a[0][1][0] == '1') Merge(A, Find(Get(i, j + 1)));
      if(a[1][2][0] == '1') Merge(A, Find(Get(i + 1, j + 2)));
      if(a[2][1][0] == '1') Merge(A, Find(Get(i + 2, j + 1)));
    }
    if(a[0][1][0] == '1') {
      A = Find(Get(i, j + 1));
      if(a[0][0][0] == '1') Merge(A, Find(Get(i, j)));
      if(a[0][2][0] == '1') Merge(A, Find(Get(i, j + 2)));
    }
    if(a[1][0][0] == '1') {
      A = Find(Get(i + 1, j));
      if(a[0][0][0] == '1') Merge(A, Find(Get(i, j)));
      if(a[2][0][0] == '1') Merge(A, Find(Get(i + 2, j)));
    }
    if(a[2][1][0] == '1') {
      A = Find(Get(i + 2, j + 1));
      if(a[2][0][0] == '1') Merge(A, Find(Get(i + 2, j)));
      if(a[2][2][0] == '1') Merge(A, Find(Get(i + 2, j + 2)));
    }
    if(a[1][2][0] == '1') {
      A = Find(Get(i + 1, j + 2));
      if(a[0][2][0] == '1') Merge(A, Find(Get(i, j + 2)));
      if(a[2][2][0] == '1') Merge(A, Find(Get(i + 2, j + 2)));
    }
	}
  if(k == n - 1) {
    // printf("Cnt %u\n", Cnt);
    std::string Rt(std::string(100, '0'));
    unsigned Cur(0);
    while (Cnt) Rt[Cur] = '0' + (Cnt & 1), Cnt >>= 1, ++Cur;
    return Rt;
  }
  return a[0][0];
}
