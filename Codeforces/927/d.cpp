#include <bits/stdc++.h>

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
  cin.tie(0) -> sync_with_stdio(0);
  int T;cin>>T;
  while(T--) {
    int n;cin>>n;
    char t;cin>>t;
    vector<string> s(2*n);
    rep(i,2*n) cin>>s.at(i);
    rep(i,2*n) swap(s.at(i).at(0),s.at(i).at(1));
    vector<string> a,b;
    rep(i,2*n) {
      if(s.at(i).at(0)==t) {
        a.push_back(s.at(i));
      } else {
        b.push_back(s.at(i));
      }
    }
    sort(all(a));
    sort(all(b));
    int ai = 0;
    vector<pair<string,string>> ans;
    bool flg = true;
    rep(i,b.size()) {
      pair<string,string> p;
      p.first = b.at(i);
      if(i!=b.size()-1&&b.at(i).at(0)==b.at(i+1).at(0)) {
        p.second = b.at(i+1);
        i++;
      } else {
        if(ai>=a.size()) {
          flg = false;
          break;
        }
        p.second = a.at(ai++);
      }
      ans.push_back(p);
    }
    if(!flg) {
      cout << "IMPOSSIBLE\n";
      continue;
    }
    while(ai<a.size()) {
      ans.emplace_back(a.at(ai),a.at(ai+1));
      ai+=2;
    }
    rep(i,n) {
      swap(ans.at(i).first.at(0),ans.at(i).first.at(1));
      swap(ans.at(i).second.at(0),ans.at(i).second.at(1));
    }
    rep(i,n) {
      cout << ans.at(i).first << " " << ans.at(i).second;
      if(i==n-1) cout << endl;
      else cout << "\n";
    }
    
  }

  exit(0);
}
