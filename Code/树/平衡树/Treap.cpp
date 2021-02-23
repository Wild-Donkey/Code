#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<cstdio>
#include<cmath>
#include<queue>
#include<map> 
using namespace std;
struct ND{
	int l;
	int r;
	int fa;
	int val;
	int rval;
	int siz;
	int ct;
}a[100005];
int n;
int k;
int Do;
int cnt=0;
void tl(int x){//右儿当爹 
	int son=a[x].r;
	a[x].r=a[son].l;
	a[son].l=x;
	a[son].fa=a[x].fa;
	a[x].fa=son;
	a[son].siz=a[x].siz;
	a[x].siz=a[a[x].l].siz+a[a[x].r].siz+a[x].ct; 
	return;
}
void tr(int x){//左儿当爹 
	int son=a[x].l;
	a[x].l=a[son].r;
	a[son].r=x;
	a[son].fa=a[x].fa;
	a[x].fa=son;
	a[son].siz=a[x].siz;
	a[x].siz=a[a[x].l].siz+a[a[x].r].siz+a[x].ct; 
	return;
}
int root(){
	int x=1;
	while(a[x].fa>0){
		x=a[x].fa;
	}
	return x;
}
void udt(int x){
	int now=x;
	while(a[x].fa>0){
		a[x].siz=a[a[x].l].siz+a[a[x].r].siz+a[x].ct; 
	}
	return 0;
}
int in(int v){
	int now=root();
	while(now>0){
		if(v==a[now].siz){//重复元素 
			a[now].ct++;
			a[now].siz++;
			udt(now);
			return now;
		}
		if(v<a[now].siz){//左子树 
			if(a[now].l){
				now=a[now].l;
			}
			else{
				cnt++;
				a[now].l=cnt;
				a[cnt].fa=now;
				a[cnt].siz=1;
				a[cnt].ct=1;
				a[cnt].val=v;
				a[cnt].rval=rand()*rand();
				now=cnt;
				udt(now);
				break;
			}
		}
		else{//右子树 
			if(a[now].r){
				now=a[now].r;
			}
			else{
				cnt++;
				a[now].r=cnt;
				a[cnt].fa=now;
				a[cnt].siz=1;
				a[cnt].ct=1;
				a[cnt].val=v;
				a[cnt].rval=rand()*rand();
				now=cnt;
				udt(now);
				break;
			}
		}
	}
	while(a[now].rval<a[a[now].fa].rval){//保证小根堆 
		if(now==a[a[now].fa].l){
			tr(a[now].fa);
		}
		else{
			tl(a[now].fa);
		}
	}
	return now;
}
void del(int v){
	int now=root();
	while(now>0){
		if(a[now].val==v){//删它 
			if(a[now].ct>1){
				a[now].ct--;
				a[now].siz--;
				udt(now);
				return
			}
			else{
				while((a[now].l>0)&&(a[now].r>0)){//非链点 
					if(a[a[now].l].rval>a[a[now].r].rval){//右子当爹 
						tl(now); 
					}
					else{
						tr(now);
					}
				}
				if((a[now].l<=0)||(a[now].r<=0)){//叶 
					if(now==a[a[now].fa].l){//是左儿 
						a[a[now].fa].l=0;
					}
					else{//右儿 
						a[a[now].fa].r=0;
					}
					udt(a[now].fa);
				}
				else{
					int son=max(a[now].l,a[now].r);//独子 
					if(now==a[a[now].fa].l){//是左儿 
						a[a[now].fa].l=son;
						a[son].fa=a[now].fa;
					}
					else{//右儿 
						a[a[now].fa].r=son;
						a[son].fa=a[now].fa;
					}
					udt(a[now].fa);
				}
			}
		}
		if(a[now].val<v){
			now=a[now].l;
		}
		else{
			now=a[now].r;
		}
	}
	return;
}
int findx(int x){
	int now=root(),le=x+1;//考虑开始的-INF 
	while(now>0){
		if(le<=a[a[now].l].siz){//左子树 
			now=a[now].l;
		}
		if(le>a[a[now].l].siz){//不在左子树 
			if(le<=a[a[now].l]+a[now].ct){//就是当前节点 
				return a[now].val;
			}
			else{//右子树 
				le-=a[now].ct;
				le-=a[a[now].l].siz;
				now=a[now].r; 
			}
		}
	}
	return -1;
}
int findv(int v){
	int now=root();
	int rk=0;//考虑-INF 
	while(now>0){
		if(v==a[now].val){//找到 
			rk+=a[a[now].l].siz;
			return rk;
		}
		if(v>a[now].val){//右子树 
			rk+=a[now].ct;
			rk+=a[a[now].l].siz;
			now=a[now].r; 
		}
		else{//左子树 
			now=a[now].l; 
		}
	}
	return rk;
}
int bf(int v){//前驱 
	int now=root(),Min=1/*-INF*/;
	while(now>0){
		if(a[now].val==v){//找到了 
			if(a[now].l>0){//有左子树 
				now=a[now].l;
				while(a[now].r>0){//左子树最大值 
					now=a[now].r;
				}
				return now;
			}
			else{
				if(now==a[a[now].fa].r){//是右儿 
					return a[now].fa; 
				} 
			}
		}
	}
	return -1;
}
int af(int v){//后继 
	return -1;
}
int main(){
	cin>>n;
	in(-0x3f3f3f3f);
	in(0x3f3f3f3f);
	srand(n);
	for(int i=1;i<=n;i++){
		cin>>Do>>k;
		if(Do==1){
			in(k);
		}
		if(Do==2){
			del(k);
		}
		if(Do==3){
			cout<<findv(k)<<endl;
		}
		if(Do==4){
			cout<<findx(k)<<endl;
		}
		if(Do==5){
			cout<<bf(k)<<endl;
		}
		if(Do==6){
			cout<<af(k)<<endl;
		}
	}
	return 0;
}
