#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<stack>
using namespace std;
void fre() { freopen("d://test//input.in", "r", stdin); freopen("d://test//output.out", "w", stdout); }
typedef long long ll;
typedef pair<int,int> pr;
const int maxn=2e5+9;
const int N=1<<20;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
const int temp=233;
const double eps=0.000001;
const double PI=acos(-1);
const int dx[] = {1,1,1,2,2};
const int dy[] = {-1,0,1,-1,1};
const char ds[]={'/','|','\\','(',')'};
inline ll read(){
    ll num=0, w=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if(ch=='-')w=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') {num = (num<<3) + (num<<1) + (ch^48);ch = getchar();}return num*w;
}
int n,m;
int mp[110][110];
void Floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(mp[i][j]>mp[i][k]+mp[k][j]){
					mp[i][j]=mp[i][k]+mp[k][j];
				}
			}
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	memset(mp,inf,sizeof mp);
	for(int i=1;i<=n;i++) mp[i][i]=0;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		mp[u][v]=w;
	}
	Floyd();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",mp[i][j]);	
		}
		printf("\n");
	}
	return 0;
}
/*
4 8
1 2 2
2 3 3
3 4 1
4 1 5
1 3 6
3 1 7
1 4 4
4 3 12
*/
