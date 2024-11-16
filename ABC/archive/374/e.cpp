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

int main() {
  ll n,x;cin>>n>>x;
  vector<ll> a(n),p(n),b(n),q(n);
  rep(i,n) cin>>a.at(i)>>p.at(i)>>b.at(i)>>q.at(i);
  ll ok = 0;
  ll ng = INF;
  while(abs(ok-ng)>1) {
    ll mid = (ok+ng)/2;
    ll sum = 0;
    bool flg = true;
    rep(i,n) {
      ll mi = LINF;
      ll ac = (mid+a.at(i)-1)/a.at(i);
      chmin(mi,ac*p.at(i));
      reps(aa,max(0LL,ac-1000LL),ac+1) {
        ll r = mid-aa*a.at(i);
        if(r<0) continue;
        ll bb = (r+b.at(i)-1)/b.at(i);
        chmin(mi,aa*p.at(i)+bb*q.at(i));
      }
      ll bc = (mid+b.at(i)-1)/b.at(i);
      chmin(mi,bc*q.at(i));
      reps(bb,max(0LL,bc-1000LL),bc+1) {
        ll r = mid-bb*b.at(i);
        if(r<0) continue;
        ll aa = (r+a.at(i)-1)/a.at(i);
        chmin(mi,aa*p.at(i)+bb*q.at(i));
      }
      sum += mi;
      if(sum>x) {
        flg = false;
        break;
      }
    }
    if(!flg) {
      ng = mid;
      continue;
    }
    if(sum>x) ng = mid;
    else ok = mid;
  }
  cout << ok << endl;

  return 0;
}
