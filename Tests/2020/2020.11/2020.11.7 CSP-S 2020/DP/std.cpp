#include <iostream>
#define maxn 32005
using namespace std;
int n,m;
int v,p,q;
int main_item_w[maxn];
int main_item_c[maxn];
int annex_item_w[maxn][3];
int annex_item_c[maxn][3];
int f[maxn];
int main(){
    cin >> n >> m;
    for (int i=1;i<=m;i++){
        cin >> v >> p >> q;
        if (!q){
            main_item_w[i] = v;
            main_item_c[i] = v * p;
        }
        else{
            annex_item_w[q][0]++;
            annex_item_w[q][annex_item_w[q][0]] = v;
            annex_item_c[q][annex_item_w[q][0]] = v * p;
        }
    }

    for (int i=1;i<=m;i++)
        for (int j=n;main_item_w[i]!=0 && j>=main_item_w[i];j--){
            f[j] = max(f[j],f[j-main_item_w[i]]+main_item_c[i]);

            if (j >= main_item_w[i] + annex_item_w[i][1])
                f[j] = max(f[j],f[ j - main_item_w[i] - annex_item_w[i][1] ] + main_item_c[i] + annex_item_c[i][1]);

            if (j >= main_item_w[i] + annex_item_w[i][2])
                f[j] = max(f[j],f[ j - main_item_w[i] - annex_item_w[i][2] ] + main_item_c[i] + annex_item_c[i][2]);

            if (j >= main_item_w[i] + annex_item_w[i][1] + annex_item_w[i][2])
                f[j] = max(f[j],f[ j - main_item_w[i] - annex_item_w[i][1] - annex_item_w[i][2] ] + main_item_c[i] + annex_item_c[i][1] + annex_item_c[i][2]);

         }
     cout << f[n] << endl;
     return 0;
}
