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

int main() {
  int n;cin>>n;
  vector<string> s(n);cin>>s;
  vector in(n,vector(26,vector<int>()));
  vector out(n,vector(26,vector<int>()));
  rep(i,n) rep(j,n) {
    if(s.at(i).at(j)=='-') continue;
    out.at(i).at(s.at(i).at(j)-'a').push_back(j);
    in.at(j).at(s.at(i).at(j)-'a').push_back(i);
  }
  vector dist(n,vector(n,INF));
  deque<pair<int,int>> q;
  rep(i,n) rep(j,n) {
    if(i==j) {
      q.push_front(pair(i,j));
      dist.at(i).at(j) = 0;
    } else if(s.at(i).at(j)!='-') {
      q.push_back(pair(i,j));
      dist.at(i).at(j) = 1;
    }
  }
  while(q.size()) {
    auto [vi,vj] = q.front();q.pop_front();
    rep(c,26) {
      for(auto ni : in.at(vi).at(c)) {
        for(auto nj : out.at(vj).at(c)) {
          if(dist.at(ni).at(nj)!=INF) continue;
          dist.at(ni).at(nj) = dist.at(vi).at(vj) + 2;
          q.push_back(pair(ni,nj));
        }
      }
    }
  }
  rep(i,n) {
    rep(j,n) {
      if(j) cout << " ";
      int ans = dist.at(i).at(j);
      if(ans==INF) ans = -1;
      cout << ans;
    }
    cout << endl;
  }

  return 0;
}
