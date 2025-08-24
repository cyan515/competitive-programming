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
  int n,m,k;cin>>n>>m>>k;
  vector<string> s(n);cin>>s;
  if(n>m) {
    vector<string> ss(m,"");
    rep(j,m) rep(i,n) ss.at(j).push_back(s.at(i).at(j));
    swap(s,ss);
    swap(n,m);
  }
  vector x(n,vector<int>());
  rep(i,n) {
    rep(j,m) {
      if(s.at(i).at(j)=='#') x.at(i).push_back(j);
    }
  }
  rep(i,n) reps(j,i,n) {
    
  }

  return 0;
}
