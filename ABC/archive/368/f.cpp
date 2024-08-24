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

int mex(const vector<int>& g_values) {
    int n = g_values.size();
    vector<bool> seen(n + 1, false);
    for (int g : g_values) {
        if (g <= n) seen[g] = true;
    }
    for (int i = 0; i <= n; ++i) {
        if (!seen[i]) return i;
    }
    return n;
}

int grundy(int n) {
    if (n < 2) return 0;
    vector<int> g_values;
    for (int i = 1; i < n; ++i) {
        g_values.push_back(grundy(i));
    }
    return mex(g_values);
}

int main() {
  ll n;cin>>n;
  vector<ll> a(n);cin>>a;
  vector<ll> b(n,0);
  rep(i,n) {
    map<ll,ll> mp;
    for(ll j=2;j*j<=a.at(i);j++) {
      while(a.at(i)%j==0) {
        mp[j]++;
        a.at(i)/=j;
      }
    }
    if(a.at(i)!=1) mp[a.at(i)]++;
    ll cnt = 0;
    for(auto [k,v] : mp) {
      cnt += v;
    }
    b.at(i) = cnt;
  }
  ll s = 0;
  rep(i,n) {
    s ^= b.at(i);
  }
  
  if(s!=0) cout << "Anna" << endl;
  else cout << "Bruno" << endl;

  return 0;
}
