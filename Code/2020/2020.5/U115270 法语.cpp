#include<iostream>
#include<cstring>
using namespace std;
char ch;
int l, n;
bool Big=0;
string w;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		Big=0;
		cin>>w>>ch;
		l=w.length();
		if(w[0]<='Z'){
			Big=1;
			w[0]+='a'-'A';
		}
		if((w[l-1]=='x')||(w[l-1]=='s')){
			if(Big){
				cout<<"Les "<<w<<endl;
			}
			else{
				cout<<"les "<<w<<endl;
			}
			continue;
		}
		if((w[0]=='a')||(w[0]=='e')||(w[0]=='i')||(w[0]=='o')||(w[0]=='u')||(w[0]=='y')||(w[0]=='h')){
			if(Big){
				cout<<"L'"<<w<<endl;
			}
			else{
				cout<<"l'"<<w<<endl;
			}
			continue;
		}
		if(ch=='f'){
			if(Big){
				cout<<"La "<<w<<endl;
			}
			else{
				cout<<"la "<<w<<endl;
			}
		}
		else{
			if(Big){
				cout<<"Le "<<w<<endl;
			}
			else{
				cout<<"le "<<w<<endl;
			}
		}
	}
	return 0;
}
