#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int maxn=100010;
struct zkw{
    int cd;
    int rd;
};
zkw a[maxn];
vector<int> q[maxn];
queue<int> w;
int n,m,s,t,num=0,o;
int now;
bool yh(){
    for(int i=1;i<=n;++i){
        if(a[i].rd==0) w.push(i);
    }
    while(!w.empty ()){
        now=w.front();
        w.pop();
        num++;
        for(int i=0;i<q[now].size();++i){
            a[q[now][i]].rd--;
            if(a[q[now][i]].rd==0) w.push(q[now][i]);
        }
    }
    if(num<n) return true;
    else return false;
}
int main(){
    scanf("%d",&o);
    while(o--){
    	scanf("%d%d",&n,&m);
    	if(m==0){
    	    printf("0");
    	    continue;
        }
        for(int i=1;i<=m;++i){
            scanf("%d%d",&s,&t);
            a[s].cd++;
            a[t].rd++;
            q[s].push_back(t);
        }
        if(yh()) printf("2\n");
        else printf("1\n");
        num=0;
        memset(a,0,sizeof(a));
        memset(q,0,sizeof(q));
        while(!w.empty()){w.pop();}
	}
	return 0;
}
