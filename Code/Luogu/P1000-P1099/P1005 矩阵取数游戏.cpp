#include<iostream>
#include<cstring>
using namespace std;
int n,m,tmp,a[105][105],ans[55],A[55],B[55],two[105][55],f[105][105][55],Max[105][55];
void Plus(int x[],int y[]){
	memset(ans,0,sizeof(ans));
	ans[0]=max(x[0],y[0])+1;
	for(int i=1;i<=ans[0];i++){
		ans[i]+=x[i]+y[i];
		ans[i+1]+=ans[i]/10;
		ans[i]%=10;
	}
	while((ans[ans[0]]==0)&&(ans[0]>1)){
		ans[0]--;
	}
	return;
}
void tms(int x[],int y){
	memset(ans,0,sizeof(ans));
	ans[0]=x[0]+10;
	for(int i=1;i<=ans[0];i++){
		ans[i]+=x[i]*y;
		ans[i+1]+=ans[i]/10;
		ans[i]%=10; 
	}
	while((ans[ans[0]]==0)&&(ans[0]>1)){
		ans[0]--;
	}
	return;
}
void change(int x){
	memset(ans,0,sizeof(ans));
	ans[0]=10;
	int i=1;
	while(x){
		ans[i++]=x%10;
		x/=10;
	}
	while((ans[ans[0]]==0)&&(ans[0]>1)){
		ans[0]--;
	}
	return;
}
void move(int x[],int y[]){
	for(int i=x[0];i>=0;i--){
		y[i]=x[i];
	}
	return;
}
void print(int x[]){
	for(int i=x[0];i>=1;i--){
		cout<<x[i];
	}
	cout<<endl; 
	return;
}
bool cmp(int x[],int y[]){
	if(x[0]<y[0]){
		return 0;
	}
	if(x[0]>y[0]){
		return 1;
	}
	for(int i=x[0];i>=1;i--){
		if(x[i]<y[i]){
			return 0;
		}
		if(x[i]>y[i]){
			return 1;
		}
	}
	return 0; 
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	two[0][0]=1;
	two[0][1]=1;
	for(int i=1;i<=m;i++){
		tms(two[i-1],2);
		move(ans,two[i]);
		//print(two[i]);
	}
	for(int i=1;i<=n;i++){//枚举行数 
		memset(f,0,sizeof(f));
		change(0);
		move(ans,f[m][1]);
		for(int j=m-1;j>=0;j--){//枚举剩余区间长度 
			for(int k=1;k<=m-j+1;k++){//枚举剩余区间起点 
				memset(A,0,sizeof(A));
				memset(B,0,sizeof(B));
				if(k>=2) 
				{
					tms(two[m-j],a[i][k-1]);//取左端 
					move(ans,A);//本次取数 
					Plus(A,f[j+1][k-1]);//加上之前的 
					move(ans,A);
				}
				if(k+j<=m){
					tms(two[m-j],a[i][k+j]);//取右端 
					move(ans,B);
					Plus(B,f[j+1][k]);
					move(ans,B);
				}
				if(cmp(A,B)){//A>B
					move(A,f[j][k]);//第i行，剩j个，剩下的第一个为k的最大值 
				}
				else{
					move(B,f[j][k]);
				}
			} 
		}
		for(int j=1;j<=m;j++){
			if(cmp(f[0][j],Max[i])){
				move(f[0][j],Max[i]);
			}
		}
		Plus(Max[0],Max[i]);
		move(ans,Max[0]);
	}
	print(Max[0]);
	return 0;
} 
