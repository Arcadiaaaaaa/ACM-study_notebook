// Problem: P12157 [蓝桥杯 2025 省 Java B] 魔法科考试
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P12157
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 心得：埃氏筛法，注意特判0 1是合数不是质数；使用unordered_set自动去重
// 代码有冗余部分未删除 且代码中埃氏筛非最优，存在大量重复计算
#include <bits/stdc++.h>
using namespace std;
vector<bool> is_he;
vector<int> prim;
void aishishai(int n){
	is_he.assign(n+1,false);
	if(n>=0) is_he[0] == true;
	if(n>=1) is_he[1] == true;
	prim.clear();
	for(int i=2;i<=n;i++){
		if(!is_he[i]){
			prim.push_back(i);
			for(int j=2;j*i<=n;j++){
				is_he[i*j] = true;
			}
		}
	}
}
bool isp(int x){
	if(x==1) return false;
	if(x==2||x==3) return true;
	if(x%2==0||x%3==0) return false;
	for(int i=5;i*i<=x;i+=6){
		if(x%i==0||x%(i+2)==0) return false;
	}
	return true;
}

int main()
{
	std::ios::sync_with_stdio(false); 
	std::cin.tie(NULL);
	
	int n,m;cin>>n>>m;
	int k = m+n;
	vector<int> a(n),b(m);
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<m;i++)cin>>b[i];
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	aishishai((a[a.size()-1]+b[b.size()-1]));
	unordered_set<int> st;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if(a[i]+b[j]<=k&&!is_he[a[i]+b[j]]) {
				st.insert(a[i]+b[j]);
			//cout<<a[i]<<b[j]<<" ";
			}
		}
	
	cout<<st.size();	
    return 0;
}
