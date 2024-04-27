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
  int n;cin>>n;
  int m;cin>>m;
  int h;cin>>h;
  int k;cin>>k;
  string s;cin>>s;
  bool flg = true;
  set<pair<int,int>> item;
  for(int i=0;i<m;i++) {
    int a,b;cin>>a>>b;
    item.insert(make_pair(a,b));
  }
  int x = 0;
  int y = 0;
  for(int i=0;i<n;i++) {
    char c = s.at(i);
    h--;
    if(h<0) {
      flg = false;
      break;
    }
    if(c=='R') {
      x++;
    } else if(c=='L') {
      x--;
    } else if(c=='U') {
      y++;
    } else if(c=='D') {
      y--;
    }
    if(item.find(make_pair(x,y))!=item.end()&&h<k) {
      h = max(h,k);
      item.erase(make_pair(x,y));
    }
  }

  if(flg) cout << "Yes";
  else cout << "No";
  cout << endl;

  exit(0);
}
