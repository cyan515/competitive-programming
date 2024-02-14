#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T;cin>>T;
  while(T--) {
    int n,k;cin>>n>>k;
    bool ans = true;
    string s;cin>>s;
    map<char,int> mp;
    rep(i,n) mp[s.at(i)]++;
    int odd_cnt = 0;
    for(auto [k,v] : mp) {
      if(v%2!=0) odd_cnt++;
    }
    if(k<odd_cnt-1) ans=false;
    if(ans) cout << "Yes\n";
    else cout << "No\n";
  }

  exit(0);
}
