// Problem: P1579 哥德巴赫猜想（升级版）
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1579
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 心得：
#include <bits/stdc++.h>
using namespace std;
vector<bool> he;
vector<int> zhi;
void zhishushai(int n){
	he.assign(n+1,false);
	if(n>=0) he[0] = true;
	if(n>=1) he[1] = true;
	zhi.clear();
	for(int i=2;i<=n;i++){
		if(!he[i]){
			zhi.push_back(i);
			for(int j =i*i;j<=n;j+=i ){
				he[j] = true;
			}
		}
	}
}
void solve(int len,int n){
	for(int i=0;i<len;i++){
		for(int j=i;j<len;j++){
			for(int k=len-1;k>=0;k--){
				if(zhi[i]+zhi[j]+zhi[k]==n){
					cout<<zhi[i]<<" "<<zhi[j]<<" "<<zhi[k];
					return;
				}
			}
		}
	}
}
int main(){
	int n;
	cin>>n;
	zhishushai(n);
	int len = zhi.size();
	solve(len,n);
}