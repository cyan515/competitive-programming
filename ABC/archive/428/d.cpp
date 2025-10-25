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

/**
 * @fn
 * 誤差のない sqrt
 * x が平方数でない場合、小数点以下は切り捨てる
 * 言い換えると、a**2 が x を超えない最大の a を返却する
 * @brief 平方根
 */
long long sqr(const long long& x) {
  long long r = sqrt(x)-2;
  while(r*r>x)r--;
  while((r+1)*(r+1)<=x)r++;
  return r;
}

int main() {
  int T;cin>>T;
  auto f = [](ll C,ll from,ll to) -> ll {
    ll x = stoll(to_string(C)+to_string(from));
    ll y = stoll(to_string(C)+to_string(to-1));
    ll xx = sqr(x-1);
    ll yy = sqr(y);
    return yy-xx;
  };
  while(T--) {
    ll c,d;cin>>c>>d;
    ll ans = 0;
    ll be = c+1;
    ll en = c+d;
    if(to_string(be).size()==to_string(en).size()) {
      ans += f(c,be,en+1);
    } else {
      ll base = 1;
      while(base<be) base *= 10;
      ans += f(c,be,base);
      while(base*10<=en) {
        ans += f(c,base,base*10);
        base *= 10;
      }
      ans += f(c,base,en+1);
    }
    cout << ans << endl;
  }

  return 0;
}
