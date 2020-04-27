#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int maxn=1e3+9;
const int inf=0x3f3f3f3f;
int dp[maxn][maxn];
int s1[maxn],s2[maxn];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int len1=n;
	int len2=m;
	for(int i=0;i<=len1;i++){
		dp[i][0]=0;
		scanf("%d",&s1[i]);
	}
	for(int i=0;i<=len2;i++){
		dp[0][i]=0;
		scanf("%d",&s1[i]);
	}
	for(int i=1;i<=len1;i++)
		for(int j=1;j<=len2;j++)
			if(s1[i]=s2[j])
				dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	printf("%d\n",dp[len1][len2]);
} 

