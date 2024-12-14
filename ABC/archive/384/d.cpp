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
  ll n;cin>>n;
  ll s;cin>>s;
  vector<ll> a(n);cin>>a;
  rep(i,n) a.push_back(a.at(i));
  ll sum = 0;
  rep(i,n) sum += a.at(i);
  s %= sum;
  vector<ll> pref(2*n+1);
  rep(i,n) {
    pref.at(i+1) = a.at(i);
    pref.at(n+i+1) = a.at(i);
  }
  rep(i,2*n) pref.at(i+1) += pref.at(i);
  set<ll> st;
  rep(i,2*n+1) st.insert(pref.at(i));
  rep(i,2*n+1) {
    if(st.count(pref.at(i)+s)) {
      cout << Yes << endl;
      return 0;
    }
  }
  cout << No << endl;

  return 0;
}
