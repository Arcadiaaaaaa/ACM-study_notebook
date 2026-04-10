// Problem: P5019 [NOIP 2018 提高组] 铺设道路
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5019
// Memory Limit: 125 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
//从左往右扫，前面的操作能覆盖当前就继续用；只有当前深度比前一个位置更高时，才需要新开操作。新开的数量就是这段“多出来的高度”。

int a[100005];
int main()
{
	std::ios::sync_with_stdio(false); 
	std::cin.tie(NULL);
	int n;cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];a[i]-=1;
	}
	long long ans=a[1];
	for(int i=2;i<=n;i++)
	{
		if(a[i]>a[i-1]) ans+=(a[i]-a[i-1]);
	}
	cout<<ans;
    return 0;
}