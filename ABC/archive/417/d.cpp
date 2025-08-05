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

int main() {
  int n;cin>>n;
  vector<int> p(n),a(n),b(n);
  rep(i,n) cin>>p.at(i)>>a.at(i)>>b.at(i);
  int m = 501;
  vector memo(n+1,vector<int>(m,-1));
  rep(j,m) memo.at(n).at(j) = j;
  for(int i=n-1;i>=0;i--) rep(j,m) {
    int x = j;
    reps(ii,i,n) {
      if(x<m&&memo.at(ii).at(x)!=-1) {
        memo.at(i).at(j) = memo.at(ii).at(x);
        break;
      }
      if(x<=p.at(ii)) x += a.at(ii);
      else x -= b.at(ii);
      x = max(x,0);
    }
    if(memo.at(i).at(j)==-1) memo.at(i).at(j) = x;
  }
  vector<int> pref(n+1,0);
  rep(i,n) pref.at(i+1) = pref.at(i)+b.at(i);
  int Q;cin>>Q;
  while(Q--) {
    int x;cin>>x;
    int ok = n+1;
    int ng = -1;
    while(abs(ok-ng)>1) {
      int mid = (ok+ng)/2;
      if(x-pref.at(mid)<m) ok = mid;
      else ng = mid;
    }
    if(ok==n+1) cout << x - pref.back() << endl;
    else cout << memo.at(ok).at(x-pref.at(ok)) << endl;
  }

  return 0;
}
