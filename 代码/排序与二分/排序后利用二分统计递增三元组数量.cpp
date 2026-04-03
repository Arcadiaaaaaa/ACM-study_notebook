// Problem: P8667 [蓝桥杯 2018 省 B] 递增三元组
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P8667
// Memory Limit: 256 MB
// Time Limit: 1000 ms

/* 
1）求 A 中小于 b 的个数

排序后，A 里所有小于 b 的数会集中在前面。

用 lower_bound(A.begin(), A.end(), b)：

返回第一个 大于等于 b 的位置
这个位置的下标，就是 < b 的元素个数
2）求 C 中大于 b 的个数

用 upper_bound(C.begin(), C.end(), b)：

返回第一个 大于 b 的位置
这个位置后面的元素都 > b

还要注意这俩函数返回值是指针，要做指针减法才是数量
*/
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int a[N];
int b[N];
int c[N];

bool cmp(int q,int w){
	return q<w;
}
int main()
{
	std::ios::sync_with_stdio(false); 
	std::cin.tie(NULL);

	int n;cin>>n;
	
		for(int j=0;j<n;j++){
			cin>>a[j];
		}
		for(int j=0;j<n;j++){
			cin>>b[j];
		}
		for(int j=0;j<n;j++){
			cin>>c[j];
		}
	
	sort(a,a+n,cmp);
	sort(c,c+n,cmp);
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		int B=b[i];
		long long A=lower_bound(a,a+n,B)-a;
		long long C=(c+n)-upper_bound(c,c+n,B);
//为什么开longlong：因为 `A` 和 `C` 都是 `int`，
//`A*C` 会先按int算，结果可能达到10e10超出int范围

		ans+=A*C;
	}
	cout<<ans;
	
    return 0;
}