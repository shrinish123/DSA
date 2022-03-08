#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long 
const int mod = 1e9 + 7;


void solve() {
    
    int n;
    cin>>n;
    int arr[n];
     map<int,int> freq;

    for(int i=0;i<n;i++){
      cin>>arr[i];
       freq[arr[i]]++;
    }
    int extra =0;
    

    for(auto it : freq){
          if(it.second > 1 && it.first !=0 && freq.find(-it.first) == freq.end()){
        extra++;
      }
    }

    cout<<freq.size()+extra<<endl;


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