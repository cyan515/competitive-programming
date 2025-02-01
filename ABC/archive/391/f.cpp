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
class Timer {
    public:
    void start() {
        origin = rdtsc();
    }
    
    inline double get_time() {
        return (rdtsc() - origin) * SECONDS_PER_CLOCK;
    }
    
    private:
    constexpr static double SECONDS_PER_CLOCK = 1 / 3.0e9;
    unsigned long long origin;
    
    inline static unsigned long long rdtsc() {
        unsigned long long lo, hi;
        __asm__ volatile ("rdtsc" : "=a" (lo), "=d" (hi));
        return (hi << 32) | lo;
    }
};

int main() {
  Timer timer;
  timer.start();
  ll n,k;cin>>n>>k;
  vector<ll> a(n),b(n),c(n);
  cin>>a>>b>>c;
  sort(rall(a));
  sort(rall(b));
  sort(rall(c));
  priority_queue<tuple<ll,int,int,int>> q;
  auto f = [](ll s,ll t,ll u) -> ll {
    return s*t+t*u+u*s;
  };
  q.push(tuple(f(a.front(),b.front(),c.front()),0,0,0));
  set<tuple<int,int,int>> seen;
  rep(_,k-1) {
    auto [d,ai,bi,ci] = q.top();q.pop();
    if(ai!=n-1&&seen.count(tuple(ai+1,bi,ci))==0) {
      ll nx = f(a.at(ai+1),b.at(bi),c.at(ci));
      q.push(tuple(nx,ai+1,bi,ci));
      seen.insert(tuple(ai+1,bi,ci));
    }
    if(bi!=n-1&&seen.count(tuple(ai,bi+1,ci))==0) {
      ll nx = f(a.at(ai),b.at(bi+1),c.at(ci));
      q.push(tuple(nx,ai,bi+1,ci));
      seen.insert(tuple(ai,bi+1,ci));
    }
    if(ci!=n-1&&seen.count(tuple(ai,bi,ci+1))==0) {
      ll nx = f(a.at(ai),b.at(bi),c.at(ci+1));
      q.push(tuple(nx,ai,bi,ci+1));
      seen.insert(tuple(ai,bi,ci+1));
    }
  }
  auto [d,x,y,z] = q.top();
  cout << d << endl;

  return 0;
}
