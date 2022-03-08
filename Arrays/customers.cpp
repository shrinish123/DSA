#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long 



void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    while(n--){
       int a,b;
      cin>>a>>b;
      v.push_back({a,1});
      v.push_back({b,-1});
    }

   sort(v.begin(),v.end());
   int cur =0;
   int ans =0;
   for(auto it : v){
      
      cur+= it.second;
      ans = max(ans,cur);
   }
   cout<<ans<<endl;
    

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--){
    solve();
    }
}
