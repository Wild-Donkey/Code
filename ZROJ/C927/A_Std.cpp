#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
int n,m,d[N<<1];
char s[N][N];
bool vis[N][N];
struct data{
	int x,y,z;
}pre[N][N];
queue<data>q;
void print(data p){
	int x=p.x,y=p.y;
	if(!(x==1&&y==1)) print(pre[x][y]);
	putchar(s[x][y]);
} 
signed main(){
  freopen("A.in", "r", stdin);
//  freopen("A_Std.out", "w", stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	memset(d,0x3f,sizeof(d));
	q.push((data){1,1,1}),d[1]=s[1][1];
	while(q.size()){
		data v=q.front();q.pop();
		int x=v.x,y=v.y,z=v.z;
		if((int)s[x][y]>d[z]) continue;
		if(x==n&&y==m) print(v),exit(0);
		if(!vis[x+1][y]&&x<n&&(y==m||s[x+1][y]<=s[x][y+1]))
			vis[x+1][y]=1,pre[x+1][y]=v,q.push((data){x+1,y,z+1}),d[z+1]=min(d[z+1],(int)s[x+1][y]);
		if(!vis[x][y+1]&&y<m&&(x==n||s[x][y+1]<=s[x+1][y]))
			vis[x][y+1]=1,pre[x][y+1]=v,q.push((data){x,y+1,z+1}),d[z+1]=min(d[z+1],(int)s[x][y+1]);
	}
	return 0;
}
