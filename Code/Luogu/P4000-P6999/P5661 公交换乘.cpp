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
int t, kd, n, hed = 0, tal = 0, ans = 0, cntu = 0, cntb = 0;
bool flg;
char ch;
string s;
struct Car {
	int tim, pri;
}U[100005], B[100005];
inline int IN() {
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
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
	n = IN();
    for (register int i = 1; i <= n; i++) {
    	kd = IN();
    	if (kd) {
			B[++cntb].pri = IN();
			B[cntb].tim = IN();
		}
		else {
			U[++cntu].pri = IN();
			U[cntu].tim = IN();
			ans += U[cntu].pri;
		}
    }
    hed = 1;
    for (int i(1); i <= cntb; ++i) {
    	flg = 0;
		for (int j(hed); j <= cntu; ++j) {
			printf("%d %d\n", i, j); 
			if (B[i].tim <= U[j].tim + 45) {//地铁够晚 
    			if (B[i].tim >= U[j].tim) {//地铁够早 
    				if (B[i].pri > U[j].pri) {//地铁价格不够 
    					continue; 
					}
					else{//使用代金券 
						U[j].pri = 0;
						flg = 1;
						break; 
					}
				}
				else {//地铁晚了
					break;
				}
			}
			else {//地铁早了 
				hed++;
			}
		}
		if(!flg){
			ans += B[i].pri;
		}
		flg = 0;
	}
    printf("%d\n", ans);
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}

