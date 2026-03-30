// Problem: P2388 阶乘之乘
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2388
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 心得：连续阶乘计算，可用仅增量更新优化时间复杂度
#include <bits/stdc++.h>
using namespace std;


int cal(int x){
	int re=0;
	while(x){
		if(x%5!=0)break;
		else {
			re++;
			x = x/5;
		}
	}
	return re;
}
int main()
{
	std::ios::sync_with_stdio(false); 
	std::cin.tie(NULL);

	int n;
	cin>>n;
	if(n<5) {cout<<0;
    return 0;}
    long long ans=0;
    long long f=0;
    for(int i=5;i<=n;i++){
    	f = f +cal(i);
    	ans += f;
    }
    cout<<ans;
}