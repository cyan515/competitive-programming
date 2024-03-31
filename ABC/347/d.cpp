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
string convert_base(ll _N, int BASE) {
  string RET = "";
  if (_N == 0LL) {
    RET = "0";
  } else {
    while (_N > 0) {
      char c = '0' + (_N % BASE);
      RET += c;
      _N /= BASE;
    }
    reverse(RET.begin(), RET.end());
  }
  return RET;
}
long long binary_to_decimal(string S) {
  int len = S.length();
  long long ret = 0;
  for(int i=0;i<len;i++) {
    ret *= 2LL;
    if(S.at(i)=='1') ret++;
  }
  return ret;
}
int main() {
  ll a,b,c;cin>>a>>b>>c;
  string s = convert_base(c,2);
  while(s.size()<60) s = "0"+s;
  ll lim = 1L<<60;
  int n = s.size();
  reverse(all(s));
  vector<int> x(n,-1);
  vector<int> y(n,-1);
  rep(i,n) {
    if(s.at(i)=='0') continue;
    if(a>b) {
      x.at(i) = 1;
      y.at(i) = 0;
      a--;
      if(a<0) {
        cout << -1 << endl;
        return 0;
      }
    } else {
      x.at(i) = 0;
      y.at(i) = 1;
      b--;
      if(b<0) {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  if(a!=b) {
    cout << -1 << endl;
  } else {
    rep(i,n) {
      if(x.at(i)==-1) {
        if(a>0) {
          x.at(i) = 1;
          y.at(i) = 1;
          a--;
        } else {
          x.at(i) = 0;
          y.at(i) = 0;
        }
      }
    }
    string ax = "";
    string ay = "";
    rep(i,n) {
      ax += to_string(x.at(i));
      ay += to_string(y.at(i));
    }
    reverse(all(ax));
    reverse(all(ay));
    ll ansx = binary_to_decimal(ax);
    ll ansy = binary_to_decimal(ay);
    
    if(ansx<lim && ansy<lim && a==0) cout << ansx << " " << ansy << endl;
    else cout << -1 << endl;
  }

  return 0;
}
