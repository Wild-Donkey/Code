#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int rd(){
	int res = 0, fl = 1; char c = getchar();
    while(!isdigit(c)){if(c == '-') fl = -1; c = getchar();}
    while(isdigit(c)){res = (res << 3) + (res << 1) + c - '0'; c = getchar();}
    return res * fl;
}
const int maxn = 1000010;
int n, a[310], b[310], c[310], m, p, x;
int hefa[10][20][20], cnt[10];
bool vis[10];
void Cal(){//n^3
	for(int i(1);i<=n;++i) b[i]=a[i];
	int sam(0), sam0;
	for(int i(1);i<=cnt[n];++i){
		sam0=0;
		memset(vis,0,sizeof(vis));
		for(int j(1);j<=n;++j){
			for(int k(1);k<=n;++k){
				if(!vis[k]&&hefa[n][i][j]==b[k]){
					vis[k]=1;
					sam0++;
					break;
				}
			}
		}
		sam=max(sam,sam0);
	}
	printf("%d\n",n-sam);
	return ;
}
int main(){
	n=rd(), m=rd();
	for(int i(1);i<=n;++i) a[i]=rd();
	cnt[0]=1;
	hefa[1][++cnt[1]][1]=1;
	for(int i(2);i<=5;++i){
		for(int j(1);j<=i;++j){
			for(int k(1);k<=cnt[i-j];++k){
				++cnt[i];
				for(int p(1);p<=j;++p){
					hefa[i][cnt[i]][p]=i;
				}
				for(int p(1);p<=i-j;++p){
					hefa[i][cnt[i]][j+p]=hefa[i-j][k][p];
				}
			}
		}
	}
//	for(int i(1);i<=5;++i){
//		printf("cnt[%d]=%d\n", i, cnt[i]);
//		for(int j(1);j<=cnt[i];++j){
//			for(int k(1);k<=i;++k) printf("%d ",hefa[i][j][k]);
//			printf("\n");
//		}
//	}
	for(int i(1);i<=m;++i){
		p=rd(); x=rd();
		if(p>=1&&p<=n){
			a[p]=x;
		}
		else{
			for(int j(1);j<=n;++j) a[j]+=x;
		}
//		printf("Now: ");
//		for(int j(1);j<=n;++j) printf("%d ", a[j]);
//		printf("\n");
		Cal();
	}
	return 0;
}

/*
1 2 3
1 1
1 2 3  0
0 1
2 3 4  1 (2 3 1)
0 1
3 4 5  2 (3 2 1)
0 1
4 5 6  3 (3 2 1)
2 2
4 2 6  2 (3 2 2)
3 2
4 2 2  1 (3 2 2)
0 -1
3 1 1  1 (3 2 1)
0 -1
2 0 0  2 (2 3 1)
0 -1
1 -1 -1 2 (1 2 3)
*/

//n=1  1
//1
//
//n=2   2
//2 1
//2 2
//
//n=3   4
//3(n=2)
//3 3(n=1)
//
//n=4    8
//4(n=3)
//4 4(n=2)
//4 4 4(n=1)
//
//n=5    16
//5 (n=4)
//5 5 (n=3)
//5 5 5 (n=2)
//5 5 5 5 (n=1)

