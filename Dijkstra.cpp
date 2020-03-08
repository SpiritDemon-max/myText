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
int dis[maxn];
bool vis[maxn];
void Dijkstra(int x){
	memset(dis,inf,sizeof dis);
	vis[x]=1;
	dis[x]=0;
	for(int i=1;i<=n;i++){
		dis[i]=min(dis[i],mp[x][i]);
	}
	for(int i=1;i<n;i++){
		int minn=inf,pos=0;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&dis[j]<minn){
				minn=dis[j];
				pos=j;
			}
		}
		vis[pos]=true;
		for(int j=1;j<=n;j++){
			dis[j]=min(dis[j],dis[pos]+mp[pos][j]);
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
	Dijkstra(1);
	for(int i=1;i<=n;i++){
		printf("%d ",dis[i]);
	}
	printf("\n");
	return 0;
}
/*
8 11
1 2 1
2 4 2
3 1 2
4 3 1
5 4 2
6 5 2
4 6 8
5 7 2
7 6 3
8 6 2
7 8 3
*/
