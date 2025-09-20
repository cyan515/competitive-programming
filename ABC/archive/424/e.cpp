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

int main() {
  int T;cin>>T;
  while(T--) {
    ll n,k,x;cin>>n>>k>>x;
    vector<ll> a(n);cin>>a;
    sort(a.rbegin(),a.rend());
    vector<ll> cnt(n,1);
    priority_queue<pair<long double,int>> q;
    rep(i,n) q.push(pair(a.at(i),i));
    ll cur = 0;
    while(cur<k) {
      auto [len,idx] = q.top();q.pop();
      if(cur+cnt.at(idx)<=k) {
        cur += cnt.at(idx);
        cnt.at(idx) *= 2;
        q.push(pair(len/2,idx));
      } else {
        ll rest = k - cur;
        a.push_back(a.at(idx));
        cnt.push_back(rest*2);
        cnt.at(idx) -= rest;
      }
    }
    ll sum = 0;
    vector<int> ord(a.size());
    rep(i,a.size()) ord.at(i) = i;
    sort(all(ord),[&](int i,int j) -> bool {
      return (long double)a.at(i)/cnt.at(i) > (long double)a.at(j)/cnt.at(j); 
    });
    
  }

  return 0;
}
