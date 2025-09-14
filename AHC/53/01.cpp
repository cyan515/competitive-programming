#include <bits/stdc++.h>
using namespace std;
#define reps(i, a, n) for (int i = (a); i < (int) (n); ++i)
#define rep(i, n) reps(i, 0, n)
const int INF = (1<<30)-1;
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}

// std::random_device seed_gen;
// std::mt19937 mt(seed_gen());
// #pragma GCC target("avx")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")

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
Timer timer;
const double TIME_LIMIT = 1.8;

bool is_timeover() {
  return timer.get_time() > TIME_LIMIT;
}

using ll = long long;

int n,m;
ll l,u;

template <class T> void print(vector<T>& vec) {
  rep(i,vec.size()) {
    if(i) cout << " ";
    cout << vec.at(i);
  }
  cout << '\n';
  cout.flush();
}

vector<int> solve(vector<ll>& a, vector<ll>& b) {
  vector<int> ret(n,-1);
  map<ll,queue<int>> mp;
  rep(i,n) mp[a.at(i)].push(i);
  auto rem = b;
  rep(i,m) {
    auto it = mp.upper_bound(rem.at(i));
    while(it!=mp.begin()) {
      it--;
      ret.at((*it).second.front()) = i;
      rem.at(i) -= a.at((*it).second.front());
      (*it).second.pop();
      if((*it).second.size()==0) mp.erase(it);
      it = mp.upper_bound(rem.at(i));
    }
  }
  while(mp.size()) {
    auto [val,q] = *mp.begin();
    while(q.size()) {
      int idx = q.front();q.pop();
      int best = 0;
      int best_i = -1;
      rep(i,m) {
        ll cur = abs(rem.at(i));
        ll nex = abs(rem.at(i)-val);
        ll d = cur - nex;
        if(d > best) {
          best = d;
          best_i = i;
        }
      }
      if(best_i==-1) continue;
      rem.at(best_i) -= a.at(idx);
      ret.at(idx) = best_i;
    }
    mp.erase(val);
  }
  return ret;
}

vector<ll> decide_a() {
  vector<ll> a(n,1);
  int cur_i = 0;
  rep(i,m) a.at(cur_i++) = l;
  reps(i,m,m+45) a.at(i) = 1e12 * ((i-m)/15 + 1);
  reps(i,m+45,n) {
    a.at(i) = 1e9;
    rep(j,i%4) a.at(i) *= 10;
  }
  return a;
}

ll calc_score(vector<ll>& a,vector<ll>& b,vector<int>& x) {
  vector<ll> sum(m,0);
  rep(i,n) {
    if(x.at(i)==0) continue;
    sum.at(x.at(i)-1) += a.at(i);
  }
  ll diff = 0;
  rep(i,m) diff += abs(b.at(i)-sum.at(i));
  ll ret = (20 - log10(1+diff)) * 5 * 10000000;
  return ret;
}

int main() {
  timer.start();
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  // receive input
  cin>>n>>m>>l>>u;
  auto a = decide_a();
  print(a);
  vector<ll> b(m);
  rep(i,m) cin>>b.at(i);
  auto ans = solve(a,b);
  rep(i,ans.size()) ans.at(i)++;
  print(ans);
  auto score = calc_score(a,b,ans);
  cerr << score << endl;

  return 0;
}
