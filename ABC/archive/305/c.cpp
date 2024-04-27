#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using vvi = vector<vector<int>>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 998244353;

int main() {
  int h,w;cin>>h>>w;
  vector<string> s(h);
  for(int i=0;i<h;i++) cin>>s.at(i);
  pair<int,int> first = make_pair(INF,INF);
  for(int i=0;i<h;i++) {
    for(int j=0;j<w;j++) {
      if(s.at(i).at(j)=='#') {
        first = make_pair(min(first.first,i),min(first.second,j));
      }
    }
  }
  pair<int,int> last = make_pair(-INF,-INF);
  for(int i=h-1;i>=0;i--) {
    for(int j=w-1;j>=0;j--) {
      if(s.at(i).at(j)=='#') {
        last = make_pair(max(last.first,i),max(last.second,j));
      }
    }
  }
  int l = first.second;
  int r = last.second;
  int u = first.first;
  int d = last.first;
  for(int i=u;i<=d;i++) {
    for(int j=l;j<=r;j++) {
      if(s.at(i).at(j)=='.') {
        cout << i+1 << " " << j+1 << endl;
        exit(0);
      }
    }
  }

  exit(0);
}
