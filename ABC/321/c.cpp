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
  int k;cin>>k;
  set<ll> q;
  string s = "";
  auto f = [&](auto f) -> void {
    char c = s.empty() ? '9'+1 : s.at(s.size()-1);
    rep(i,c-'0') {
      s += to_string(i);
      q.insert(stoll(s));
      f(f);
      s.pop_back();
    }
  };
  f(f);
  auto it = q.begin();
  rep(i,k) {
    it++;
  }
  cout << *it << endl;
  
  exit(0);
}
