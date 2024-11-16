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
  int T;cin>>T;
  while(T--) {
    int n,k;cin>>n>>k;
    vector<pair<ll,ll>> ab(n);
    rep(i,n) cin>>ab.at(i).first;
    rep(i,n) cin>>ab.at(i).second;
    sort(all(ab));
    vector<ll> a(n),b(n);
    rep(i,n) {
      a.at(i) = ab.at(i).first;
      b.at(i) = ab.at(i).second;
    }
    multiset<ll> st;
    ll sum = 0;
    rep(i,k) {
      st.insert(b.at(i));
      sum+=b.at(i);
    }
    ll ans = a.at(k-1)*sum;
    reps(i,k,n) {
      sum += b.at(i);
      auto it = st.end();
      it--;
      sum -= *it;
      st.erase(it);
      st.insert(b.at(i));
      chmin(ans,a.at(i)*sum);
    }
    cout << ans << endl;
  }

  return 0;
}
