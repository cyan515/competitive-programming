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

vector<vector<int>> calcNext(const string &S) {
    int n = (int)S.size();
    vector<vector<int> > res(n + 1, vector<int>(26, n));
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) res[i][j] = res[i + 1][j];
        res[i][S[i] - 'a'] = i;
    }
    return res;
}

ll solve1(int n,string& t,vector<string>& ss) {
  
  vector<vector<int>> l = calcNext(t);
  reverse(all(t));
  vector<vector<int>> r = calcNext(t);
  rep(i,n) rep(j,26) r.at(i).at(j) = n-1-r.at(i).at(j);
  vector<int> ma(n);
  vector<int> mi(n);
  rep(i,n) {
    string s = ss.at(i);
    int idx = 0;
    rep(j,s.size()) {
      int c = s.at(j)-'a';
      idx = l.at(idx).at(c);
    }
    ma.at(i) = idx;
    idx = n-1;
    rep(j,s.size()) {
      int c = s.at(s.size()-1-j)-'a';
      idx = l.at(idx).at(c);
    }
    mi.at(i) = idx;
  }
  sort(all(mi));
  sort(all(ma));
  ll ans = 0;
  rep(i,n) {
    ans += upper_bound(all(mi),ma.at(i)) - mi.end();
  }
  return ans;
}

ll solve2(int n,string& t,vector<string>& ss) {
  
  ll ans = 0;
  rep(i,n) rep(j,n) {
    string s = ss.at(i) + ss.at(j);
    rep(k,s.size()) {
      string u = s.substr(k,t.size());
      if(u==t) {
        ans++;
        i=j=n;
        k=s.size();
      }
    }
  }
  return ans;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n;cin>>n;
  string t;cin>>t;
  vector<string> ss(n,"");
  rep(i,n) cin>>ss.at(i);
  rep(i,100) {
    n=3;
    ss.resize(0);
    ss.resize(n);
    t = "";
    rep(j,n) {
      t += 'a' + rand()%3;
      rep(k,10) ss.at(j) += 'a' + rand()%3;
    }
    ll ans1 = solve1(n,t,ss);
    ll ans2 = solve2(n,t,ss);
    if(ans1!=ans2) {
      cout << "error " << ans1 << " " << ans2 << endl;
    }
  }
  
  exit(0);
}
