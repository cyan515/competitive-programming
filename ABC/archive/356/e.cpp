#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
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

int main() {
  ll n;cin>>n;
  vector<ll> a(n);cin>>a;
  sort(all(a));
  fenwick_tree<ll> f(1000010);
  rep(i,n) f.add(a.at(i),1);
  ll ans = 0;
  vector<ll> memo(1000010,-1);
  rep(i,n-1) {
    ans += f.sum(a.at(i)+1,1000010);
    ans += f.sum(a.at(i),a.at(i)+1)-1;
    f.add(a.at(i),-1);
    if(memo.at(a.at(i))!=-1) {
      ans += memo.at(a.at(i));
      continue;
    }
    ll x = 2;
    ll sum = 0;
    while(a.at(i)*x<=a.back()) {
      sum += f.sum(a.at(i)*x,1000010);
      x++;
    }
    ans += sum;
    memo.at(a.at(i)) = sum;
  }
  cout << ans << endl;

  return 0;
}
