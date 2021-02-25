#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,two[50];
void f(int x){
	if(x==1){
		printf("2(0)");
		return;
	}
	if(x==2){
		printf("2");
		return;
	}
	int i=15;
	bool flg=0;
	while((x>=0)&&(i>2)){
		i--;
		if(x>=two[i]){
			if(flg){
				printf("+");
			}
			printf("2(");
			f(i);
			printf(")");
			x-=two[i];
			flg=1;
		}
	}
	if(x>=2){
		if(flg){
			printf("+");
		}
		f(2);
		x-=2;
		flg=1;
	}
	if(x){
		if(flg){
			printf("+");
		}
		f(1);
	}
	return;
}
int main(){
	two[0]=1;
	for(int i=1;i<=20;i++){
		two[i]=2*two[i-1];
	}
	cin>>n;
	f(n);
	return 0;
}
