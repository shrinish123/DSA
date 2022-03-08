#include<bits/stdc++.h>
using namespace std;


#define endl '\n'
#define pr pair<int,int> 
#define F  first 
#define S  second

int n,m;
char arr[10001][10001];
int dist[10001][10001];
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {0,-1,1,-1,1,-1,0,1};

bool check(int i,int j){
    if(i<0 || i>=n || j< 0 || j>= m || arr[i][j] == '#' ) return false;
    else return true;
}

void bfs(pr st){

    dist[st.F][st.S] =0;

    queue<pr> q;
    q.push(st);
    while(!q.empty()){
       pr cur = q.front();
       int curd = dist[cur.F][cur.S];
       q.pop();
       for(int i=0;i<8;i++){
        int x = cur.F+dx[i];
        int y = cur.S+dy[i];
        if(check(x,y) && dist[x][y] > curd+ 1 ){
            q.push({x,y});
            dist[x][y] = curd+1;
        }
    }
    }
}

void solve(){
    cin>>n>>m;

   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           cin>>arr[i][j];
       }
   }

   pair<int,int> st,en;
   int a,b,c,d;
   cin>>a>>b>>c>>d;
   st.F = a;
   st.S =b;
   en.F =c;
   en.S =d;

   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           dist[i][j] = 1e9;
       }
   }

   bfs(st);
   int ans = dist[en.first][en.second] == 1e9 ? -1 : dist[en.first][en.second] ;

   cout<<ans<<endl;


}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}