#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
void YN(bool b){cout<<(b?"Yes":"No")<<endl;}

int main() {
  int n;cin>>n;
  vector<ll> a(n),b(n);
  rep(i,n) cin>>a.at(i)>>b.at(i);
  vector<bool> flg(n,false);
  int bit = 0;
  vector memo(1<<n,vector<bool>(2,false));
  vector seen(1<<n,vector<bool>(2,false));
  auto f = [&](auto f, int t) -> bool {
    bool cont = false;
    rep(i,n) reps(j,i+1,n) {
      cont |= a.at(i)==a.at(j);
    }
    rep(i,n) reps(j,i+1,n) {
      cont |= b.at(i)==b.at(j);
    }
    if(!cont) {
      return t!=0;
    }
    if(seen.at(bit).at(t)) {
      return memo.at(bit).at(t);
    }
    bool ret;
    if(t==0) {
      ret = false;
      rep(i,n) reps(j,i+1,n) {
        if(bit&(1<<i)) continue;
        if(bit&(1<<j)) continue;
        if(a.at(i)==a.at(j)) {
          bit ^= 1<<i;
          bit ^= 1<<j;
          ret |= f(f,1);
          bit ^= 1<<i;
          bit ^= 1<<j;
        }
        if(b.at(i)==b.at(j)) {
          bit ^= 1<<i;
          bit ^= 1<<j;
          ret |= f(f,1);
          bit ^= 1<<i;
          bit ^= 1<<j;
        }
      }
    } else {
      ret = true;
      rep(i,n) reps(j,i+1,n) {
        if(bit&(1<<i)) continue;
        if(bit&(1<<j)) continue;
        if(a.at(i)==a.at(j)) {
          bit ^= 1<<i;
          bit ^= 1<<j;
          ret &= f(f,0);
          bit ^= 1<<i;
          bit ^= 1<<j;
        }
        if(b.at(i)==b.at(j)) {
          bit ^= 1<<i;
          bit ^= 1<<j;
          ret &= f(f,0);
          bit ^= 1<<i;
          bit ^= 1<<j;
        }
      }
    }
    seen.at(bit).at(t) = true;
    return memo.at(bit).at(t) = ret;
  };
  bool ans = f(f,0);
  if(ans) cout << "Takahashi" << endl;
  else cout << "Aoki" << endl;

  return 0;
}
