#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
unsigned n, a[10000005], b[10000005], Bucket[100005], Hd(1), Tl(0), Top(1);
unsigned long long Ans(0), Tmp(0), Q[10000005];
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
int main() {
	n = RD();
	for (register unsigned i(1); i <= n; ++i) ++Bucket[a[i] = RD()];
	for (register unsigned i(1); i <= 100000; ++i) Bucket[i] += Bucket[i - 1];
	for (register unsigned i(1); i <= n; ++i) b[Bucket[a[i]]--] = a[i];
//	for (register unsigned i(1); i <= n; ++i) printf("b[%u] = %u\n", i, b[i]);
  Q[Hd] = 0x3f3f3f3f3f3f3f3f;
	while (Top <= n) {
	  if((Q[Hd] < b[Top]) && (Hd <= Tl)) {
	    Tmp = Q[Hd++];
    } else {
      Tmp = b[Top++];
    }
    if(Top <= n) {
  	  if((Q[Hd] < b[Top]) && (Hd <= Tl)) {
  	    Tmp += Q[Hd++];
      } else {
        Tmp += b[Top++];
      }
    } else {
      Tmp += Q[Hd++];
    }
    Ans += Q[++Tl] = Tmp;
//    printf("Q %u %u %u\n", Tl, Tmp, Top);
//    Q[Tl] = 0x3f3f3f3f3f3f3f3f;
  }
  while (Hd < Tl) {
	  Tmp = Q[Hd++];
	  Tmp += Q[Hd++];
	  Ans += Q[++Tl] = Tmp;
//    printf("Q %u %u\n", Tl, Tmp);
  }
	printf("%llu\n", Ans);
//	printf("%u %llu\n", Hd, Q[Hd]);
	return 0;
}
