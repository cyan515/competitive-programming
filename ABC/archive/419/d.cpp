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
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  ll n,m;cin>>n>>m;
  string s,t;cin>>s>>t;
  vector<int> l(m),r(m);
  rep(i,m) cin>>l.at(i)>>r.at(i),l.at(i)--;
  vector<int> imos(n+1,0);
  rep(i,m) {
    imos.at(l.at(i))++;
    imos.at(r.at(i))--;
  }
  rep(i,n) imos.at(i+1) += imos.at(i);
  rep(i,n) imos.at(i) %= 2;
  rep(i,n) {
    if(imos.at(i)%2) cout << t.at(i);
    else cout << s.at(i);
  }
  cout << endl;

  return 0;
}
