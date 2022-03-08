#include<bits/stdc++.h>
using namespace std;

#define int long long 

void solve(){

  int l,n;
  cin>>l>>n;
  vector<int> v;
  for(int i=0;i<n;i++){
      int x;
      cin>>x;
      v.push_back(x);
  }

  sort(v.begin(),v.end());
  if(n==1){
      cout<<l<<endl;
  }else {
     
      int mana =v[0]+v[1];
      int cost = mana;

        for(int i=1;i<n-1;i++){
            cost = cost+ v[i+1];
            mana += cost;
        }
        cout<<mana<<endl;
  }
 

}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}
