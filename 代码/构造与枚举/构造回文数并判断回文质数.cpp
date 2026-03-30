// Problem: P1217 [USACO1.5] 回文质数 Prime Palindromes
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1217
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 遍历查找符合条件的一定超时，反过来构造回文数再判断是否合规
// 所有偶数位数的回文数都不是质数，因为都能被11整除
// 快速判断一个十进制数是否可以被另一个数整除，思路：将十进制数拆成 10的次方 和的形式，然后对每一项分别取模观察规律
// 即十进制整除判定的核心是把整数按位权展开，再利用 10𝑖次方mod m 的规律化简。
#include <bits/stdc++.h>
using namespace std;
bool is_p(int x){
	if(x<2) return 0;
	if(x==2) return 1;
	if(x%2==0) return 0;
	for(int i = 3;i<=x/i;i+=2){
		if(x%i==0) return 0;
	}
	return 1;
}
int creat(int x){
	int res=1;
	res =x;
	x = x/10;
	while(x){
		res = res*10 + x%10;
		x = x/10;
	}
	return res;
}
int main(){
	int a,b;
	cin>>a>>b;
	int short1[] = {2,3,5,7,11};
	for(int i:short1){
		if(i>=a&&i<=b)cout<<i<<"\n";
	}
	for(int x = 10;;x++){
		int t = creat(x);
		if(t<a) continue;
		if(t>b) break;
		if(is_p(t)) cout<<t<<"\n";
		
	}
}