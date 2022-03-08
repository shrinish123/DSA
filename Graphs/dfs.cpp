#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long 
const int mod = 1e9 + 7;

//graph variables
int n,m;
vector<vector<int>> g;
vector<int> vis;

int nodeVisited =0;

void dfs(int node) {
    vis[node] = 1;
    nodeVisited++;
    for(auto v : g[node]) {
        if(!vis[v]) {
            dfs(v);
        }
    }
}


void solve() {
    cin>>n>>m;
    g.clear();
    g.resize(n+1);
    vis.assign(n+1,0);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> comp;

    for(int node =1;node<=n;node++){
        if(!vis[node]) {
            nodeVisited =0;
            dfs(node);
            comp.push_back(nodeVisited);
        }
    }

    int prevSum =0;
    int ans =0;
    for(auto v: comp){
        ans += prevSum*v;
        prevSum+=v;
    }   

    cout<<ans<<endl;
 }

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t;cin>>_t;
    string temp;
    getline(cin,temp);
    while(_t--)
    solve();
}