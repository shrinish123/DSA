#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int n,m;
vector<string> arr;
int vis[1010][1010];
int countr =0;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool isValid(int x,int y){
    if(x<0 || x>=n || y<0 || y>=m || arr[x][y] == '#' || vis[x][y] == 1 ) return false;
    else return true;
}

void dfs(int i,int j){
    vis[i][j] = 1;

    for(int k=0;k<4;k++){

        if(isValid(i+dx[k],j+dy[k])){
            dfs(i+dx[k],j+dy[k]);
        }
    }

}

void solve(){
  cin>>n>>m;
  arr.resize(n);

  for(int i=0;i<n;i++){
        cin>>arr[i];
  }

  for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          if(arr[i][j] == '.' && vis[i][j] == 0){
              dfs(i,j);
              countr++;
          }
      }
  }

  cout<<countr<<endl;

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}