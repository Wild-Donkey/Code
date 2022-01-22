#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	for(int T=1;T<=100000;T++){
		system("B_Make.exe");
		system("B.exe");
		double st=clock();
		system("B_Std.exe");
		double ed=clock();
		if(system("fc B.ans B.out")){
			printf("Wrong Answer\n");
			return 0;
		}
		else{
			printf("Accepted , ²âÊÔµã±àºÅ #%d , ÓÃÊ± %.0lfms\n",T,ed-st);
		}
	}
	return 0;
}

