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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

string convert_base(int _N, int BASE) {
  // 答えを求める
  string ans = "";
  if (_N == 0LL) {
    // S == 0 のみ、例外処理
    ans = "0";
  } else {
    // そうでない場合、下の位から桁を決定する
    while (_N > 0) {
      char c = '0' + (_N % BASE);
      ans += c;
      _N /= BASE;
    }
    // 答え ans を反転させる
    reverse(ans.begin(), ans.end());
  }
  return ans;
}
int binaryToDecimal(string S) {
  int len = S.length();
  long long ret = 0;
  for(int i=0;i<len;i++) {
    ret *= 2L;
    if(S.at(i)=='1') ret++;
  }
  return ret;
}
int main() {
  int n;cin>>n;
  string str = convert_base(n-1,2);
  int len = str.size();
  cout << len << endl;
  vector ask(8,vector<int>());
  rep(i,n) {
    rep(j,8) if((i+1) & (1<<j)) ask.at(j).push_back(i+1);
  }
  rep(i,len) {
    cout << ask.at(i).size() << " ";
    rep(j,ask.at(i).size()) {
      cout << ask.at(i).at(j);
      if(j==ask.at(i).size()-1) cout << endl;
      else cout << " ";
    }
  }
  string ret;cin>>ret;
  reverse(all(ret));
  int ans = binaryToDecimal(ret);
  if(ans==0) ans=n;
  cout << ans << endl;

  exit(0);
}
