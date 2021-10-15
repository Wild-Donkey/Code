// Author: Lech Duraj

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int infty = 1000000000;
const int maxn = 300;
int A[maxn],B[maxn],H[maxn];
int sol[2*maxn+2][2*maxn+2];

int main()
{
    int TT;
    scanf("%d",&TT);
    while(TT--)
    {
        int n;
        scanf("%d",&n);
        vector<int> ends;
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d%d",&A[i],&B[i],&H[i]);
            ends.push_back(A[i]);
            ends.push_back(B[i]);
        }
        ends.push_back(-infty);                                // ends is the array of all endpoints
        ends.push_back(+infty);
        sort(ends.begin(),ends.end());
        ends.erase(unique(ends.begin(),ends.end()),ends.end());
        int k = ends.size();
        for(int d = 1; d < k; d++)
            for(int i = 0; i + d < k; i++)
            {
                int j = i+d;                                   // computing sol[i][j] - the solution for all buildings with endpoints between i and j
                int highest = -1;
                for(int q = 0; q < n; q++)
                    if ((A[q] > ends[i]) && (B[q] < ends[j]) && (highest == -1 || H[q] > H[highest]))
                        highest = q;
                if (highest == -1)
                    sol[i][j] = 0;
                else
                {
                    sol[i][j] = infty;                          // find left and right endpoint of the highest building
                    int hleft = 0;
                    while (ends[hleft] != A[highest])           // 'cause binary search is for kids
                        hleft++;
                    int hright = 0;
                    while (ends[hright] != B[highest])          // real men use linear search!
                        hright++;                               // (while maintaining complexity)
                    for(int q = hleft; q <= hright; q++)        // now, we put a rod somewhere between the highest building endpoints
                        sol[i][j] = min(sol[i][j], H[highest] + sol[i][q] + sol[q][j]);         // and split into two parts
                }
            }
        printf("%d\n",sol[0][k-1]);
    }
}
