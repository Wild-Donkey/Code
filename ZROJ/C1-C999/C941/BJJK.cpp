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
#include<bits/stdc++.h>
#define il inline
#define mod 998244353
#define inf 0x3fffffff
#define pi pair<int,int>
#define mp(a,b) make_pair(a, b)
#define fi first
#define se second
using namespace std;
typedef long long ll;

const int OutputBufferSize = 10000000;
namespace input {
    #define BUF_SIZE 100000 
    #define OUT_SIZE 100000 
    #define ll long long 
    bool IOerror = 0; 
    inline char nc() {
        static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE; 
        if (p1 == pend) { 
            p1 = buf; pend = buf + fread(buf, 1, BUF_SIZE, stdin); 
            if (pend == p1) { IOerror = 1; return -1; } 
        } 
        return *p1++; 
    } 
    inline bool blank(char ch) {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    } 
    inline void read(char &ch) { 
        ch = nc();
        while (blank(ch)) ch = nc();
    }
    inline void read(int &x) {
        char ch = nc(); x = 0; 
        for (; blank(ch); ch = nc()); 
        if (IOerror) return; 
        for (; ch >= '0' && ch <= '9'; ch = nc()) x = x * 10 + ch - '0';
    } 
    #undef ll 
    #undef OUT_SIZE 
    #undef BUF_SIZE 
}; 

namespace output {
    char buffer[OutputBufferSize];
    char *s = buffer;
    inline void flush() {
        assert(stdout != NULL);
        fwrite(buffer, 1, s - buffer, stdout);
        s = buffer;
        fflush(stdout);
    }
    inline void print(const char ch) {
        if (s - buffer > OutputBufferSize - 2) flush();
        *s++ = ch;
    }
    inline void print(char* str) {
        while (*str != 0) print(char(*str++));
    }
    inline void print(int x) {
        char buf[25] = {0}, *p = buf;
        if (x == 0) print('0');
        while (x) *(++p) = x % 10, x /= 10;
        while (p != buf) print(char(*(p--) + '0'));
    }
}


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
const int maxn = 2010;
int n, m, dis[maxn][maxn];
char bd[maxn][maxn];
queue<pi> q; 
int main(){
//	freopen("B2.in", "r", stdin);
	freopen("B.ans", "w", stdout);
	input::read(n); input::read(m);
//	cout<<n<<" "<<m<<endl;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			input::read(bd[i][j]);
//			cout<<bd[i][j]<<">";
			dis[i][j]=0x3fffffff;
		}
//		cout<<"\n";
	}
//	cout<<"over cin\n";
//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=m;++j) printf("%c ", bd[i][j]);
//		printf("\n"); 
//	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(bd[i][j]=='+'){q.push(make_pair(i, j)); dis[i][j]=0;} 
	while(q.size()){
		int u_x=q.front().fi, u_y=q.front().se; q.pop();
		for(int i=u_x+1;i<=n&&bd[i][u_y]!='#';++i){
			if(dis[i][u_y]>dis[u_x][u_y]+1){
				dis[i][u_y]=dis[u_x][u_y]+1;
				q.push(make_pair(i,u_y));
			}
		}
		for(int i=u_x-1;i>=1&&bd[i][u_y]!='#';--i){
			if(dis[i][u_y]>dis[u_x][u_y]+1){
				dis[i][u_y]=dis[u_x][u_y]+1;
				q.push(make_pair(i,u_y)); 
			}
		}
		for(int j=u_y+1;j<=m&&bd[u_x][j]!='#';++j){
			if(dis[u_x][j]>dis[u_x][u_y]+1){
				dis[u_x][j]=dis[u_x][u_y]+1;
				q.push(make_pair(u_x, j)); 
			}
		}
		for(int j=u_y-1;j>=1&&bd[u_x][j]!='#';--j){
			if(dis[u_x][j]>dis[u_x][u_y]+1){
				dis[u_x][j]=dis[u_x][u_y]+1;
				q.push(make_pair(u_x, j));
			}
		}
	}
//	cout<<"over bfs\n";
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(bd[i][j]=='#'){
				putchar('#');
//				output::print('#');
			}
			else if(dis[i][j]==0x3fffffff){
//				output::print('X');
				putchar('X');
			}
			else 
				printf("%d", dis[i][j]);
				//output::print(dis[i][j]);
			if(j==m) puts("");
			else putchar(' ');
			output::print("\n"[j==m]);
		}
	}
	output::flush();
	return 0;
}

