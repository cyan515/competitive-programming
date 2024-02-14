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
  string s,t;cin>>s>>t;
  sort(all(s));
  sort(all(t));
  auto f = [](string str) -> int {
    int ret = 0;
    if(str=="AB"||str=="BC"||str=="CD"||str=="DE"||str=="AE") ret = 1;
    if(str=="AC"||str=="AD"||str=="BD"||str=="BE"||str=="CE") ret = 2;
    return ret;
  };
  int sl = f(s);
  int tl = f(t);
  if(sl==tl) cout << "Yes" << endl;
  else cout << "No" << endl;

  exit(0);
}
