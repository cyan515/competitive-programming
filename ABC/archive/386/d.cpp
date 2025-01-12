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
  ll n,m;cin>>n>>m;
  vector<ll> x(m),y(m);
  vector<char> c(m);
  rep(i,m) cin>>x.at(i)>>y.at(i)>>c.at(i);
  vector<int> ord(m);
  rep(i,m) ord.at(i) = i;
  sort(all(ord),[&](int ii,int jj) -> bool {
    if(x.at(ii)!=x.at(jj)) return x.at(ii)<x.at(jj);
    else return c.at(jj)<c.at(ii);
  });
  int right = n;
  for(auto o:ord) {
    int yy = y.at(o);
    char cc = c.at(o);
    if(cc=='B') {
      if(yy>right) {
        cout << No << endl;
        return 0;
      }
    } else {
      chmin(right,yy-1);
    }
  }
  cout << Yes << endl;

  return 0;
}
