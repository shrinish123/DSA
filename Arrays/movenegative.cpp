#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long 

const int mod = 1e9 + 7;

void solve() {
   
    string str;
    getline(cin,str);
    string x,y,z;
    bool isX =1;
    bool isY =0;
    bool isZ =0;

  for(int i=0;i<str.size();i++) {
      
      if(str[i] == ' ') {
          isY =1;
          isX =0;
      } 
      if(str[i] == '.') {
          isZ = 1;
          isY =0;
      }

      if(isX) {
          x += str[i];
      }
      if(isY) {
          y += str[i];
      }
      if(isZ) {
          z+= str[i];
      }
  }

//   int xn,yn,zn;
//   xn = stoll(x);
//   yn = stoll(y);
//   zn = stoll(z);

int x1 = stoll(x),y1 =stoll(y), z1 =stoll(z);

  cout<<(z1+x1) <<"." << (y1+x1)<<endl;

   
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
