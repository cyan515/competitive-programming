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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
void YN(bool b){cout<<(b?"Yes":"No")<<endl;}

int main() {
  ll n;cin>>n;
  vector<tuple<ll,ll,ll>> ac(n);
  rep(i,n) {
    ll a,c;cin>>a>>c;
    ac.at(i) = tuple(a,c,i);
  }
  sort(ac.rbegin(),ac.rend());
  auto [mi,ma,lst] = ac.front();
  vector<ll> ans;
  ans.push_back(lst);
  reps(i,1,n) {
    auto [a,c,idx] = ac.at(i);
    if(ma<c) continue;
    ma = min(ma,c);
    ans.push_back(idx);
  }
  cout << ans.size() << endl;
  sort(all(ans));
  rep(i,ans.size()) {
    if(i) cout << " ";
    cout << ans.at(i)+1;
  }
  cout << endl;
  
  return 0;
}
