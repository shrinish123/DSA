#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
// #define int long long 
const int mod = 1e9 + 7;

int n,k;
int ans=0;
map<int,int> mp;
vector<int> curPerm;


void rec(int level) {
    if(level == n) {
       ans++;
        if(ans == k){
            for(int i=0;i<n;i++){
               cout<<curPerm[i]<<" ";
           }
           cout<<endl;
        }
       return;
    }

     for( auto it : mp){
         if(it.second != 0){
             curPerm.push_back(it.first);
             mp[it.first]--;
             rec(level+1);
             if(ans == k){
                 break;
             }
             curPerm.pop_back();
             mp[it.first]++;
         }
     }
}


void solve() {
     cin>>n>>k;
     for(int i=0;i<n;i++){
         mp[i+1]++;
     }
    rec(0);

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

// Dont declare count as global variable as there is alredy a built in function count
// in map it.second-- does nto work as its a unidirectional itrator .instead use mp[it.first]--