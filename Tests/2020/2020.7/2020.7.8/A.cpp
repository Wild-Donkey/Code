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
int t, n, a[10005], cnt=0, f[2][10005];
long long ans=1;
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
int main() {
    n = IN();
    for (register int i = 1; i <= n; i++) {
    	cin >> ch;
    	if(ch == 'Y'){
    		a[i] = 1;
		}
		else{
			if(ch == 'C'){
				a[i] = 0;
				cnt++;
			}
			else{
				if(ch == 'H'){
					a[i] = -1;
				} 
			}
		}
    }
    f[!flg][0] = 1;
    for (int i = 1; i <= n; i++) {
    	//printf("%d\n",a[i]); 
    	if(a[i] == 1) {
			f[flg][0] = 0;
		}
		else {
			f[flg][0] = f[!flg][1];
		}
		//printf("%d %d %d\n", i, a[i], f[flg][0]); 
    	for (int j = 1; j <= i; j++){
    		if (a[i] == 1) {
    			f[flg][j] = f[!flg][j - 1];
			}
			if (a[i] == -1) {
				f[flg][j] = f[!flg][j + 1];
			}
			if (a[i] == 0) {
				f[flg][j] = (f[!flg][j - 1] + f[!flg][j + 1]) % 1000000007;
			}
			//printf("%d %d %d %d\n", i, j, a[i], f[flg][j]); 
		}
		/*if((a[i] == 0)) {
			f[flg][i] = f[!flg][i - 1];
		}
		else {
			f[flg][i] = f[];
		}*/
		flg = !flg;
	}
    printf("%d \n", f[!flg][0]);
  return 0;
}

