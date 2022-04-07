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
struct Node{
	int siz;
	long long val,tag;
	Node *ls,*rs;
}N[4000005],*cntn=N;
long long a[2000005],Two=1,ans=0,two[100],n,m;
inline int IN()
{
	char c;int sign=1,res=0;
	while((c=getchar())>'9'||c<'0') if(c=='-') sign=-1;res+=c-'0';
	while((c=getchar())>='0'&&c<='9') res=res*10+c-'0';
	return res*sign;	
}
void PD(Node *now) {
	if(now->ls!=NULL){
    	if(now->tag) {
			now->ls->val+=now->ls->siz*now->tag;
    		now->ls->tag+=now->tag;
			now->rs->val+=now->rs->siz*now->tag;
    		now->rs->tag+=now->tag;
    	}
	}
	now->tag=0;
    return;
}
void Build(Node *now,long long x,long long y)
{
	//printf("Build %lld %lld\n",x,y); 
    if(x==Two) {
        now->val=a[y];
        now->siz=(y<=n);
        now->ls=NULL;
        now->rs=NULL;
		//printf("Build %lld %lld %lld\n",x,y,now->val);
        return;
    }
    now->ls=++cntn;
    now->rs=++cntn;
    Build(now->ls,x+1,y);
    Build(now->rs,x+1,y+(1<<x));
    now->val=now->ls->val+now->rs->val;
    now->siz=now->ls->siz+now->rs->siz;
	//printf("Build %lld %lld %lld\n",x,y,now->val);
    return;
}
void Change(Node *now,long long X,long long x,long long y,long long z)
{
    if(x==X&&y!=0) {
		return;
	}
    PD(now);
    if(x==X) {
		now->val+=now->siz*z;
    	now->tag+=z;
		return;
	}
    if(y&1) {
		Change(now->rs,X,x+1,y>>1,z);
	}
    else {
		Change(now->ls,X,x+1,y>>1,z);
	}
    now->val=now->ls->val+now->rs->val;
}
long long Find(Node *now,long long X,long long x,long long y) {
    //printf("Find %lld %lld %lld %lld %lld\n",x,y,now->val,now->xk,now->yk); 
	if(x==X&&y!=0){
		return 0;
	}
    PD(now);
    if(x==X) {
		return now->val;
	}
    if(y&1) {
    	//printf("Go Right\n"); 
		return Find(now->rs,X,x+1,y>>1);
	}
    else {
    	//printf("Go Left\n"); 
		return Find(now->ls,X,x+1,y>>1);
	}
	return 0;
}
int main() {
    n=IN();
	m=IN();
	two[0]=1;
    //printf("%lld %lld\n",n,m); 
    while(two[Two-1]<n) {
		two[Two]=two[Two-1]<<1;
		Two++;
	}
	Two--;
    for(register int i=1;i<=n;i++) {
		a[i]=IN();
    	//printf("%lld\n",a[i]); 
	}
    Build(cntn,0,1);
    long long Do,A,B,C;
    for(register int i=1;i<=m;i++) {
        Do=(IN()+ans)%2+1;
		A=IN();
		B=IN();
        if(Do==1) {
		    C=IN();
		    //printf("%lld %lld %lld\n",A,B,C); 
            if(B!=0){
				Change(N,min(Two,A),0,B-1,C);
			}
            else {
				Change(N,min(Two,A),0,(1<<(min(Two,A)))-1,C);
			}
        }
        else {
		    //printf("%lld %lld\n",A,B); 
			if(B!=0) {
				ans=Find(N,min(Two,A),0,B-1);
			}
        	else {
				ans=Find(N,min(Two,A),0,(1<<(min(Two,A)))-1);
			}
			printf("%lld\n",ans);
    	}
    }
    return 0;
}
