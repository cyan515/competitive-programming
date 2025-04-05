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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
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

int main() {
  auto isp = eratosthenes(1000010);
  vector<ll> ps;
  rep(i,1000010) {
    if(isp.at(i)) ps.push_back(i);
  }
  vector<ll> pp(ps.size());
  rep(i,ps.size()) {
    pp.at(i) = ps.at(i)*ps.at(i);
  }
  vector<ll> ppp;
  rep(i,pp.size()) {
    ll x = 1;
    ll y = pp.at(i);
    while(1) {
      ll z;
      if(__builtin_mul_overflow(x,y,&z)) {
        break;
      }
      x = z;
      if(x>1000000000000LL) break;
      ppp.push_back(x);
    }
  }
  int Q;cin>>Q;
  int n = ppp.size();
  sort(all(ppp));
  vector<ll> can;
  rep(i,n) reps(j,i+1,n) {
    if(ppp.at(j)%ppp.at(i)==0) continue;
    ll z;
    if(__builtin_mul_overflow(ppp.at(i),ppp.at(j),&z)) {
      break;
    } else {
      if(z>1000000000000LL) break;
      can.push_back(z);
    }
  }
  sort(all(can));
  while(Q--) {
    ll a;cin>>a;
    auto it = upper_bound(all(can),a);
    it--;
    cout << *it << endl;
  }

  return 0;
}
