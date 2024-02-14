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

string toBinary(int n) {
  string r = "";
  while (n != 0){
    if(n%5==0) r+="0";
    else if(n%5==1) r+="1";
    else if(n%5==2) r+="2";
    else if(n%5==3) r+="3";
    else if(n%5==4) r+="4";
    n /= 5;
  }
  return r;
}

int main() {
  ll n;cin>>n;n--;
  
  // 答えを求める
  string ans = "";
  if (n == 0LL) {
      // S == 0 のみ、例外処理
      ans = "0";
  } else {
      // そうでない場合、下の位から桁を決定する
      while (n > 0) {
          char c = '0' + (n % 5);
          ans += c;
          n /= 5;
      }
      // 答え ans を反転させる
      reverse(ans.begin(), ans.end());
  }
  
  rep(i,ans.size()) {
    ans.at(i) = '0' + (ans.at(i)-'0')*2;
  }
  
  cout << ans << endl;

  exit(0);
}
