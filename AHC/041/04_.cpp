#include <bits/stdc++.h>
// #include <atcoder/dsu>
// using namespace atcoder;
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
mt19937 engine;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_real_distribution<double> rnd(0.0, 1.0);

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

int score(vector<int>& a,vector<int>& depths) {
  int ret = 0;
  int n = a.size();
  rep(i,n) {
    ret += (depths.at(i)+1)*a.at(i);
  }
  return ret + 1;
}

pair<vector<int>,vector<int>> solve(int n,int m,int h,vector<int>& a,vector<pair<int,int>>& edges,vector<int>& xs,vector<int>& ys) {
  vector<int> ret(n);
  vector graph(n,vector<int>());
  for(auto& [u,v] : edges) {
    graph.at(u).push_back(v);
    graph.at(v).push_back(u);
  }
  rep(i,n) shuffle(all(graph.at(i)),engine);
  vector<bool> is_used(n,false);
  vector<bool> is_leaf(n,false);
  vector<int> depths(n,0);
  auto dfs = [&](auto f,int v,int dep) -> void {
    if(dep==h) return;
    bool leaf = true;;
    for(auto nv : graph.at(v)) {
      if(is_used.at(nv)) continue;
      is_used.at(nv) = true;
      depths.at(nv) = dep+1;
      ret.at(nv) = v;
      f(f,nv,dep+1);
      leaf = false;
    }
    is_leaf.at(v) = leaf;
  };
  vector<int> ord(n);
  rep(i,n) ord.at(i) = i;
  shuffle(all(ord), engine);
  for(auto& i : ord) {
    if(is_used.at(i)) continue;
    depths.at(i) = 0;
    ret.at(i) = -1;
    is_used.at(i) = true;
    dfs(dfs,i,0);
  }
  int ma = score(a,depths);
  double start_temp = 1000.0;
  double end_temp = 0.0;
  double start_time = 0.0;
  Timer timer;
  timer.start();
  while(1) {
    double now_time = timer.get_time();
    if(now_time>1.8) break;
    auto rett = ret;
    auto dep = depths;
    rep(v,n) {
      if(rett.at(v)==-1) continue;
      if(!is_leaf.at(v)) continue;
      for(auto nv : graph.at(v)) {
        if(rett.at(nv)==-1) continue;
        if(dep.at(nv)==h) continue;
        if(chmax(dep.at(v),dep.at(nv)+1)) rett.at(v) = nv;
      }
    }
    int nscore = score(a,dep);
    int diff = ma - nscore;
    
    double temp = start_temp + (end_temp - start_temp) * (now_time - start_time) / 0.2;
    double prob = exp(-diff/temp);
    
    if(exp(-diff / temp) > rnd(rng)) {
      ma = nscore;
      swap(depths,dep);
      swap(ret,rett);
    }
  }
  return pair(ret,depths);
}

int main() {
  Timer timer;
  timer.start();
  random_device seed_gen;
  engine = mt19937(seed_gen());
  int n,m,h;cin>>n>>m>>h;
  vector<int> a(n);cin>>a;
  vector<pair<int,int>> edges(m);
  rep(i,m) {
    int u,v;cin>>u>>v;
    edges.at(i) = pair(u,v);
  }
  vector<int> x(n),y(n);
  rep(i,n) cin>>x.at(i)>>y.at(i);
  int ma = 0;
  vector<int> ans;
  vector<int> depths;
  while(1) {
    auto [nans,ndepths] = solve(n,m,h,a,edges,x,y);
    if(chmax(ma,score(a,ndepths))) {
      ans = nans;
      depths = ndepths;
      rep(i,n) {
        if(i) cout << " ";
        cout << ans.at(i);
      }
      cout << "\n";
    }
    // if(timer.get_time()>1.3) break;
    break;
  }
  cout << endl;
  cerr << score(a,depths) << endl;
  
  return 0;
}
