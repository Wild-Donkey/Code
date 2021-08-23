#include<map>
#include<set>
#include<cmath>
#include<ctime>
#include<queue>
#include<stack>
#include<vector>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<functional>
#define mod 998244353
#define inf 0x3fffffff
#define pi pair<int,int>
#define mp(a,b) make_pair(a, b)
#define fi first
#define se second
using namespace std;
typedef long long ll;
int rd(){
	int res = 0, fl = 1;
   char c = getchar();
   while(!isdigit(c)){
       if(c == '-') fl = -1;
       c = getchar();
   }
   while(isdigit(c)){
      res = (res << 3) + (res << 1) + c - '0';
      c = getchar();
   }
   return res * fl;
}

const int maxn = 1000010;
int n, s, a[maxn], Mid;
int main(){
	freopen("B.in", "w", stdout);
	srand(time(NULL));
	n = 201 + rand) % 100;
	s = 90000 + rand()%10000;
	Mid = rand() % n + 1;
	printf("%d %d\n", n, s);
	a[1] = 900 + rand() % 50;
	a[n] = 900 + rand() % 50;
	for (register unsigned i(2); i < Mid; ++i) {
	  a[i] = min(a[i - 1], max(a[i - 1] - 10, 0) + rand() % 11);
  }
	for (register unsigned i(n - 1); i > Mid; --i) {
	  a[i] = min(a[i + 1], max(a[i + 1] - 10, 0) + rand() % 11);
  }
  a[Mid] = rand() % (min(a[Mid + 1], a[Mid - 1]) + 1);
	for(int i=1;i<=n;++i) printf("%d ", a[i]);
	printf("\n");
	return 0;
}


