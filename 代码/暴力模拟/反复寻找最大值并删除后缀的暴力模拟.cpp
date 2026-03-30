#include <bits/stdc++.h>
using namespace std;




vector<int> a;
int main()
{
	std::ios::sync_with_stdio(false); 
	std::cin.tie(NULL);
    int n;cin>>n;a.resize(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans =0 ;
    while(!a.empty()){
        int max = -1;int p=0;
        for(int i=0;i<n;i++){
            if(a[i]>=max) {
                max=a[i];p=i;
            }
        }
        for(int i=n-1;i>=p-1;i--){
            a.pop_back();
        }
        ans++;n=p;
        if(a.size()==1){ans++;a.pop_back();}
    }
	
	cout<<ans;
    return 0;
}