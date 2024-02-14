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
  vector a(n,vector<int>(3));
  rep(i,n) cin>>a.at(i).at(0)>>a.at(i).at(1)>>a.at(i).at(2);
  rep(i,n) sort(a.at(i).begin(),a.at(i).end());
  sort(a.begin(),a.end());
  bool flg = false;

  int mi = a.at(0).at(1);
  vector<int> idx;
  rep(i,n) {
    if(a.at(i).at(1)>mi) {
      idx.push_back(i);
    }
  }

  if(flg) cout << "Yes" << endl;
  else cout << "No" << endl;

  exit(0);
}
