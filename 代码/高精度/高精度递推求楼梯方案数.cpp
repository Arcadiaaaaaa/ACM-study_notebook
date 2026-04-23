// Problem: P1255 数楼梯
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1255
// Memory Limit: 128 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
string delete_leading0(string s){
	int i=0;
	while(i<s.size()&&s[i]=='0') i++;
	if(i!=s.size()) return s.substr(i);
	else return "0";
}
string add(string a,string b){
	int carry=0;string ans="";
	a=delete_leading0(a);
	b=delete_leading0(b);
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for(int i=0;i<max(a.size(),b.size())|| carry;i++)
	{
		int sum = carry;
		if(i<a.size()) sum+=a[i]-'0';
		if(i<b.size()) sum+=b[i]-'0';
		ans.push_back(char('0'+sum%10));
		carry = sum/10;
	}
	reverse(ans.begin(),ans.end());
	return delete_leading0(ans);
	
}
int main()
{
	std::ios::sync_with_stdio(false); 
	std::cin.tie(NULL);

	int n;
	cin>>n;
	vector<string> a(5005);
	a[1]="1";
	a[2]="2";
	for(int i=3;i<=n;i++){
		a[i]=add(a[i-1],a[i-2]);
	}
	cout<<a[n];
    return 0;
}