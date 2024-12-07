#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
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

vector<bool> eratosthenes(const int& n) {
  vector<bool> isprime(n+1, true);
  isprime[0] = isprime[1] = false;
  for (int p = 2; p <= n; ++p) {
    if (!isprime[p]) continue;
    for (int q = p * 2; q <= n; q += p) {
      isprime[q] = false;
    }
  }
  return isprime;
}
long long sqr(const long long& x) {
  long long r = sqrt(x)-2;
  while((r+1)*(r+1)<=x)r++;
  return r;
}

int main() {
  ll n;cin>>n;
  int ans = 0;
  auto e = eratosthenes(sqr(n)+10);
  vector<ll> p;
  rep(i,e.size()) {
    if(e.at(i)) p.push_back(i);
  }
  int m = p.size();
  rep(i,m) reps(j,i+1,m) {
    ll x = p.at(i)*p.at(j);
    ll z;
    bool ov = __builtin_mul_overflow(x,x,&z);
    if(ov) break;
    if(z>n) break;
    ans++;
  }
  rep(i,p.size()) {
    ll x = p.at(i);
    x *= x;
    x *= x;
    x *= x;
    if(x>n) break;
    ans++;
  }
  cout << ans << endl;

  return 0;
}
