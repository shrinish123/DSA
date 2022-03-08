#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'


//graph
int n,m;
vector<vector<int>> g;
vector<int> col;
vector<int> parent;
vector<int> cycle;
bool is_cycle = false;

void dfs(int node,int par) {
    parent[node] = par;
    col[node] = 2;

    for(auto v : g[node]) {
        // if(v==parent[node])continue;  for undirected
        if(col[v] == 1) {
            dfs(v,node);
        }
        else if( col[v] == 2 ) {
             is_cycle = true;

             if(is_cycle){
                  int temp = node;
                  while(temp != v) {
                      cycle.push_back(temp);
                      temp = parent[temp];
                  }
                  cycle.push_back(temp);
                 
             }


        }
        else {
          //do nothing 
        }
    }
     
     col[node] =3;

}


void solve(){
  
  cin>>n>>m;


  g.clear();
  g.resize(n+1);
  col.assign(n+1,1);
  parent.assign(n+1,0);

  for(int i=0;i<m;i++){
      int a,b;
      cin>>a>>b;
      g[a].push_back(b);
    //   g[b].push_back(a);   // only for undirected
  }

  for(int i=1;i<=n;i++){
      if(col[i] == 1){
         dfs(i,0);
      }
  }

   is_cycle? cout<<"YES"<<endl : cout<<"NO"<<endl;

   for(auto it : cycle){
       cout<< it <<" ";
   }

   cout<<endl;
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