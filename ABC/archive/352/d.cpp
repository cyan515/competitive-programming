#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  ll n,k;cin>>n>>k;
  vector<ll> p(n);cin>>p;
  rep(i,n) p.at(i)--;
  vector<ll> a(n);
  rep(i,n) a.at(p.at(i))=i;
  set<ll> st;
  rep(i,k) st.insert(a.at(i));
  ll ans = LINF;
  reps(i,k,n) {
    chmin(ans,*st.rbegin()-*st.begin());
    st.erase(a.at(i-k));
    st.insert(a.at(i));
  }
  chmin(ans,*st.rbegin()-*st.begin());
  cout << ans << endl;

  return 0;
}
