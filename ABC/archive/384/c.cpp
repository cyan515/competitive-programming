#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
const string Yes = "Yes";
const string No = "No";
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  vector<ll> x(5);cin>>x;
  string y = "ABCDE";
  vector<pair<ll,string>> ans;
  reps(bit,1,1<<5) {
    ll sum = 0;
    string s = "";
    rep(i,5) {
      if((bit&(1<<i))>0) {
        sum += x.at(i);
        s.push_back(y.at(i));
      }
    }
    ans.push_back(pair(-sum,s));
  }
  sort(all(ans));
  rep(i,ans.size()) {
    cout << ans.at(i).second << endl;
  }
  
  return 0;
}
