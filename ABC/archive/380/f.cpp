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
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

map<int, long long> table;
mt19937_64 rng(time(0));
uniform_int_distribution<long long> dist(1, (1LL << 60) - 1);
  
int main() {
  int n,m,l;cin>>n>>m>>l;
  map<int,int> a,b,c;
  ll s = 0;
  ll t = 0;
  ll u = 0;
  rep(i,n) {
    int x;cin>>x;a[x]++;
    ll d = dist(rng);
    table[x] = d;
    s += d;
  }
  rep(i,m) {
    int x;cin>>x;b[x]++;
    ll d = dist(rng);
    table[x] = d;
    t += d;
  }
  rep(i,l) {
    int x;cin>>x;c[x]++;
    ll d = dist(rng);
    table[x] = d;
    u += d;
  }
  map<tuple<ll,ll,ll,int>,bool> memo;
  auto f = [&](auto ff,int T) -> bool {
    if(T==0 && a.empty()) {
      return memo[tuple(s,t,u,T)] = false;
    }
    if(T==1 && b.empty()) {
      return memo[tuple(s,t,u,T)] = true;
    }
    auto it = memo.find(tuple(s,t,u,T));
    if(it!=memo.end()) {
      return (*it).second;
    }
    bool ret;
    if(T==0) {
      ret = false;
      vector<int> op;
      for(auto [k,v]:a)op.push_back(k);
      vector<int> fi;
      for(auto [k,v]:c)fi.push_back(k);
      for(auto k:op) {
        if(--a[k]==0) a.erase(k);
        c[k]++;
        ll d = table.at(k);
        s -= d;
        u += d;
        ret |= ff(ff,1);
        for(auto kk:fi) {
          if(k<=kk) continue; 
          if(--c[kk]==0) c.erase(kk);
          a[kk]++;
          ll dd = table.at(kk);
          u -= dd;
          s += dd;
          ret |= ff(ff,1);
          u += dd;
          s -= dd;
          if(--a[kk]==0) a.erase(kk);
          c[kk]++;
        }
        s += d;
        u -= d;
        a[k]++;
        if(--c[k]==0) c.erase(k);
      }
    } else {
      ret = true;
      vector<int> op;
      for(auto [k,v]:b)op.push_back(k);
      vector<int> fi;
      for(auto [k,v]:c)fi.push_back(k);
      for(auto k:op) {
        if(--b[k]==0) b.erase(k);
        c[k]++;
        ll d = table.at(k);
        t -= d;
        u += d;
        ret &= ff(ff,0);
        for(auto kk:fi) {
          if(k<=kk) continue; 
          if(--c[kk]==0) c.erase(kk);
          b[kk]++;
          ll dd = table.at(kk);
          t += dd;
          u -= dd;
          ret &= ff(ff,0);
          t -= dd;
          u += dd;
          if(--b[kk]==0) b.erase(kk);
          c[kk]++;
        }
        t += d;
        u -= d;
        b[k]++;
        if(--c[k]==0) c.erase(k);
      }
    }
    return memo[tuple(s,t,u,T)] = ret;
  };
  if(f(f,0)) cout << "Takahashi" << endl;
  else cout << "Aoki" << endl;

  return 0;
}
