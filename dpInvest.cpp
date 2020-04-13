#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int maxn=1e3+9;
const int inf=0x3f3f3f3f;
int f[maxn][maxn],v[maxn][maxn],x[maxn][maxn];
int n,m;
int main(){
    cin>>n>>m;
    for(int i=0;i<=m;i++)
		for(int j=1;j<=n;j++)
			cin>>v[j][i];
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m;j++)
			for(int k=0;k<=j;k++)
				if(f[i-1][j-k]+v[i][k]>f[i][j]){
					f[i][j]=f[i-1][j-k]+v[i][k];
					x[i][j]=k;
				}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			printf("%d %d%c",f[j][i],x[j][i],j==n?'\n':' ');
	printf("%d\n",f[n][m]);
    return 0;
}

