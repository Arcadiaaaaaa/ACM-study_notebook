// Problem: P1886 【模板】单调队列 / 滑动窗口
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1886
// Memory Limit: 500 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
const int _N = 1000009;
int a[_N];
deque<int> q;
void find_big(int n,int k){
	for(int i=0;i<n;i++){
		while(!q.empty() && a[q.back()] < a[i])q.pop_back();
		q.push_back(i);
		if(i>=k-1){
			while(!q.empty() && q.front()<=i-k)q.pop_front();
			printf("%d ",a[q.front()]);
		}
	}
}
void find_small(int n,int k){
	for(int i=0;i<n;i++){
		while(!q.empty()&&a[q.back()]>a[i]) q.pop_back();
		q.push_back(i);
		if(i>=k-1){
			while(!q.empty()&&q.front()<=i-k)q.pop_front();
			printf("%d ",a[q.front()]);
		}
	}
}
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	find_small(n,k);
	printf("\n");
	while(!q.empty())q.pop_back();
	find_big(n,k);
}