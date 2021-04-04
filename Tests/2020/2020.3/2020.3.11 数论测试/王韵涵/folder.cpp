#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("folder.in", "r", stdin);
	freopen("folder.out", "w", stdout);
	int bei, jia, sheng;
	int i=1;
	cin >> bei >> jia >> sheng;
	while ((jia*i+sheng)%bei)
	{
		i++;
		if (i==90000000)
		{
			cout << "NO" << endl << 0;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
	}
	int beishu;
	beishu = (jia * i + sheng) / bei;
	cout << "YE5" << endl << beishu;
	fclose(stdin);
	fclose(stdout);
	return 0;

}