#include<iostream>
using namespace std;
int n,m,stc[10005],top,fst[10005],cnt,low[10005],Time,dfsx[10005],ans=0;
bool instc[10005]= {0};
struct E {
	int nxt,lai,qu;
} a[50005];
void dfs(int x) {
	instc[x]=1;
	top++;
	stc[top]=x;//入栈
	Time++;
	dfsx[x]=Time;//纪录DFS序
	low[x]=Time;
	for(int i=fst[x]; i; i=a[i].nxt) {
		//cout<<a[i].lai<<" "<<a[i].qu<<endl;
		if(!dfsx[a[i].qu]) { //树枝边
			dfs(a[i].qu);
			low[x]=min(low[x],low[a[i].qu]);
		}
		else { //后向/横叉边
			if(instc[a[i].qu]){
				low[x]=min(low[x],dfsx[a[i].qu]);
			}
		}
		//cout<<x<<endl;
		//cout<<a[i].qu<<" "<<dfsx[a[i].qu]<<" "<<low[x]<<endl; 
	}
	if(low[x]==dfsx[x]){//获得强连通分量 
		int siz=0;
		while(1){
			if(stc[top]==x){
				top--;
				siz++;
				break;
			}
			top--;
			siz++;
		}
		if(siz>1){
			ans++;
		}
		//cout<<siz<<" "<<ans<<endl;
	}
		return;
}
int main() {
	cin>>n>>m;
	for(int i=1; i<=m; i++) {
		int ia,ib;
		cnt++;
		cin>>ia>>ib;
		if(fst[ia]) {
			a[cnt].nxt=fst[ia];
		}
		fst[ia]=cnt;
		a[cnt].lai=ia;
		a[cnt].qu=ib;
		//cout<<fst[ia]<<" "<<ia<<endl;
	}//连边建图
	/*for(int i=1;i<=cnt;i++){
		cout<<a[i].lai<<" "<<a[i].qu<<" "<<a[i].nxt<<endl;
	}*/
	for(int i=1; i<=n; i++) {
		if(!dfsx[i]) {
			dfs(i);
		}
	}
	cout<<ans<<endl;
	return 0;
}
