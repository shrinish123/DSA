#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long 
const int mod = 1e9 + 7;


void solve() {

    int n;
    cin>>n;

    for(int den =1234; den <= 98765/n; den++) { // also abcde can be 6 digit no. Also max value of abcde is 98765
        
        int num = den * n;

        set<int> st;

        int temp = den;

       for(int i=0;i<5;i++) {
           st.insert(temp%10);
           temp/=10;
       }
        temp = num;
       
       for(int i=0;i<5;i++) {  // cannot use while because 0 being the leading digit
           st.insert(temp%10);
           temp/=10;
       }

        if(st.size() == 10) {
             cout<<num<<" "<<den<<endl;
        }
        
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