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
  ll n,m,y;cin>>n>>m>>y;
  vector<ll> a(n);cin>>a;
  vector<ll> cand;
  rep(bit,1LL<<n) {
    if(__popcount(bit)!=m) continue;
    ll lcm = 1;
    rep(i,n) {
      if((bit&(1<<i))!=0) {
        ll g = gcd(lcm,a.at(i));
        ll z;
        bool of = __builtin_mul_overflow(lcm/g,a.at(i),&z);
        if(of) {
          lcm = -1;
          break;
        }
        lcm = z;
      }
    }
    if(lcm==-1) continue;
    bool ok = true;
    rep(i,n) {
      if((bit&(1<<i))!=0) continue;
      ok &= (lcm%a.at(i)!=0);
    }
    if(!ok) continue;
    if(lcm<=y) cand.push_back(lcm);
  }

  return 0;
}
