#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int maxn=1e5+9;
const int inf=0x3f3f3f3f;
int arr[maxn];
void select_k(int arr[],int l,int r,int k){
	int i=l,j=r,mid=arr[(l+r)>>1];
	while(i<=j){
		while(arr[i]<mid) i++;
		while(arr[j]>mid) j--;
		if(i<=j){
			swap(arr[i],arr[j]);
			i++,j--;
		}
	}
	if(l<=j&&k<=j-l+1) select_k(arr,l,j,k);
	if(i<=r&&k>=i-l+1) select_k(arr,i,r,k-(i-l));
}
 
int main()
{
    srand(time(0));
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;++i) arr[i]=rand()%1000;
    for(int i=1;i<=n;++i) cout<<arr[i]<<' ';
    cout<<endl;
    select_k(arr,1,n,k);
    cout<<"第"<<k<<"位数字是"<<arr[k]<<endl;
    return 0;
}


