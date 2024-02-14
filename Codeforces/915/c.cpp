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

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T;cin>>T;
  while(T--) {
    int n;cin>>n;
    string s;cin>>s;
    {
      string ss = s;
      sort(all(ss));
      if(ss==s) {
        cout << 0 << endl;
        continue;
      }
    }
    string t = "";
    t += s.at(n-1);
    bool flg = true;
    vector<bool> fixed(n,false);
    for(int i=n-2;i>=0;i--) {
      if(t.back()<=s.at(i)) {
        t.push_back(s.at(i));
      } else {
        fixed.at(i) = true;
      }
    }
    {
      string ss = "";
      rep(i,n) if(fixed.at(i)) ss+=s.at(i);
      string sss = ss;
      sort(all(sss));
      if(sss!=ss) {
        cout << -1 << endl;
        continue;
      }
    }
    {
      string ss = s;
      sort(all(ss));
      rep(i,n) {
        if(fixed.at(i) && s.at(i)!=ss.at(i)) {
          flg = false;
        }
      }
    }
    vector<int> cnt(26,0);
    rep(i,n) {
      if(fixed.at(i)) continue;WK
      cnt.at(s.at(i)-'a')++;
    }
    
    while(flg && t.size()>=2 && t.back()==t.at(t.size()-2)) t.pop_back();
    
    if(flg) cout << t.size() -1 << endl;
    else cout << -1 << endl;
  }

  exit(0);
}
