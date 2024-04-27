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
  vector<string> a(h);
  vector<string> b(h);
  for(int i=0;i<h;i++) cin>>a.at(i);
  for(int i=0;i<h;i++) cin>>b.at(i);
  bool flg = false;
  for(int i=0;i<h;i++) {
    for(int j=0;j<w;j++) {
      bool ok = true;
      for(int k=0;k<h;k++) {
        for(int l=0;l<w;l++) {
          if(a.at(k).at(l)!=b.at((k+i)%h).at((l+j)%w)) {
            ok = false;
            break;
          }
        }
        if(!ok) break;
      }
      if(ok) flg=true;
    }
  }

  if(flg) cout << "Yes";
  else cout << "No";
  cout << endl;

  exit(0);
}
