#include<bits/stdc++.h>
using namespace std;


#define int long long 
#define endl '\n'

int n,m;
vector<vector<int>> g;
vector<int> vis;
vector<int> par;
bool flag = false;

void dfs(int node,int parent){
    par[node] = parent;
    vis[node] = 2;
    

    for(auto v : g[node]){
        if( v == par[node])continue;
        if(vis[v] == 1){
            dfs(v,node);
        }else if( vis[v] == 2 ){
            flag =true;
        }
    }
    vis[node] = 3;
}

void solve(){
  cin>>n>>m;
  g.resize(n+1);
  vis.assign(n+1,1);
  par.assign(n+1,0);
  for(int i=0;i<m;i++){
      int a,b;
      cin>>a>>b;
      g[a].push_back(b);
      g[b].push_back(a);
  }


  for(int i=1;i<=n;i++){
      if(vis[i] == 1){
          dfs(i,0);
      }
  }

  flag ? cout<<"YES"<<endl : cout<<"NO"<<endl;
  
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}