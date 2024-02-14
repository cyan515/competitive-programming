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

vector<vector<int> > calc_next(const string &S) {
    int n = (int)S.size();
    vector<vector<int> > res(n+1, vector<int>(26, n));
    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) res[i][j] = res[i+1][j];
        res[i][S[i]-'a'] = i;
    }
    return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T;cin>>T;
  while(T--) {
    int n,k,m;cin>>n>>k>>m;
    string s;cin>>s;
    auto nxt = calc_next(s);
    string fl = "";
    vector ok(m,INF);
    auto dfs = [&](int idx,int cnt,auto dfs) -> string {
      if(idx==m) {
        return fl;
      }
      if(cnt==n) {
        ok.at(idx) = min(ok.at(idx),cnt);
        return "";
      }
      if(ok.at(idx)<=cnt) return "";
      string ret;
      rep(i,k) {
        fl.push_back('a'+i);
        ret = dfs(nxt.at(idx+1).at(i),cnt+1,dfs);
        fl.pop_back();
        if(ret.size()!=0) return ret;
      }
      ok.at(idx) = min(ok.at(idx),cnt);
      return "";
    };
    string ans;
    rep(i,k) {
      fl.push_back('a'+i);
      ans = dfs(nxt.at(0).at(i),1,dfs);
      fl.pop_back();
      if(ans.size()!=0) break;
    }
    if(ans.size()==0) cout << "YES" << endl;
    else {
      while(ans.size()<n) ans+='a';
      cout << "NO" << endl << ans << endl;
    }
  }

  exit(0);
}
