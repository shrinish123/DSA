#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
// #define int long long 
const int mod = 1e9 + 7;
const int N = 10010;
int n,m,q;
vector<vector<int>> g;
vector<int> vis;
int id = 0;
vector<int> nodes;
vector<int> compsz;

void dfs(int node){
   vis[node] =1;
   nodes[node] = id;
   compsz[id]++;
   for(auto v : g[node]){
       if(!vis[v]){
           dfs(v);
       }
   }
}



void solve() {
    cin>>n>>m>>q;
    g.resize(n+1);
    vis.assign(n+1,0);
    nodes.resize(n+1);
    compsz.resize(n+1);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
          g[a].push_back(b);
          g[b].push_back(a);
    }
    


    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
              id++;
        }
    }

    


    while(q--){

        int a;
        cin>>a;
        if(a ==1){
            int x;
            cin>>x;
            cout<<compsz[nodes[x]]<<endl;

        }else {
            int x,y;
            cin>>x>>y;
            nodes[x] == nodes[y] ? cout<<"YES"<<endl : cout<<"NO"<<endl;
    }
 }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t;cin>>_t;
    // string temp;
    // getline(cin,temp);
    // while(_t--)
    solve();
}