#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
using namespace std;
int n,m,x,y,two[100];
int main(){
	srand(time(0));
	freopen("data.in","w",stdout);
	n=(rand()*rand())%100000+1;
	m=(rand()*rand())%n+1;
	/*two[0]=1;
	for(int i=1;i<=n;i++){
		two[i]=two[i-1]<<1;
	}*/
	cout<<n<<" "<<m<<endl;
	for(int i=1;i<=n;i++){
		cout<<rand()<<endl;
	}
	return 0;
}
