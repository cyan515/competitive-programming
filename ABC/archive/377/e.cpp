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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

vector<int> doubling(const vector<int>& graph, const long long k) {
  int n = graph.size();
  vector<vector<int>> doubling(60, vector<int>(n));
  
  for (int v = 0; v < n; v++) {
    doubling.at(0).at(v) = graph.at(v);
  }
  
  for (int i = 1; i < 60; ++i) for (int v = 0; v < n; v++) {
    doubling.at(i).at(v) = doubling.at(i-1).at(doubling.at(i-1).at(v));
  }
  
  vector<int> result(n);
  for (int v = 0; v < n; v++) {
    int current = v;
    for (int i = 0; i < 60; i++) {
      if (k & (1LL << i)) {
        current = doubling.at(i).at(current);
      }
    }
    result.at(v) = current;
  }
  
  return result;
}

int main() {
  ll n,k;cin>>n>>k;
  vector<int> p(n);cin>>p;
  rep(i,n) p.at(i)--;
  vector<int> q(n);
  rep(i,n) q.at(p.at(i)) = i;
  auto ans = doubling(q,k);
  rep(i,n) {
    p.at(i) = ans.at(ans.at(i));
  }
  rep(i,n) {
    if(i) cout << " ";
    cout << ans.at(i)+1;
  }
  cout << endl;

  return 0;
}
