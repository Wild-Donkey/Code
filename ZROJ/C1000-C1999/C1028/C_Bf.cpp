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
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') rdsg = -1, rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0', rdch = getchar();
  return rdtp * rdsg;
}
unsigned long long Ans(0x3f3f3f3f), Tmp(0);
unsigned n, a[100005], b[100005], Cost[100005];
int Posx[100005], Posy[100005];
char Used[10];
pair<unsigned, unsigned> Q[1000005];
unsigned Hd(0), Tl(0); 
bitset<605> Vis[605];
void DFS(){//5!
//  printf("DFS ");
//  for (unsigned i(1); i <= n; ++i) if(Used[i]) printf("%u ", i);
//  putchar(0x0A); 
//	for(unsigned i(290); i <= 310; ++i) {
//    for (unsigned j(290); j <= 310; ++j) printf("%u ", (unsigned)Vis[i][j]);
//    putchar(0x0A);
//  }
  if(Vis[300][300]) {Ans = min(Ans, Tmp);return;}
	for(unsigned i(1); i <= n; ++i) if((!Used[i]) && (Vis[Posx[i] + 300][Posy[i] + 300])) {
		Used[i] = 1, Tmp += Cost[i];
    bitset<605> VisT[605];
    memcpy(VisT, Vis, sizeof(Vis));
    unsigned TlT(Tl), HdT(0);
//    printf("Hd Tl %u\n", Hd, Tl);
    while (HdT ^ Tl) {
      unsigned Cx(Q[++HdT].first), Cy(Q[HdT].second);
//      if(Cx == Cy || Tl >= 45150) printf("FAQ %u %u %u Tl %u\n", HdT, Cx, Cy, Tl);
      if((Cx >= a[i]) && (Cy >= b[i]) && (!Vis[Cx - a[i]][Cy - b[i]])) Vis[Cx - a[i]][Cy - b[i]] = 1, Q[++Tl] = make_pair(Cx - a[i], Cy - b[i]);
      if((Cx >= a[i]) && (Cy + b[i] <= 600) && (!Vis[Cx - a[i]][Cy + b[i]])) Vis[Cx - a[i]][Cy + b[i]] = 1, Q[++Tl] = make_pair(Cx - a[i], Cy + b[i]);
      if((Cx + a[i] <= 600) && (Cy + b[i] <= 600) && (!Vis[Cx + a[i]][Cy + b[i]])) Vis[Cx + a[i]][Cy + b[i]] = 1, Q[++Tl] = make_pair(Cx + a[i], Cy + b[i]);
      if((Cx + a[i] <= 600) && (Cy >= b[i]) && (!Vis[Cx + a[i]][Cy - b[i]])) Vis[Cx + a[i]][Cy - b[i]] = 1, Q[++Tl] = make_pair(Cx + a[i], Cy - b[i]);
      if((Cx >= b[i]) && (Cy >= a[i]) && (!Vis[Cx - b[i]][Cy - a[i]])) Vis[Cx - b[i]][Cy - a[i]] = 1, Q[++Tl] = make_pair(Cx - b[i], Cy - a[i]);
      if((Cx >= b[i]) && (Cy + a[i] <= 600) && (!Vis[Cx - b[i]][Cy + a[i]])) Vis[Cx - b[i]][Cy + a[i]] = 1, Q[++Tl] = make_pair(Cx - b[i], Cy + a[i]);
      if((Cx + b[i] <= 600) && (Cy + a[i] <= 600) && (!Vis[Cx + b[i]][Cy + a[i]])) Vis[Cx + b[i]][Cy + a[i]] = 1, Q[++Tl] = make_pair(Cx + b[i], Cy + a[i]);
      if((Cx + b[i] <= 600) && (Cy >= a[i]) && (!Vis[Cx + b[i]][Cy - a[i]])) Vis[Cx + b[i]][Cy - a[i]] = 1, Q[++Tl] = make_pair(Cx + b[i], Cy - a[i]);
//      if(Tl >= 45150) printf("Done %u\n", Tl);
    }
    DFS();
		Used[i] = 0, Tmp -= Cost[i];
    memcpy(Vis, VisT, sizeof(Vis)), Tl = TlT;
	}
}
int main(){
  n = RD();
  for(unsigned i(1); i <= n; ++i) Posx[i] = RDsg(), Posy[i] = RDsg(), a[i] = RD(), b[i] = RD(), Cost[i] = RD();
  Tmp = 0, Vis[300 + Posx[1]][300 + Posy[1]] = 1, Q[++Tl] = make_pair(300 + Posx[1], 300 + Posy[1]), DFS();
	if(Ans >= 0x3f3f3f3f) {printf("-1\n"); return 0;}
	printf("%llu\n",Ans);
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
