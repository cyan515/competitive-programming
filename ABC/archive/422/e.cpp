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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

std::random_device seed_gen;
std::mt19937 mt(seed_gen());

int main() {
  ll n;cin>>n;
  vector<ll> x(n),y(n);
  rep(i,n) cin>>x.at(i)>>y.at(i);
  rep(_i,100) {
    int i = abs((int)mt())%n;
    int j = abs((int)mt())%n;
    while(i==j) j = abs((int)mt())%n;
    ll s = x.at(i);
    ll t = y.at(i);
    ll u = x.at(j);
    ll v = y.at(j);
    ll a = t-v;
    ll b = u-s;
    ll c = v*s-u*t;
    int cnt = 0;
    rep(ii,n) {
      if(a*x.at(ii)+b*y.at(ii)+c==0) cnt++;
    }
    if(cnt>n/2) {
      cout << Yes << endl;
      cout << a << " " << b << " " << c << endl;
      return 0;
    }
  }
  cout << No << endl;

  return 0;
}
