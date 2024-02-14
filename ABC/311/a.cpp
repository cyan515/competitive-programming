#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using vvi = vector<vector<int>>;
using rpqi = priority_queue<int, vector<int>, greater<int>>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

int main() {
  int n;cin>>n;
  string s;cin>>s;
  bool a=false;
  bool b=false;
  bool c=false;
  rep(i,n) {
    if(s.at(i)=='A') a=true;
    if(s.at(i)=='B') b=true;
    if(s.at(i)=='C') c=true;
    if(a&&b&&c) {
      cout << i+1 << endl;
      exit(0);
    }
  }

  exit(0);
}
