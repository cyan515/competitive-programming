#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n;cin>>n;
  string s;cin>>s;
  sort(all(s));
  reverse(all(s));
  ll ma = stoll(s);
  map<char,int> mp;
  rep(i,n) mp[s.at(i)]++;
  ll ans = 0;
  for(ll i=0;i*i<=ma;i++) {
    string t = to_string(i*i);
    int len = t.length();
    map<char,int> cnt;
    rep(j,len) cnt[t.at(j)]++;
    bool ok = mp['0'] >= cnt['0'];
    reps(j,1,10) {
      ok &= mp['0'+j] == cnt['0'+j];
    }
    if(ok) ans++;
  }
  cout << ans << endl;

  exit(0);
}
