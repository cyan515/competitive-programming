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

class ZobristHash {
public:
    ZobristHash(int numElements) {
        mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
        hashValues.resize(numElements);
        for (auto& hv : hashValues) {
            hv = rng();
        }
        currentHash = 0;
    }

    void addElement(int element) {
        currentHash ^= hashValues[element];
    }

    ll getCurrentHash() const {
        return currentHash;
    }

private:
    vector<ll> hashValues;
    ll currentHash;
};

int main() {
  ll n,m;cin>>n>>m;
  ZobristHash zh(n);
  map<ll,vector<ll>> mp;
  rep(i,m) {
    ll t,p;cin>>t>>p;p--;
    zh.addElement(p);
    mp[zh.getCurrentHash()].push_back(t);
  }
  int Q;cin>>Q;
  while(Q--) {
    ll a,b;cin>>a>>b;a--;b--;
    zh.addElement(a);
    zh.addElement(b);
    ll h = zh.getCurrentHash();
    zh.addElement(a);
    zh.addElement(b);
  }

  return 0;
}
