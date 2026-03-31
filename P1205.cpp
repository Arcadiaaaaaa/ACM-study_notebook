// Problem: P1205 [USACO1.2] 方块转换 Transformations
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1205
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// vector a,b可以直接比较 a==b
#include <bits/stdc++.h>
using namespace std; 
vector<string> rotate90(vector<string> a){
	vector<string> t(a.size(),string (a.size(),' '));
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a.size();j++){
			t[i][j] = a[a.size()-j-1][i];
		}
	}
	return t;
}
vector<string> reflect(vector<string> a){
	vector<string> t(a.size(),string (a.size(),' '));
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a.size();j++){
			t[i][j] = a[i][a.size()-j-1];
		}
	}
	return t;
}
int solve(vector<string> a,vector<string> b){
	if(rotate90(a)==b)return 1;
	if(rotate90(rotate90(a))==b) return 2;
	if(rotate90(rotate90(rotate90(a)))==b) return 3;
	if(reflect(a)==b) return 4;
	if(rotate90(reflect(a))==b ||
	rotate90(rotate90(reflect(a)))==b ||
	rotate90(rotate90(rotate90(reflect(a))))==b) return 5;
	if(a==b) return 6;
	return 7;
}
int main()
{
	int n;cin>>n;
	vector<string>a(n);
	vector<string>b(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	cout<<solve(a,b);
	
}