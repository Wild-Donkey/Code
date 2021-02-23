#include<iostream>
using namespace std;
int n,m,a[400],Card[5]={0},f[41][41][41][41]={0};
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>Card[0];
		Card[Card[0]]++; 
	}
	//cout<<Card[1]<<" "<<Card[2]<<" "<<Card[3]<<" "<<Card[4]<<endl;
	for(int i1=0;i1<=Card[1];i1++){
		for(int i2=0;i2<=Card[2];i2++){
			for(int i3=0;i3<=Card[3];i3++){
				for(int i4=0;i4<=Card[4];i4++){
					if(i1){
						f[i1][i2][i3][i4]=max(f[i1][i2][i3][i4],f[i1-1][i2][i3][i4]);
					}
					if(i2){
						f[i1][i2][i3][i4]=max(f[i1][i2][i3][i4],f[i1][i2-1][i3][i4]);
					}
					if(i3){
						f[i1][i2][i3][i4]=max(f[i1][i2][i3][i4],f[i1][i2][i3-1][i4]);
					}
					if(i4){
						f[i1][i2][i3][i4]=max(f[i1][i2][i3][i4],f[i1][i2][i3][i4-1]);
					}
					f[i1][i2][i3][i4]+=a[i1+(i2<<1)+(i3<<1)+i3+(i4<<2)];
					//cout<<i1<<" "<<i2<<" "<<i3<<" "<<i4<<" "<<f[i1][i2][i3][i4]<<endl;
				}
			}
		}
	}
	cout<<f[Card[1]][Card[2]][Card[3]][Card[4]]<<endl;
	return 0;
}
