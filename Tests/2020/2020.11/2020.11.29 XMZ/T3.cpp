#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#define rint register int
#define ll long long
#define EdisonBa 0
using namespace std;
inline int RD() {
  int intmp = 0, insign = 1;
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') {
    if (rdch == '-') {
      insign = -1;
    }
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp * insign;
}
int __, _______[200005], _$[200005], __$[200005], _________;
struct ___ {
  int _____, ______;
  const bool operator<(const ___ &________________) const {
    return this->_____ < ________________._____;
  }
} ____[200005], ________[200005];
/*
这个题不就是 p^2 + q^2 > 2pq => (p-q)^2 > 0 => 每一只鸡皆神鸡
*/
//就是最长公共子序列吧？//qs
int main() {
  __ = RD();
  for (register int _(1); _ <= __; ++_) {  //建议改为 : 代码可读性带师
    ____[_]._____ = RD();
    ____[_].______ = _;
  }
  for (register int _(1); _ <= __; ++_) {
    _________ = RD();
  }
  sort(____ + 1, ____ + __ + 1);
  for (register int _(1); _ <= __; ++_) {
    ________[_]._____ = RD();
    ________[_].______ = _;
  }
  sort(________ + 1, ________ + __ + 1);
  for (register int _(1); _ <= __; ++_) {
    _$[____[_].______] = _;  // SBWYH
    __$[________[_].______] = _;
  }
  for (register int _(1); _ <= __; ++_) {
    printf("%d %d\n", _$[_], __$[_]);
  }
  /*这时____[_].______ 和 ________[_].______ 表示p值第_小的鸡的位置
  _$[_] 和 __$[_] 表示离散化后的p值
  */
  memset(_______, 0, sizeof(_______));
  _________ = 0;
  for (register int _(1), __________; _ <= __; ++_) {
    __________ = ____[__$[_]].______;
    if (_________ > __________) {  // 淘汰
      continue;
    }
    _______[__________] = _______[_________] + 1;
    _________ = __________;
    // printf("%d %d\n", _______[__________], __________);
  }
  printf("%d\n", _______[__]);
  system("pause");
  return EdisonBa;
}

/*
那就打T3吧

谁打 << 我们 << 可

我T2不会
*/