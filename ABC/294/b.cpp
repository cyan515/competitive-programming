#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 1000000007;

int main() {
  int h,w;cin>>h>>w;
  for(int i=0;i<h;i++) {
    for(int j=0;j<w;j++) {
      int a;cin>>a;
      if(a==0) cout << ".";
      else {
        char c = 'A'+a-1;
        string s = "" + c;
        cout << c;
      }
    }
    cout << endl;
  }

  exit(0);
}
