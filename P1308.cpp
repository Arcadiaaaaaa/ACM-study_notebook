// Problem: P1308 [NOIP 2011 普及组] 统计单词数
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1308
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 心得：避免数组越界访问，在访问前必须确保没越界
// find函数查找子串，查找文本中的单词需要手写匹配，以空格划分不同单词与目标词汇比较
#include <bits/stdc++.h>
using namespace std;

int main(){
	string word;
	string s;
	getline(cin,word);
	getline(cin,s);
	for(char &c:s){
		c = tolower(c);
	}
	for(char &c:word){
		c = tolower(c);
	}
	int pos=-1;
	
	int ans=0;
	for(int i=0;i<s.size();){
		while(i <= s.size()&&s[i]==' ')i++;
		if(i>s.size())break;
		int start = i;
		while(i <= s.size()&&s[i]!=' ')i++;
		if(i>s.size())break;
		string t = s.substr(start,i-start);
		if(t == word) {ans++;if(pos==-1)pos=start;}
		
	}
			
			if(pos!=-1)cout<<ans<<" "<<pos;
			else cout<<-1;
	
}