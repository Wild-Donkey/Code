#include<bits/stdc++.h>

using namespace std;

int LENGTH;
int Vstep;
int Vcar;
double S;
double TIME;

int main()
{
	freopen("escape.in","r",stdin);
	freopen("escape.out","w",stdout);
	cin>>LENGTH>>Vstep>>Vcar;
	S=LENGTH*(Vcar*Vcar-Vstep*Vstep)/(2*Vstep*Vcar-3*Vstep*Vstep+Vcar*Vcar);
	TIME=S/Vcar+(LENGTH-S)/Vstep;
	printf("%.2f\n",TIME);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
