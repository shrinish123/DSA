#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int n,m;
vector<vector<int>> g;
vector<int> vis;
vector<int> comp;
int nodeVis=0;

void dfs(int node){
   vis[node] = 1;
   nodeVis++;
   for(auto v :g[node]){
       if(!vis[v]){
           dfs(v);
       }
   }
}

void solve(){
   cin>>n>>m;
   g.resize(n+1);
   vis.resize(n+1);
   while(m--){
       int a,b;
       cin>>a>>b;
       g[a].push_back(b);
       g[b].push_back(a);

   }

   for(int i=1;i<=n;i++){
       if(!vis[i]){
           dfs(i);
           comp.push_back(nodeVis);
           nodeVis=0;
       }
   }
    int prevSum =0;
    int ans =0;
    for(auto v : comp){
         ans += v * prevSum;
         prevSum+= v;
    }
    cout<<ans<<endl;

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}