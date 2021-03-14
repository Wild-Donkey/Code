#include<iostream>
#include<cstring>
using namespace std;
unsigned long long faq;
long long you;
int main(){
	cin>>you;
	if(you<=0){
		cout<<0<<endl;
		return 0;
	}
	faq=you<<1;
	faq--;
	cout<<faq<<endl;
	return 0;
}
