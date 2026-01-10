#include <bits/stdc++.h>
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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

vector<vector<int>> doubling_memo(60, vector<int>());
vector<vector<ll>> doubling_sum(60,vector<ll>());
ll doub(const long long k, const int v) {
  
  int current = v;
  ll sum = 0;
  for (int i = 0; i < 60; i++) {
    if (k & (1LL << i)) {
      sum += doubling_sum.at(i).at(current);
      current = doubling_memo.at(i).at(current);
    }
  }
  return sum;
}
void doubling(const vector<int>& graph) {
  int n = graph.size();
  rep(i,60) doubling_memo.at(i).resize(n);
  rep(i,60) {
    doubling_sum.at(i).resize(n);
    rep(j,n) doubling_sum.at(i).at(j) = 0;
  }
  
  for (int v = 0; v < n; v++) {
    doubling_memo.at(0).at(v) = graph.at(v);
    doubling_sum.at(0).at(v) = v+1;
  }
  
  for (int i = 1; i < 60; ++i) for (int v = 0; v < n; v++) {
    doubling_memo.at(i).at(v) = doubling_memo.at(i-1).at(doubling_memo.at(i-1).at(v));
    doubling_sum.at(i).at(v) = doubling_sum.at(i-1).at(v) + doubling_sum.at(i-1).at(doubling_memo.at(i-1).at(v));
  }
}

int main() {
  ll n;cin>>n;int Q;cin>>Q;
  vector<int> a(n);cin>>a;
  rep(i,n) a.at(i)--;
  doubling(a);
  while(Q--) {
    ll t,b;cin>>t>>b;b--;
    cout << doub(t,b) << endl;
  }

  return 0;
}
