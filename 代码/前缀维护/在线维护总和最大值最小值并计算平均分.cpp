// Problem: P8830 [传智杯 #3 练习赛] 评委打分
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P8830
// Memory Limit: 512 MB
// Time Limit: 2000 ms

//把“每次都重新统计一遍前面的结果”，改成“边读边维护需要的信息，后面直接复用”。
#include <bits/stdc++.h>
using namespace std;

int a[int(1e6+5)];

int main()
{
	std::ios::sync_with_stdio(false); 
	std::cin.tie(NULL);

	int n;cin>>n;
	cin>>a[0]>>a[1];int mx=max(a[0],a[1]),mi=min(a[0],a[1]);int sum = a[0]+a[1];
	for(int i=2;i<n;i++){
		cin>>a[i];
		if(a[i]>mx) mx=a[i];
		if(a[i]<mi) mi=a[i];
		sum+=a[i];
		double ans = (sum-mx-mi)/double(i-1);
		printf("%.2f\n",ans);
		
	}
	
    return 0;
}