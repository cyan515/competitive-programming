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

struct answer_asset {
  vector<vector<int>> assign;
  vector<int> operations;
};

int n,m,k;
vector<int> x,y;
vector<vector<int>> p;
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},{0,0},};
const string DIR_STRING = "RLDUS";
const int RIGHT = 0;
const int LEFT = 1;
const int DOWN = 2;
const int UP = 3;

void print_answer(answer_asset ans) {
  auto [assign, op] = ans;
  for(auto vec : assign) {
    rep(i,m) {
      if(i) cout << " ";
      cout << DIR_STRING.at(vec.at(i));
    }
    cout << '\n';
  }
  for(auto ele : op) {
    cout << ele << '\n';
  }
}

bool can_move(int bit, int dir_i) {
  return (bit&(1<<dir_i)) == 0;
}

int reverse_direction(int dir_i) {
  if(dir_i==4) return dir_i;
  else if(dir_i%2) return dir_i - 1;
  else return dir_i + 1;
}

answer_asset solve() {
  vector assign(k,vector<int>(m,4));
  vector<int> operations = {};
  
  rep(i,4) assign.at(i).front() = i;
  int sx = x.at(0);
  int sy = y.at(0);
  vector seen(n,vector<bool>(n,false));
  auto dfs = [&](auto self,int cx,int cy) -> void {
    rep(di,4) {
      if(!can_move(p.at(cx).at(cy),di)) continue;
      auto [dx,dy] = dir.at(di);
      int nx = cx+dx;
      int ny = cy+dy;
      if(seen.at(nx).at(ny)) continue;
      seen.at(nx).at(ny) = true;
      operations.push_back(di);
      self(self,nx,ny);
      operations.push_back(reverse_direction(di));
    }
  };
  dfs(dfs,sx,sy);
  
  return {assign, operations};
}

int main() {
  timer.start();
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  // receive input
  cin>>n>>m>>k;
  x.resize(m);
  y.resize(m);
  rep(i,m) cin>>x.at(i)>>y.at(i);
  p.resize(n);
  rep(i,n) p.at(i).resize(n);
  // 0000
  // UDLR
  rep(i,n) rep(j,n) {
    if(j==0 || !can_move(p.at(i).at(j-1),RIGHT)) {
      p.at(i).at(j) += 1<<LEFT;
    }
    if(j==n-1) {
      p.at(i).at(j) += 1<<RIGHT;
      continue;
    }
    char a;cin>>a;
    if(a=='1') p.at(i).at(j) += 1<<0;
  }
  rep(i,n) rep(j,n) {
    if(i==0 || !can_move(p.at(i-1).at(j),DOWN)) {
      p.at(i).at(j) += 1<<UP;
    }
    if(i==n-1) {
      p.at(i).at(j) += 1<<DOWN;
      continue;
    }
    char a;cin>>a;
    if(a=='1') p.at(i).at(j) += 1<<DOWN;
  }
  auto ans = solve();
  print_answer(ans);

  return 0;
}
