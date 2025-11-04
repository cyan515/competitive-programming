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


/// @see https://ei1333.github.io/luzhiled/snippets/string/rolling-hash.html
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
 
  rolling_hash(const vector<int> &a, unsigned base = 10007) {
    int sz = (int) a.size();
    hashed.assign(sz + 1, 0);
    power.assign(sz + 1, 0);
    power[0] = 1;
    for(int i = 0; i < sz; i++) {
      power[i + 1] = mul(power[i], base);
      hashed[i + 1] = mul(hashed[i], base) + a[i];
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

struct multi_rolling_hash {

  multi_rolling_hash(const string &s, unsigned base1 = 10007, unsigned base2 = 9973) {
    rh1 = rolling_hash<1000000007>(s, base1);
    rh2 = rolling_hash<1000000009>(s, base2);
  }

  multi_rolling_hash(const vector<int> &a, unsigned base1 = 10007, unsigned base2 = 9973) {
    rh1 = rolling_hash<1000000007>(a, base1);
    rh2 = rolling_hash<1000000009>(a, base2);
  }

  // 半開区間
  pair<unsigned,unsigned> get(int l, int r) const {
    return pair(rh1.get(l, r), rh2.get(l, r));
  }

private:
  rolling_hash<1000000007> rh1;
  rolling_hash<1000000009> rh2;
};

int main() {
  int T;cin>>T;
  while(T--) {
    string s,t;cin>>s>>t;
    int n = s.size();
    s += s;
    multi_rolling_hash a(s),b(t);
    int ans = -1;
    rep(i,n) {
      if(a.get(i,i+n)==b.get(0,n)) {
        ans = i;
        break;
      }
    }
    cout << ans << endl;
  }

  return 0;
}
