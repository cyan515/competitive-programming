#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/fenwicktree>
using mint=atcoder::modint998244353;
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
  int n,m;cin>>n>>m;
  vector<int>x(m),y(m);
  rep(i,m)cin>>x.at(i)>>y.at(i);
  rep(i,m)x.at(i)--,y.at(i)--;
  map<int,vector<int>>mp;
  rep(i,m)mp[y.at(i)].push_back(x.at(i));
  atcoder::fenwick_tree<mint>dp(n+1);
  dp.add(0,1);
  rep(i,n){
    for(auto ele:mp[i]){
      dp.add(i,dp.sum(0,ele));
    }
  }
  cout<<dp.sum(n-1,n).val()<<endl;

  return 0;
}
