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
  ll n;cin>>n;
  string a;cin>>a;
  vector<string> hist;
  vector<vector<ll>> dp(n+1);
  auto f = [&](auto f,string& s) -> int {
    hist.push_back(s);
    if(s.size()==1) {
      return s=="1";
    }
    string t = "";
    rep(i,s.size()/3) {
      int cnt = 0;
      rep(j,3) cnt += s.at(3*i+j)=='1';
      if(cnt>=2) t += "1";
      else t += "0";
    }
    return f(f,t);
  };
  int x = f(f,a);
  if(x==0) {
    rep(i,n+1) rep(j,hist.at(i).size()) hist.at(i).at(j) = hist.at(i).at(j)=='1'?'0':'1';
  }
  rep(i,n+1) dp.at(i).resize(hist.at(i).size());
  rep(i,n+1) rep(j,dp.at(i).size()) dp.at(i).at(j) = 0;
  rep(i,dp.at(0).size()) if(hist.at(0).at(i)=='1') dp.at(0).at(i) = 1;
  reps(i,1,n+1) {
    rep(j,dp.at(i).size()) {
      if(hist.at(i).at(j)=='0') continue;
      int cnt = 0;
      vector<int> cost(3);
      rep(k,3) {
        if(hist.at(i-1).at(j*3+k)=='1') {
          cnt++;
          cost.at(k) = dp.at(i-1).at(j*3+k);
        } else cost.at(k) = INF;
      }
      ll sum = 0;
      sort(all(cost));
      if(cnt==3) {
        sum = cost.at(0)+cost.at(1);
      }
      if(cnt==2) {
        sum = cost.at(0);
      }
      dp.at(i).at(j) = sum;
    }
  }
  cout << dp.at(n).at(0) << endl;
  
  return 0;
}
