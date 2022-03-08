#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int n;
int x[100100];
vector<int> sol;
bool dp[100][1001];
bool saved[100][1001];

bool rec(int level,int sneed){

    if(sneed < 0)return 0;
      
    //base
    if(level == n){
        if(sneed == 0 ) return 1;
        else return 0;
    }

    //cache check
    if(saved[level][sneed]){
        return dp[level][sneed];
    }

    //transition 

    bool ans = rec(level+1,sneed) || rec(level+1,sneed-x[level]);

    //save and ret
     saved[level][sneed] = 1;
     dp[level][sneed] = ans;
     return ans;

}

void generate(int level ,int sneed){
    if(level == n){
        return ;
    }

    if(rec(level+1,sneed)){
        generate(level+1,sneed);
    }else{
        sol.push_back(x[level]);
        generate(level+1,sneed-x[level]);
    }
}



void solve(){
   cin>>n;
   for(int i=0;i<n;i++){
       cin>>x[i];
   }
   int q;
   cin>>q;
   while(q--){
       int y;
       cin>>y;
       cout<<rec(0,y)<<endl;
       if(rec(0,y)){
           sol.clear();
           generate(0,y);
            for(auto v :sol){
                cout<<v<<" ";
            }
            cout<<endl;
       }
   }


}

signed main(){
    solve();
}
