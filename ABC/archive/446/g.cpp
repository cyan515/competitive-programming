#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;
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
  ll n;cin>>n;
  vector<ll>a(n);cin>>a;
  vector ids(500010,vector<int>());
  vector<int>pos(n,0);
  rep(i,n)pos.at(i)=ids.at(a.at(i)).size(),ids.at(a.at(i)).push_back(i);
  fenwick_tree<mint> ft(n+1);
  ft.add(0,1);
  rep(i,n) {
    if(pos.at(i)-a.at(i)<-1) continue;
    if(pos.at(i)-a.at(i)==-1) {
      
    } else {
      
    }
  }
  cout<<ft.sum(1,n+1).val()<<endl;
  
  return 0;
}
