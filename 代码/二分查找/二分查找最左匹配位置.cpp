// Problem: P2249 【深基13.例1】查找
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2249
// Memory Limit: 125 MB
// Time Limit: 1000 ms

// 心得：二分查找注意边界条件，当num==a[mid]时，不能直接返回mid，而是要继续向左边查找，直到找到最左边的那个num的位置。
#include<bits/stdc++.h>
using namespace std ;
const int N = int(1e6+10);
int a[N];
int bin_s(int num,int n){
	int left,right;
	left=1;right=n;
	int mid;int ans=-1;
	while(left<=right){
		mid=left+(right-left)/2;
		if(num==a[mid]) {ans = mid;right=mid-1;}
		if(num>a[mid]){
			left=mid+1;
		}
		if(num<a[mid]){
			right=mid-1;
		}
	}
	return ans;
	
}
int main(){
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	while(m--){
		int t;
		cin>>t;
		printf("%d ",bin_s(t,n));
	}
}