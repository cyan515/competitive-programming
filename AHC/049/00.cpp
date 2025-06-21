#include <bits/stdc++.h>
using namespace std;
#define reps(i, a, n) for (int i = (a); i < (int) (n); ++i)
#define rep(i, n) reps(i, 0, n)
const int INF = (1<<30)-1;
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

std::random_device seed_gen;
std::mt19937 mt(seed_gen());
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

struct action {
  int type;
  char direction;
  void print() {
    switch(type) {
      case 1:
      case 2:
        printf("%d\n",type);
        break;
      case 3:
        printf("%c\n", direction);
        break;
    }
  }
};

action take() {
  return {1,0};
}

action lay() {
  return {2,0};
}

vector<action> move(int from_i,int from_j,int to_i,int to_j) {
  vector<action> ret;
  while(from_i<to_i) from_i++,ret.push_back({3,'R'});
  while(from_i>to_i) from_i--,ret.push_back({3,'L'});
  while(from_j<to_j) from_j++,ret.push_back({3,'D'});
  while(from_j>to_j) from_j--,ret.push_back({3,'U'});
  return ret;
}

vector<action> solve(int n, vector<vector<int>> &weight, vector<vector<int>> &duration) {
  vector<action> ret;
  int cur_i = 0;
  int cur_j = 0;
  auto ws = weight;
  auto ds = duration;
  priority_queue<tuple<int,int,int>> q;
  vector taken(n,vector<bool>(n,false));
  taken.at(0).at(0) = true;
  rep(i,n) rep(j,n) q.push({ds.at(i).at(j),i,j});
  while(q.size()) {
    auto [d,vi,vj] = q.top();q.pop();
    if(taken.at(vi).at(vj)) continue;
    auto moves = move(cur_i,cur_j,vi,vj);
    ret.insert(ret.end(),moves.begin(),moves.end());
    ret.push_back(take());
    taken.at(vi).at(vj) = true;
    // rep(i,n) rep(j,n) {
    //   if(taken.at(i).at(j)) continue;
      
    // }
    moves = move(vi,vj,0,0);
    ret.insert(ret.end(),moves.begin(),moves.end());
  }
  return ret;
}

int main() {
  timer.start();
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  // receive input
  int n;cin>>n;
  vector weight(n,vector<int>(n)),duration(n,vector<int>(n));
  rep(i,n) rep(j,n) cin>>weight.at(i).at(j);
  rep(i,n) rep(j,n) cin>>duration.at(i).at(j);
  auto answer = solve(n,weight,duration);
  for(auto act : answer) act.print();
  cout.flush();

  return 0;
}
