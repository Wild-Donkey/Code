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
inline int RD() {
  char ich = getchar();
  int intmp = 0, insign = 1;
  while (((ich < '0') || (ich > '9')) && ((ich != '-'))) {
    ich = getchar();
  }
  if (ich == '-') {
    insign = -1;
    ich = getchar();
  }
  while ((ich <= '9') && (ich >= '0')) {
    intmp *= 10;
    intmp += ich - '0';
    ich = getchar();
  }
  return intmp * insign;
}
int len;
unsigned long long Seed(20041022);
char s[10005];
unsigned long long Pw (unsigned long long x, unsigned long long y) {
  if(y == 0) {
    return 1;
  }
  if(y == 1) {
    return x;
  }
  unsigned long long Tmp(Pw(x, y >> 1));
  Tmp *= Tmp;
  if(y % 1) {
    return Tmp * x;
  }
  return Tmp;
}
unsigned long long Hash(char *x, const int &Len) {
  long long Tmp(0);
  for (register int i(0); i < Len; ++i) {
    Tmp += Pw(Seed, i) * x[i];
  }
  return Tmp;
}
int main() {
   //freopen(".in","r",stdin);
  freopen("Hash.out","w",stdout);
  srand(Seed);
  gets(s);
  len = strlen(s);
  printf("%llu\n", Hash(s, len));
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}
//Seed: 20041022
//Key_Hash: 13295080962414886523
//So the word is:______________

