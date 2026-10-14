#include <bits/stdc++.h>
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

/**
 * @fn
 * ret[i][c] = s の i 文字目以降で最初に文字 c が登場する index となる二次元配列を返す。
 * 計算量 O(N)
 * 
 * @param s 文字列
 * @param base 基準となる文字。英大文字なら 'A' を、数字なら '0' を渡すなど。
 * @see https://qiita.com/drken/items/a207e5ae3ea2cf17f4bd
 */
vector<vector<int>> calc_next(const string& s, const char& base = 'a') {
  int n = s.size();
  vector<vector<int>> res(n+1,vector<int>(26,n));
  for(int i=n-1;i>=0;i--) {
    for(int j=0;j<26;j++) res.at(i).at(j) = res.at(i+1).at(j);
    res.at(i).at(s.at(i)-base) = i;
  }
  return res;
}

int main() {
  string s,t;cin>>s>>t;
  ll n=s.size();
  ll m=t.size();
  ll ans=(1+n)*n/2;
  auto nx=calc_next(s);
  rep(i,n){
    int cur=i;
    rep(j,m){
      cur=nx.at(cur).at(t.at(j)-'a');
      cur++;
      if(cur>n)break;
    }
    if(cur>n)continue;
    ans-=(n+1-cur);
  }
  cout<<ans<<endl;

  return 0;
}
