#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  ll n,q;cin>>n>>q;
  vector<ll> x(q);cin>>x;
  rep(i,q) x.at(i)--;
  vector<ll> ans(n,0);
  set<ll> st;
  vector<ll> memo(n,-1);
  vector<ll> cnt(q,0);
  vector inout(n,vector<pair<ll,ll>>());
  rep(i,q) {
    if(st.count(x.at(i))) {
      st.erase(x.at(i));
      inout.at(x.at(i)).push_back(pair(memo.at(x.at(i)),i));
      memo.at(x.at(i)) = -1;
    } else {
      st.insert(x.at(i));
      memo.at(x.at(i)) = i;
    }
    cnt.at(i) = st.size();
  }
  rep(i,q-1) cnt.at(i+1) += cnt.at(i);
  vector<ll> cnt2(q+1,0);
  rep(i,q) cnt2.at(i+1) = cnt.at(i);
  rep(i,n) {
    if(memo.at(i)!=-1) {
      inout.at(i).push_back(pair(memo.at(i),q));
    }
  }
  rep(i,n) {
    for(auto [in,out] : inout.at(i)) {
      ans.at(i) += cnt2.at(out)-cnt2.at(in);
    }
  }
  rep(i,n) {
    cout << ans.at(i);
    if(i==n-1) cout << endl;
    else cout << " ";
  }

  return 0;
}
