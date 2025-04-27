#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
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
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int n;cin>>n;
  vector<string> dp(2001,"");
  vector<int> mi(2001,INF);
  vector<bool> x(2001,false);
  dp.at(1) = "1";
  mi.at(1) = 1;
  x.at(1) = true;
  dp.at(11) = "11";
  mi.at(11) = 2;
  x.at(11) = true;
  dp.at(111) = "111";
  mi.at(111) = 3;
  x.at(111) = true;
  dp.at(1111) = "1111";
  mi.at(1111) = 4;
  x.at(1111) = true;
  mi.at(1) = 1;
  reps(i,2,2001) {
    reps(j,1,i) reps(k,j,i) {
      if(j+k==i) {
        if(chmin(mi.at(i),mi.at(j)+1+mi.at(k))) {
          dp.at(i) = dp.at(j) + "+" + dp.at(k);
          x.at(i) = false;
        }
      }
      if(j*k==i) {
        bool a = x.at(j);
        bool b = x.at(k);
        int cnt = 1;
        if(!a) cnt += 2;
        if(!b) cnt += 2;
        if(chmin(mi.at(i),mi.at(j)+cnt+mi.at(k))) {
          string s = dp.at(j);
          string t = dp.at(k);
          if(!a) s = "("+s+")";
          if(!b) t = "("+t+")";
          dp.at(i) = s+"*"+t;
          x.at(i) = true;
        }
      }
    }
  }
  cout << dp.at(n) << endl;

  return 0;
}
