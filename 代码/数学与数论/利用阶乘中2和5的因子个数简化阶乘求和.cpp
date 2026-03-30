// Problem: P12323 [蓝桥杯 2023 省 Java B] 阶乘求和
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P12323
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 心得：遇到大数阶乘，考虑它是10ek的整数倍，简化计算，把10ek拆成2ek*5ek，找2、5因子个数
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000000LL;
/*
// 更优解 每次计算阶乘时沿用前一个数字的结果，减少重复计算
long long fac = 1, sum = 0;
for (int i = 1; i <= 39; i++) {
    fac = fac * i % MOD;
    sum = (sum + fac) % MOD;
}


*/

int main()
{
	std::ios::sync_with_stdio(false); 
	std::cin.tie(NULL);
	ll ans=0;
	for(int i=1;i<=40;i++){
		ll t=1;
		for(int j=1;j<=i;j++)
		{
			t = (j*t)%mod; 
		}
		ans = (ans+t)%mod;
	}
	cout<<ans;
	
    return 0;
}