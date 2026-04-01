// Problem: P1835 素数密度
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1835
// Memory Limit: 128 MB
// Time Limit: 1000 ms
/* 心得：区间筛问题
重点：每个质数 p 从哪里开始筛？
    - 起点至少要是区间内第一个 p 的倍数，也就是 ceil(L / p) * p
    - 但还要保证起点不小于 p * p
    - 因为如果一个 p 的倍数小于 p * p，那么它可以写成 p * k，且 k < p
    - 这说明这个数还含有一个更小的因子，所以它更早就会被更小的质数筛掉
    - 因此起点应取 max(p * p, ceil(L / p) * p)
    - 这样既不会漏筛，也不会把质数 p 自己误标成合数
    (L + p - 1) / p 是“ceil(L / p)”
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> pri;
vector<bool> com;
void ass(ll n){
	com.assign(n+1,false);
	pri.clear();
	if(n>=0) com[0]=true;
	if(n>=1) com[1]=true;
	for(int i=2;i<=n;i++){
		if(!com[i]){
			pri.push_back(i);
			for(ll j=1LL*i*i;j<=n;j+=i){
				com[j]=true;
			}
		}
	}
}

ll sqrtplus(ll x){
	ll t = (ll)sqrt(x);
	while(t*t<x) t+=1;
	while(t*t>x) t-=1;
	return t;	
}
vector<bool> com_q;
void qujianshai(ll L,ll R){
	com_q.assign(R-L+1,false);
	ll n = sqrtplus(R);
	ass(n);
	for(ll i:pri){
		ll start = max(1LL*i*i,(L+i-1)/i*i);
		for(ll x=start;x<=R;x+=i){
			com_q[x-L] = true;
		}
	}
	for(int i=max(0LL,L);i<=min(R,1LL);i++){
		com_q[i-L]=true;
	}
}
int main(){
	ll L,R;
	cin>>L>>R;
	qujianshai(L,R);
	int ans =0;
	for(int i:com_q){
		if(i==false) ans++;
	}
	cout<<ans;
}