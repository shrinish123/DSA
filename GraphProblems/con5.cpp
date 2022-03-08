#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pr pair<int,int> 
#define F first
#define S second

int n,m,q;
int grid[10001][10001];
int visited[10001][10001];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int white =0;
int nodeVis =0;

bool check(int x,int y){
    if( x< 0 || x>= n || y< 0 || y>= m || grid[x][y] == 0) return false;
    return true;
}

void dfs(pr node){
    if(visited[node.F][node.S]) return;

    visited[node.F][node.S] =1;
    nodeVis++;

      for(int i=0;i<4;i++){
          pr neigh = {node.F+dx[i],node.S+dy[i]};
          if(check(neigh.F,neigh.S)){
              dfs(neigh);
          }
      }

} 


void solve(){
    cin>>n>>m>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j] == 1){
                white++;
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        x--;y--;
        if(grid[x][y] == 1){
              pr node;
                node.F = x; node.S =y;
                dfs(node);
                cout<<white-nodeVis<<endl;
                white = white-nodeVis;
                nodeVis=0;
        }else {
            cout<<white<<endl;
        }
      
    }

}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}