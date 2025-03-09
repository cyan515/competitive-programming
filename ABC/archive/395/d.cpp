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
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  ll n,Q;cin>>n>>Q;
  vector<int> pos(n);
  vector<int> num(n);
  vector<int> idx(n);
  rep(i,n) num.at(i) = i, pos.at(i) = i, idx.at(i) = i;
  while(Q--) {
    int t;cin>>t;
    ll a,b;
    if(t==1) {
      cin>>a>>b;a--;b--;
      pos.at(a) = idx.at(b);
    } else if(t==2) {
      cin>>a>>b;a--;b--;
      swap(num.at(idx.at(a)),num.at(idx.at(b)));
      swap(idx.at(a),idx.at(b));
    } else {
      cin>>a;a--;
      cout << num.at(pos.at(a))+1 << endl;
    }
  }

  return 0;
}
