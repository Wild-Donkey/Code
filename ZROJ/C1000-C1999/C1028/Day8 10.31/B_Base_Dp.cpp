#include<bits/stdc++.h>
#define Mod 1000000007
using namespace std;
typedef long long ll;
int rd(){
	int res = 0, fl = 1; char c = getchar();
    while(!isdigit(c)){if(c == '-') fl = -1; c = getchar();}
    while(isdigit(c)){res = (res << 3) + (res << 1) + c - '0'; c = getchar();}
    return res * fl;
}
const int maxn = 1000010;
int n, q;
ll f[maxn][10];
int main(){
	f[1][0]=2;
	for(int i(1);i<9;++i) f[1][i]=1;
	for(int i(2);i<=1000000;++i){
		for(int j(0);j<9;++j){
			for(int k(0);k<9;++k){
				f[i][j]+=f[i-1][k]*f[1][(j-k+9)%9];
			}
		}
	}
	n=rd(), q=rd();
	
	return 0;
}

