#include<cstring>
#include<iostream>
using namespace std;
int n;
char s[1005];
void print(){
	for(int i=1;i<=(n<<1)+2;i++){
		cout<<s[i];
	}
	cout<<endl;
	return;
}
void f(int x){
	if(x<=4){
		cout<<"ooo--***o*";
		for(int i=1;i<=n-4;i++){
			cout<<"o*";
		}
		cout<<endl;
		cout<<"ooo*o**--*";
		for(int i=1;i<=n-4;i++){
			cout<<"o*";
		}
		cout<<endl;
		cout<<"o--*o**oo*";
		for(int i=1;i<=n-4;i++){
			cout<<"o*";
		}
		cout<<endl;
		cout<<"o*o*o*--o*";
		for(int i=1;i<=n-4;i++){
			cout<<"o*";
		}
		cout<<endl;
		cout<<"--o*o*o*o*";
		for(int i=1;i<=n-4;i++){
			cout<<"o*";
		}
		cout<<endl;
		return;
	}
	s[(x<<1)+1]=s[x];
	s[(x<<1)+2]=s[x+1];
	s[x]='-';
	s[x+1]='-';
	print();
	s[x+1]=s[x<<1];
	s[x]=s[(x<<1)-1];
	s[x<<1]='-';
	s[(x<<1)-1]='-';
	print();
	return f(x-1);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		s[i]='o';
		s[i+n]='*';
	}
	s[(n<<1)+1]='-';
	s[(n<<1)+2]='-';
	print();
	f(n);
	return 0;
} 
