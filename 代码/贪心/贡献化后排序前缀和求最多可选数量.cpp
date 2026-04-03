// Problem: P13887 [蓝桥杯 2023 省 Python A] 三国游戏
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P13887
// Memory Limit: 512 MB
// Time Limit: 3000 ms
/*
这题最重要的收获是“贡献化”。
把
X > Y + Z
改写成
X - Y - Z > 0
于是每个事件对魏国胜利的贡献就是
a[i] - b[i] - c[i]
另外两国同理。
原来三维的问题，被压成了一维选数问题。
问题变成：
选尽量多的数，使它们的和 > 0
这种“选最多个”要想到：
如果固定选 k 个，怎样让总和最大？
答案是取最大的 k 个。
所以做法就是：
排序 + 前缀和
这题的贪心依据是：
前 k 大的和，是所有选 k 个方案里最大的和。
如果前 k 大都不行，别的 k 个更不行。
这题提醒我要注意边界：
条件是 > 0，不是 >= 0
前缀和等于 0 就已经不合法
如果一直合法到最后，答案可能是 n
如果三国都不行，答案是 -1
赛时思维收获：
看到“最终只比较总和”的题，
先别急着想 DP，
先看能不能把判定式移项，
把每个元素变成一个贡献值。
以后遇到这类题的模板：
先移项
再定义贡献
再排序
再扫前缀和
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(ll i,ll o){
	return i>o;
}
int main()
{
	std::ios::sync_with_stdio(false); 
	std::cin.tie(NULL);
	int n;cin>>n;
	int a[n],b[n],c[n];
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	for(int i=0;i<n;i++) cin>>c[i];
	
	ll da[n],db[n],dc[n];
	for(int i=0;i<n;i++){
		da[i] = a[i]-b[i]-c[i];
	}
	for(int i=0;i<n;i++){
		db[i] = b[i]-a[i]-c[i];
	}
	for(int i=0;i<n;i++){
		dc[i] = c[i]-b[i]-a[i];
	}
	sort(da,da+n,cmp);sort(db,db+n,cmp);sort(dc,dc+n,cmp);
	ll daq[n],dbq[n],dcq[n];
	daq[0]=da[0];dbq[0]=db[0];dcq[0]=dc[0];
	for(int i=1;i<n;i++){
		daq[i]=da[i]+daq[i-1];
		dbq[i]=db[i]+dbq[i-1];
		dcq[i]=dc[i]+dcq[i-1];
	}
	int a1=-1,a2=-1,a3=-1;
	ll sum = 0;

    sum = 0;
    for(int i = 0; i < n; i++){
        sum += da[i];
        if(sum > 0) a1 = i + 1;
        else break;
    }

    sum = 0;
    for(int i = 0; i < n; i++){
        sum += db[i];
        if(sum > 0) a2 = i + 1;
        else break;
    }

    sum = 0;
    for(int i = 0; i < n; i++){
        sum += dc[i];
        if(sum > 0) a3 = i + 1;
        else break;
    }
	cout<<max(a1,max(a2,a3));
    return 0;
}