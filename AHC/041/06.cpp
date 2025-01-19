#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace atcoder;
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

pair<vector<int>,vector<int>> solve(int n,int m,int h,vector<int>& a,vector<vector<int>>& graph) {
  vector<int> ret(n,-2);
  vector<int> depths(n,0);
  vector<bool> seen(n,false);
  vector<int> ord(n);
  rep(i,n) shuffle(all(graph.at(i)),engine);
  rep(i,n) ord.at(i) = i;
  sort(all(ord),[&](int ii,int jj) -> bool {
    return a.at(ii)>a.at(jj);
  });
  vector<bool> cand(n,false);
  for(auto& i : ord) {
    if(seen.at(i)) continue;
    seen.at(i) = true;
    ret.at(i) = -1;
    int v = i;
    rep(xx,10) {
      for(auto& nv : graph.at(v)) {
        cand.at(nv) = true;
        if(seen.at(nv)) continue;
        seen.at(nv) = true;
        ret.at(nv) = v;
        depths.at(nv) = 10-xx;
        v = nv;
        break;
      }
    }
  }
  rep(i,n) if(ret.at(i)!=-2) cand.at(i) = false;
  queue<int> q;
  rep(i,n) if(cand.at(i)&&!seen.at(i)) q.push(i);
  while(q.size()) {
    int v = q.front();q.pop();
    int ma = 0;
    int mai = -1;
    for(auto nv : graph.at(v)) {
      if(ret.at(nv)==-2) {
        if(!seen.at(nv)) {
          q.push(nv);
          seen.at(nv) = true;
        }
        continue;
      }
      if(depths.at(nv)==h) continue;
      if(chmax(ma,depths.at(nv))) {
        mai = nv;
      }
    }
    ret.at(v) = mai;
    depths.at(v) = depths.at(mai)+1;
  }
  return pair(ret,depths);
}

void print_ans(vector<int>& p) {
  int n = p.size();
  rep(i,n) {
    if(i) cout << " ";
    cout << p.at(i);
  }
  cout << "\n";
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
  vector graph(n,vector<int>());
  for(auto& [u,v] : edges) {
    graph.at(u).push_back(v);
    graph.at(v).push_back(u);
  }
  vector<int> x(n),y(n);
  rep(i,n) cin>>x.at(i)>>y.at(i);
  int ma = 0;
  vector<int> ans;
  vector<int> depths;
  while(1) {
    auto [nans,ndepths] = solve(n,m,h,a,graph);
    if(chmax(ma,score(a,ndepths))) {
      ans = nans;
      depths = ndepths;
      print_ans(ans);
    }
    if(timer.get_time()>1.8) break;
  }
  cout << endl;
  cerr << score(a,depths) << endl;
  
  return 0;
}
