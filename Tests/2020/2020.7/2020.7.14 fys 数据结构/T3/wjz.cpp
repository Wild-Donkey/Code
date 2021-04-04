#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long int ll;
const int maxn=1000005;
int n,tot,m;
int heap[maxn],a[maxn];
inline void up(int p){
	while(p>1){
		if(heap[p]>heap[p/2]){
			swap(heap[p],heap[p/2]);
			p/=2;
		}else{
			break;
		} 
	}
}
inline void insert(int val){
	heap[++tot]=val;
	up(tot);
}
inline ll gettop(){
	return heap[1];
}
inline void down(int p){
	int s=p*2;
	while(s<=tot){
		if(s<n&&heap[s]<heap[s+1])s++;
		if(heap[s]>heap[p]){
			swap(heap[s],heap[p]);
			p=s,s=p*2;
		}
		else{
			break;
		}
	}
}
void Extract(){
	heap[1]=heap[tot--];
	down(1);
}
inline void remove(int k){
	heap[k]=heap[tot--];
	up(k);down(k);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		insert(a[i]);
	}
	scanf("%d",&m);
	while(m--){
		int d,p;
		scanf("%d",&d);
		if(d==0){
			printf("%d\n",gettop());
		}if(d==1){
			scanf("%d",&p);
			insert(p);
		}if(d==2){
			scanf("%d",&p);
			remove(a[p]);
		}
	}
}
