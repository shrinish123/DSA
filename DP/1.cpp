#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long 

int n;
int b,k;
int p[100100];
int h[100100];
int dp[101][1001][101];

int rec(int level,int cost ,int size){
    //Pruning

    //Base Case
    if(level == n){
        return 0;
    }
    //cache check
    if(dp[level][cost][size] != -1){
        return dp[level][cost][size];
    }

    //Transitions

   int ans =  rec(level+1,cost,size);
    
    if(cost+p[level] <=b && size+1 <= k){
         ans = max(ans,h[level]+ rec(level+1,cost+p[level],size+1));
    }

    //save and return 

    dp[level][cost][size] = ans;
    return ans;
 

}

void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i];
        cin>>h[i];
    }
    cin>>b>>k;
    memset(dp,-1,sizeof(dp));
 
    cout<<rec(0,0,0)<<endl;

  
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();

}