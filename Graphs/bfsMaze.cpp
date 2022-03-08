#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'

int n,m;
vector<vector<int>> g;
vector<int> dist;

void bfs(int st){

    dist[st] = 0;
    queue<int> q;

    q.push(st);
    while(!q.empty()){
        int cur = q.front();
        int curd = dist[cur];

        q.pop();

        for(auto v : g[cur]){
            if(dist[v] > curd +1){
                dist[v] = curd+1;
                q.push(v);
            }
        }
    }

}

void solve(){
   cin>>n>>m;
   g.resize(n+1);
   dist.assign(n+1,1e9);
   for(int i=0;i<m;i++){
       int x,y;
       cin>>x>>y;
       g[x].push_back(y);
   }
   int st,en;
   cin>>st>>en;
   bfs(st);
   cout<<dist[en]<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    solve();
}