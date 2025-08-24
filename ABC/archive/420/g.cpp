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
  while((r+1)*(r+1)<=x)r++;
  return r;
}

int main() {
  ll x;cin>>x;
  set<ll> st;
  auto ok = [&](ll n) -> bool {
    ll y = n*n+n+x;
    ll z = sqr(y);
    return z*z==y;
  };
  reps(i,0,700001000) {
    ll a = x - i*i;
    ll b = 2*i - 1;
    if(abs(a)%abs(b)==0) {
      st.insert(a/b);
      ll n = a/b;
      reps(d,-10,10) if(ok(n+d)) st.insert(n+d);
      reps(d,-10,10) if(ok(-n+d)) st.insert(-n+d);
    }
  }
  vector<ll> ans;
  for(auto& ele : st) ans.push_back(ele);
  cout << ans.size() << endl;
  rep(i,ans.size()) {
    if(i) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;

  return 0;
}
