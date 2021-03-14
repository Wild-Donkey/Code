#include<iostream> 
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
//#include<minmax.h>
using namespace std;
const int Maxn = 100001;
int l, ans[26], ma, h, k;
string s, a[4];
int main()
{
	for (int j = 0; j <= 3; j++)
		getline(cin, a[j]);
	s = a[0] + a[1] + a[2] + a[3];
	l = s.length();
	for (int j = 0; j < l; j++)
		if ((s[j] <= 'Z') && (s[j] >= 'A'))
			ans[s[j] - 'A']++;
	for (int i = 0; i <= 24; i++)
		ma = max(ma, ans[i]);
	for (int i = ma; i >= 1; i--)
	{
		k = -1;
		for (int j = 0; j <= 25; j++)
			if (ans[j] >= i)
			{
				if (j == 0)
				{
					k = 0;
					cout << "*";
				}
				else
				{
					if (k < 0)
						for (int ij = 1; ij <= 2 * (j - k) - 2; ij++)
							cout << " ";
					else
						for (int ij = 1; ij <= 2 * (j - k) - 1; ij++)
							cout << " ";
					cout << "*";
					k = j;
				}
			}
		cout << endl;
	}
	cout << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
	return 0;
}