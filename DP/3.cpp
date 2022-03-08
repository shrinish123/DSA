#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long 

int n,k;
string comp;
int moves[100100];
int dp[100100][3][101];
map<char,int> mp;

int result(int mymove,int compmove){
    return compmove == (mymove+1)%3;
}

int rec(int level,int last, int chleft){
    //pruning 
    if(chleft < 0 )
    return  -1e9;

    //basecase 
    if(level == n){
        return 0;
    }

    //cache check
    if(dp[level][last][chleft] != -1){
        return dp[level][last][chleft];
    }

    // transition 
    int ans =0; 
    for(int i=0;i<3;i++){
        ans = max(ans,result(i,moves[level]) + rec(level+1,i,chleft - (i ==last ? 0: 1)));
    }



    //save and return 
    return  dp[level][last][chleft] = ans;

}

void solve(){
  cin>>n>>k;
  
  mp['R'] = 0;
  mp['P'] = 1;
  mp['S'] = 2;

  for(int i=0;i<n;i++){
      cin>>comp[i];
      int num = mp[comp[i]];
      moves[i] = num;
  }
  
  for(int i=0;i<n;i++){
      for(int j=0;j<3;j++){
          for(int m=0;m<k;m++){
              dp[i][j][k] =-1;
          }
      }
  }


}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}