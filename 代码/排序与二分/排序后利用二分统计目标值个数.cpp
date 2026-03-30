// Problem: P1102 A-B 数对
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1102
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 心得：n是1e5，ans最坏是n方2e10，需要开long long
#include <bits/stdc++.h>
using namespace std;
int a[200001];
int n;
int find(int x){
	return upper_bound(a,a+n,x)-lower_bound(a,a+n,x);
}
int main(){
	int c;cin>>n>>c;//b=a+c
	
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long ans=0;
	for(int i=0;i<n;i++){
		int f=a[i]+c;
		ans+=find(f);
	}
	cout<<ans;
}
