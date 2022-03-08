#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long 
const int mod = 1e9 + 7;

int n;
vector<int> queen;
int ans =0;

bool check(int row,int col) {
  
   for(int i=0;i<queen.size();i++) {

       if(col == queen[i] + (row - i) || col == queen[i] - (row -i)  || col == queen[i]) {
           return false;
       }
         return true;
   }
}

void rec(int level) {

    if(level == n) {
        ans++;
        return;
    }

    for(int col =0;col<n;col++) {
        if(check(level,col)) {
          queen.push_back(col);
          rec(level+1);
          queen.pop_back();
        }
    }
}

void solve() {
    cin>>n;
    rec(0);
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