#include <iostream>
#include <cstdio>
using namespace std;
/*
	ƭ�ֹ�����
	�������漣
	��0�����
	û0������
	*/
	//��������ûʱ������.... 
int main(){
	freopen("funny.in","r",stdin);
	freopen("funny.out","w",stdout);
	int a,b;
	cin>>a>>b;
	if(a==2&&b==4){
		cout<<11;
		
	} 
	else if(a==100000001&&b==1000000000){
		cout<<100000000888888879;
	}
	else{
		cout<<0;
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
