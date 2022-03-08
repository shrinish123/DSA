#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long 
const int mod = 1e9 + 7;

vector<int> unlock;
int grid[3][3] ={0};
vector<vector<int>> allSol;
int ans =0;
int n;

bool check(int i ,int j) {

    int last;
    
    if(unlock.size() == 0) {
        return true;
    }else{
        last = unlock[unlock.size() -1];
    }
   
   int lasti = last/3;
   int lastj = last%3;

    for(int k=0;k<unlock.size();k++){
        if(i == unlock[k]/3 && j== unlock[k]%3) {
            return false;
        }
    }

    if(i == lasti )







}

void rec(int level) {
    if(level == n) {
        ans++;
        allSol.push_back(unlock);
        return;
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){

            if(check(i,j)){
            unlock.push_back(i*3 + j );
            grid[i][j] =1;


            rec(level+1);

            
            int last = unlock[unlock.size() -1];
            grid[last/3][last%3] = 0;
            unlock.pop_back();
        }

        }
    }
}


void solve() {
    cin>>n;
    rec(0);
    cout<<ans<<endl;

    for(int i=0;i<allSol.size();i++){
        for(int j=0;j<allSol[i].size();j++){
            cout<<allSol[i][j]<<" ";
        }
        cout<<endl;
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