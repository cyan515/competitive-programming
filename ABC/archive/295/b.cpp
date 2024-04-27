#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 1000000007;

int main() {
  int r,c;cin>>r>>c;
  vector<string> b(r);
  for(int i=0;i<r;i++) cin>>b.at(i);
  for(int i=0;i<r;i++) {
    for(int j=0;j<c;j++) {
      if(b.at(i).at(j)=='.'
      || b.at(i).at(j)=='#') continue;
      int pow = b.at(i).at(j)-'0';
      for(int k=0;k<r;k++) {
        for(int l=0;l<c;l++) {
          if(abs(i-k)+abs(j-l)<=pow && b.at(k).at(l)=='#') {
            b.at(k).at(l) = '.';
          }
        }
      }
      b.at(i).at(j) = '.';
    }
  }

  for(int i=0;i<r;i++) cout << b.at(i) << endl;

  exit(0);
}
