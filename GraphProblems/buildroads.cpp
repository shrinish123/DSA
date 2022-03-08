#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long


int n,m;
vector<vector<int>> g;
vector<int> vis;

int comp=0;

void dfs(int node){
    vis[node] =1;

    for(auto v :g[node]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

void solve(){
   cin>>n>>m;
   g.resize(n+1);
   vis.assign(n+1,0);
   while(m--){
       int a,b;
       cin>>a>>b;
       g[a].push_back(b);
       g[b].push_back(a);
   }

   for(int i=1;i<=n;i++){
       if(!vis[i]){
           dfs(i);
           comp++;
       }
   }
   cout<<comp-1<<endl;


}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}