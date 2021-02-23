#include<windows.h>
#include<iostream>
#include<ctime> 
using namespace std;
int n,ti1,ti2;
int main(){
	while(1){
		system("rand.exe");
		ti1=clock();
		system("Expense.exe");
		ti2=clock();
		system("std.exe");
		if(system("fc Expense.out thestd.out")){
			cout << "Fuck U" << endl;
			break; 
		}
		else{
			cout<<++n<<"AC"<<endl;
			cout<<"time "<<ti2-ti1<<"ms"<<endl;
		}
	}
	return 0;
}
