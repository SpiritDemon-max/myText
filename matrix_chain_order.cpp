#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int maxn=1e3+9;
const int inf=0x3f3f3f3f;
int dp[maxn][maxn],p[maxn],s[maxn][maxn];

void print(int i,int j){
	if(i==j) printf("A%d",i);
	else{
		printf("(");
		print(i,s[i][j]);
		print(s[i][j]+1,j);
		printf(")");
	}
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&p[i]);
	for(int i=1;i<=n;i++){
		dp[i][i]=0;
	}
	for(int len=2;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			dp[i][j]=inf;
			for(int k=i;k<j;k++){
				int tmp=dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j];
				if(tmp<dp[i][j]){
					dp[i][j]=tmp;
					s[i][j]=k;
				}
			}
		}
	}
	printf("×îÓÅ½â£º%d\n",dp[1][n-1]);
	print(1,n-1);
} 

