// Problem: P1873 [COCI 2011/2012 #5] EKO / 砍树
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1873
// Memory Limit: 256 MB
// Time Limit: 1500 ms
/*
    - 求最小可行值时，mid 取下中位数
    - 求最大可行值时，mid 取上中位数，避免死循环
    - 左右边界、mid、答案通常优先开 long long
    r = mid 时，要保证 mid != r，所以取 下中位数
    l = mid 时，要保证 mid != l，所以取 上中位数
    看 mid 能不能作为答案保留下来。
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000005];int n,m;
bool check(ll x){
	ll cnt=0;
	for(int i=0;i<n;i++){
		cnt += max(0ll,a[i]-x);
		//cout<<"dec "<<cnt<<" ";
		if(cnt>=m) return true;
	}
	return false;
}
ll bin_ser_max(ll l ,ll r){
	// 越小越容易，找满足的最大值 最大可行值
	while(l<r){
		ll mid = l+(r-l+1)/2;
		//cout<<"de "<<mid;
		if(check(mid)) {l = mid;}
		else r = mid-1;
	}
	return l;
}
int main()
{
	cin>>n>>m;ll mx=-1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		mx=max(a[i],mx);
	}	
	cout<<bin_ser_max(0,mx);
}