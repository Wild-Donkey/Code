#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,gx,gy,two[100],cnt=0;
void f(int x,int y,int k,int a,int b){
	//cout<<x<<" "<<y<<" "<<a<<" "<<b<<" "<<k<<endl;
	/*cnt++;
	if(!(cnt%50)){
	//	cout<<endl;
	}
	if(cnt>=1000){
		return;
	}*/
	if(k<=1){//只剩2*2的格子 
		if(x==a){//上半部分 
			if(y==b){//左上 
				printf("%d %d %d\n",a+1,b+1,1);
			} 
			else{//右上 
				printf("%d %d %d\n",a+1,b,2);
			}
		}
		else{//下半部分 
			if(y==b){//左下 
				printf("%d %d %d\n",a,b+1,3);
			}
			else{//右下 
				printf("%d %d %d\n",a,b,4);
			}
		}
		return;
	}
	if(x<=a+two[k-1]-1){//上半部分 
		if(y<=b+two[k-1]-1){//左上 
			printf("%d %d %d\n",a+two[k-1],b+two[k-1],1);
			f(x,y,k-1,a,b);//左上子 
			f(a+two[k-1]-1,b+two[k-1],k-1,a,b+two[k-1]);//右上子 
			f(a+two[k-1],b+two[k-1]-1,k-1,a+two[k-1],b);//左下子 
			f(a+two[k-1],b+two[k-1],k-1,a+two[k-1],b+two[k-1]);//右下子 
		}
		else{//右上 
			printf("%d %d %d\n",a+two[k-1],b+two[k-1]-1,2);
			f(a+two[k-1]-1,b+two[k-1]-1,k-1,a,b);//左上子 
			f(x,y,k-1,a,b+two[k-1]);//右上子 
			f(a+two[k-1],b+two[k-1]-1,k-1,a+two[k-1],b);//左下子 
			f(a+two[k-1],b+two[k-1],k-1,a+two[k-1],b+two[k-1]);//右下子 
		} 
	}
	else{//下半部分 
		if(y<=b+two[k-1]-1){//左下 
			printf("%d %d %d\n",a+two[k-1]-1,b+two[k-1],3);
			f(a+two[k-1]-1,b+two[k-1]-1,k-1,a,b);//左上子 
			f(a+two[k-1]-1,b+two[k-1],k-1,a,b+two[k-1]);//右上子 
			f(x,y,k-1,a+two[k-1],b);//左下子 
			f(a+two[k-1],b+two[k-1],k-1,a+two[k-1],b+two[k-1]);//右下子 
		}
		else{//右下 
			printf("%d %d %d\n",a+two[k-1]-1,b+two[k-1]-1,4);
			f(a+two[k-1]-1,b+two[k-1]-1,k-1,a,b);//左上子 
			f(a+two[k-1]-1,b+two[k-1],k-1,a,b+two[k-1]);//右上子 
			f(a+two[k-1],b+two[k-1]-1,k-1,a+two[k-1],b);//左下子 
			f(x,y,k-1,a+two[k-1],b+two[k-1]);//右下子 
		}
	}
	return;
}
int main(){
	//freopen("data.in","r",stdin);
	//freopen("me.out","w",stdout);
	cin>>n>>gx>>gy;
	two[0]=1;
	for(int i=1;i<=n;i++){
		two[i]=two[i-1]<<1;
		//cout<<two[i]<<endl;
	}
	f(gx,gy,n,1,1);
	return 0;
}
