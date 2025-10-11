#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using mint = modint;
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

#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
int main() {ios::sync_with_stdio(false);
std::cin.tie(nullptr);
  int n,m;cin>>n>>m;
  vector<ll> a(n);cin>>a;
  // ll cnt = 0;
  // auto f = [&](auto self,int v) -> void {
  //   if(v>=n) {
  //     cnt++;
  //     return;
  //   }
  //   self(self,v+1);
  //   cur.push_back(v);
  //   self(self,v+2);
  //   cur.pop_back();
  // };
  // f(f,0);
  // cout << cnt << endl;
  mint::set_mod(m);
  if(n<10) {
    ll ans = 0;
    rep(bit,1<<n) {
      bool ok = true;
      rep(i,n-1) {
        if((bit&(1<<i))!=0 && (bit&(1<<(i+1)))!=0) ok = false;
      }
      if(!ok) continue;
      mint sum = 0;
      rep(i,n) {
        if((bit&(1<<i))!=0) sum += a.at(i);
      }
      if(sum==0) ans++;
    }
    cout << ans << endl;
  } else {
    vector<ll> b;
    rep(i,n/2) {
      b.push_back(a.back());
      a.pop_back();
    }
    reverse(all(b));
    // 末尾選んだ / 選んでない
    unordered_map<int,ll> ax,ay;
    // 先頭選んだ / 選んでない
    unordered_map<int,ll> bx,by;
    
    vector<int> cur;
    // true なら a
    bool flag;
    auto f = [&](auto self,int v,int lim) -> void {
      if(v>=lim) {
        if(flag) {
          // a
          mint as = 0;
          bool matsubi = false;
          for(auto idx : cur) {
            matsubi |= idx == a.size()-1;
            as += a.at(idx);
          }
          if(matsubi) ax[as.val()]++;
          else ay[as.val()]++;
        } else {
          // b
          mint bs = 0;
          bool sentou = false;
          for(auto idx : cur) {
            sentou |= idx == 0;
            bs += b.at(idx);
          }
          if(sentou) bx[bs.val()]++;
          else by[bs.val()]++;
        }
        return;
      }
      self(self,v+1,lim);
      cur.push_back(v);
      self(self,v+2,lim);
      cur.pop_back();
    };
    flag = true;
    f(f,0,(int)a.size());
    flag = false;
    f(f,0,(int)b.size());
    ll ans = 0;
    for(auto [k,v] : ax) {
      ans += by[(mint(m) - k).val()] * v;
    }
    for(auto [k,v] : ay) {
      ans += bx[(mint(m)-k).val()] * v;
      ans += by[(mint(m)-k).val()] * v;
    }
    cout << ans << endl;
  }

  return 0;
}
