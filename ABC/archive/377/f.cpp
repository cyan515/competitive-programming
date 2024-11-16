#include <bits/stdc++.h>
#include <atcoder/segtree>
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
// #pragma GCC target("avx")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")


template< unsigned mod >
struct rolling_hash {
  vector< unsigned > hashed, power;
 
  inline unsigned mul(unsigned a, unsigned b) const {
    unsigned long long x = (unsigned long long) a * b;
    unsigned xh = (unsigned) (x >> 32), xl = (unsigned) x, d, m;
    asm("divl %4; \n\t" : "=a" (d), "=d" (m) : "d" (xh), "a" (xl), "r" (mod));
    return m;
  }

  rolling_hash(){
  }
 
  rolling_hash(const string &s, unsigned base = 10007) {
    int sz = (int) s.size();
    hashed.assign(sz + 1, 0);
    power.assign(sz + 1, 0);
    power[0] = 1;
    for(int i = 0; i < sz; i++) {
      power[i + 1] = mul(power[i], base);
      hashed[i + 1] = mul(hashed[i], base) + s[i];
      if(hashed[i + 1] >= mod) hashed[i + 1] -= mod;
    }
  }
 
  // 半開区間
  unsigned get(int l, int r) const {
    unsigned ret = hashed[r] + mod - mul(hashed[l], power[r - l]);
    if(ret >= mod) ret -= mod;
    return ret;
  }
 
  unsigned connect(unsigned h1, int h2, int h2len) const {
    unsigned ret = mul(h1, power[h2len]) + h2;
    if(ret >= mod) ret -= mod;
    return ret;
  }
 
  int LCP(const rolling_hash< mod > &b, int l1, int r1, int l2, int r2) {
    int len = min(r1 - l1, r2 - l2);
    int low = -1, high = len + 1;
    while(high - low > 1) {
      int mid = (low + high) / 2;
      if(get(l1, l1 + mid) == b.get(l2, l2 + mid)) low = mid;
      else high = mid;
    }
    return (low);
  }
};

using rolling_hash1 = rolling_hash< 998244353 >;
using rolling_hash2 = rolling_hash< 924844033 >;

// super rolling hash
struct SRH {
  rolling_hash1 rh;
  rolling_hash2 rh2;
  SRH(){}
  SRH(const string &s){
    rh =rolling_hash1(s);
    rh2 = rolling_hash2(s);
  }
  ll get(ll l, ll r){
    return rh.get(l,r) + 1e9 * rh2.get(l,r);
  }
};

int main() {
  int n;cin>>n;
  vector<string> s(n);cin>>s;
  map<ll,int> mp;
  rep(i,n) {
    string x = s.at(i);
    int m = x.size();
    int ans = m;
    SRH rh(x);
    rep(j,m+1) {
      auto it = mp.find(rh.get(0,j));
      if(it==mp.end()) continue;
      int len = (*it).second;
      chmin(ans,m-(int)j+len-(int)j);
    }
    rep(j,m+1) {
      auto it = mp.find(rh.get(0,j));
      if(it==mp.end()) mp[rh.get(0,j)] = m;
      else chmin(mp[rh.get(0,j)],m);
    }
    cout << ans << endl;
  }

  return 0;
}
