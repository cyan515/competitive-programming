#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
const string Yes = "Yes";
const string No = "No";
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int D = 63;
// 10進数表現の整数を受け取って BASE 進数に変換して返す
string convert_base(const long long n, const int base=2) {
  string ret = "";
  long long cur = n;
  if (cur == 0LL) {
    ret = "0";
  } else {
    while (cur > 0) {
      char c = '0' + (cur % base);
      ret += c;
      cur /= base;
    }
    reverse(ret.begin(), ret.end());
  }
  if(ret.size()<D) {
    string pref = string(D-ret.size(),'0');
    ret = pref + ret;
  }
  return ret;
}

int main() {
  int Q;cin>>Q;
  while(Q--) {
    ll n;cin>>n;
    int x;cin>>x;
    mint ans = 0;
    string s = convert_base(n);
    reps(dig,1,D) {
      vector dp(D,vector(2,vector<mint>(x+1,0)));
      dp.at(0).at(1).at(0) = 1;
      rep(i,D-1) rep(j,x+1) {
        if(i+1==dig) {
          if(j!=x) dp.at(i+1).at(0).at(j+1) += dp.at(i).at(0).at(j);
          if(s.at(i+1)=='1') {
            if(j!=x) dp.at(i+1).at(1).at(j+1) += dp.at(i).at(1).at(j);
          } else {
          }
        } else {
          dp.at(i+1).at(0).at(j) += dp.at(i).at(0).at(j);
          if(j!=x) dp.at(i+1).at(0).at(j+1) += dp.at(i).at(0).at(j);
          if(s.at(i+1)=='1') {
            dp.at(i+1).at(0).at(j) += dp.at(i).at(1).at(j);
            if(j!=x) dp.at(i+1).at(1).at(j+1) += dp.at(i).at(1).at(j);
          } else {
            dp.at(i+1).at(1).at(j) += dp.at(i).at(1).at(j);
          }
        }
      }
      mint cnt = mint(2).pow(D-dig-1);
      cnt *= (dp.at(D-1).at(0).at(x)+dp.at(D-1).at(1).at(x));
      ans += cnt;
    }
    cout << ans.val() << endl;
  }

  return 0;
}
