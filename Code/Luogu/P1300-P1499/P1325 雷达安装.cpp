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
int n, ans = 0;
double tmp, Bgs = 1e19, Sms, inx, iny, d, now;
bool flg = 0;
char ch;
string s;
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
struct Range{
	double l, r;
}R[20005];
bool cmp(Range x, Range y) {
	return x.r < y.r;
}
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
    n = IN();
    scanf("%lf", &d);
    d *= d;
    for (register int i = 1; i <= n; i++) {
    	scanf("%lf%lf", &inx, &iny);
    	iny *= iny;
    	if(d < iny){
    		printf("-1\n");
    		return 0;
		}
    	tmp = sqrt(d - iny);
    	R[i].l = inx - tmp;
    	R[i].r = inx + tmp;
    	//printf("%lf %lf\n", R[i].l, R[i].r);
    }
    sort(R + 1, R + n + 1, cmp);
    //R[n+1].r = 1e19;
    //Bgs = R[1].r;
    now = -1e19;
    for(int i = 1; i <= n; i++) {
    	if(R[i].l <= now){
    		continue;
		}
		else{
			ans++;
			now=R[i].r;
		}
    	/*//printf("%lf %lf\n", R[i].l, R[i].r);
    	//Bgs = min(R[i].r, Bgs);//右端最小值 
    	Sms = max(R[i].l, Sms);//左端最大值 
    	flg = 1;
    	if(Sms > Bgs){
    		ans++;
    		//printf("%lf %lf %d\n", Bgs, Sms, ans);
    		Bgs = R[i+1].r; 
    		flg = 0;
		}*/
	}
	/*if(flg){
		//printf("%lf %lf", Sms, Bgs);
		ans++;
	}*/
	printf("%d", ans);
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}

