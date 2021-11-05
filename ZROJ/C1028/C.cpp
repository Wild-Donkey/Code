#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <bitset>
#include <unordered_map>
#include <vector>
#define Wild_Donkey 0
#define Inf 0x3f3f3f3f3f3f3f3f
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') rdsg = -1, rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0', rdch = getchar();
  return rdtp * rdsg;
}
unsigned long long Ans(Inf);
unsigned A, B, C;
unsigned n, a[1005], Cost[1005];
int Posx[1005], Posy[1005], Sx, Sy;
unordered_map<unsigned, unsigned long long> f;
unordered_map<unsigned, char> Vis;
inline char Judge (unsigned x, int Desx, int Desy) {
//  printf("Judge %u -> %u %u\n", x, Desx, Desy);
  unsigned Gc(x >> 1);
  if(!Gc) return ((Desx == Sx) && (Desy == Sy));
  if(Desx >= Sx) Desx -= Sx; else Desx = Sx - Desx;
  if(Desy >= Sy) Desy -= Sy; else Desy = Sy - Desy;
  if(Desx % Gc) return 0;
  if(Desy % Gc) return 0;
  Desx /= Gc, Desy /= Gc;
  if((Desx + Desy) & 1) return (x & 1);
  return 1;
}
inline unsigned Gcd (unsigned x, unsigned y) {
  unsigned TmpG;
//  printf("GCD %u %u\n", x, y);
  while (y) TmpG = x, x = y, y = TmpG % y; 
  return x;
}
void Dij(){//5!
  priority_queue <pair<unsigned long long, unsigned> > Q;
  Q.push(make_pair(Inf, 0)); 
  while (Q.size()) {
    unsigned Cur(Q.top().second);
//    printf("Dij %u %u\n", Cur >> 1, Cur & 1);
    Q.pop();
    if(Vis[Cur]) continue;
    Vis[Cur] = 1;
    if(Judge(Cur, 0, 0)) {Ans = min(Ans, f[Cur]); continue;}
    for (unsigned i(1); i <= n; ++i) if(Judge(Cur, Posx[i], Posy[i])) {
      unsigned New(Gcd(a[i] >> 1, Cur >> 1)), Gx((Cur >> 1) / New), Gy((a[i] >> 1) / New);
      New <<= 1;
      New |= (Cur * Gx) & 1;
      New |= (a[i] * Gy) & 1;
//      printf("%u + %u -> %u\n", Cur, a[i], New);
      if(f.find(New) == f.end()) {
        f[New] = f[Cur] + Cost[i];
        Q.push(make_pair(Inf - f[New], New));
        continue;
      }
      if(f[New] > f[Cur] + Cost[i]) {
        f[New] = f[Cur] + Cost[i];
        Q.push(make_pair(Inf - f[New], New));
      }
    }
  }
}
int main(){
  n = RD();
  for(unsigned i(1); i <= n; ++i) {
    Posx[i] = RDsg(), Posy[i] = RDsg(), A = RD(), B = RD(), Cost[i] = RD();
    a[i] = ((C = Gcd(A, B)) << 1) + (((A + B) / C) & 1);
//    printf("A%u = %u\n", i, a[i]);
  }
  Sx = Posx[1], Sy = Posy[1], f[0] = 0;
  Dij();
	if(Ans >= Inf) {printf("-1\n"); return 0;}
	printf("%llu\n", Ans);
	return 0;
}
/*
5 
101 101 10 10 1
6 6 2 3 3
51 21 1 1 100000
51 21 5 5 2
7 7 7 7 1
4
3 3 2 2 4
3 3 1 2 5
3 3 2 4 2
5 3 1 2 1
3
3 4 2 2 3
5 8 1 2 1
5 10 3 5 3
*/
