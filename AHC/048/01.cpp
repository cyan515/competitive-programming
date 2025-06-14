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
const double TIME_LIMIT = 2.7;

bool is_timeover() {
  return timer.get_time() > TIME_LIMIT;
}

struct color {
  double c,m,y;
};

struct action {
  int type,i,j,ii,jj,k;
  void print() {
    switch(type) {
      case 1:
        printf("%d %d %d %d\n",type,i,j,k);
        break;
      case 2:
      case 3:
        printf("%d %d %d\n",type,i,j);
        break;
      case 4:
        printf("%d %d %d %d %d\n",type,i,j,ii,jj);
        break;
    }
  }
};

action add(int i,int k) {
  return {1,i,0,-1,-1,k};
}
action deliver(int i) {
  return {2,i,0,-1,-1,-1};
}
action discard(int i) {
  return {3,i,0,-1,-1,-1};
}
action toggle(int i1,int j1,int i2,int j2) {
  return {4,i1,j1,i2,j2,-1};
}

struct well {
  color col;
  double quantity;
  bool empty() {
    return this->quantity < 1e-6;
  }
};

double calc_diff(const color &a, const color &b) {
  double dc = a.c-b.c;
  double dm = a.m-b.m;
  double dy = a.y-b.y;
  return sqrt(dc*dc+dm*dm+dy*dy);
}

color mix(const color &a, const color &b, double a_vol, double b_vol) {
  double c = (a.c*a_vol+b.c*b_vol)/(a_vol+b_vol);
  double m = (a.m*a_vol+b.m*b_vol)/(a_vol+b_vol);
  double y = (a.y*a_vol+b.y*b_vol)/(a_vol+b_vol);
  return {c,m,y};
}

double score = 1;
vector<action> solve(int n,int k,int h,int t,int d,vector<color> &colors,vector<color> &targets) {
  vector<action> ret;
  vector<well> wells(n);
  rep(i,n) wells.at(i) = {{0,0,0},0};
  queue<int> empty_wells;
  reps(i,1,n) empty_wells.push(i);
  for(auto& target : targets) {
    double min_diff = INF;
    vector<action> actions;
    int upd_idx = -1;
    color upd_col = {0,0,0};
    function<void(void)> update = [&]() -> void {
    };
    // 既存のウェル単体
    rep(i,n) {
      if(wells.at(i).empty()) continue;
      if(wells.at(i).quantity<1.0) continue;
      double diff = calc_diff(wells.at(i).col,target);
      if(diff<min_diff) {
        min_diff = diff;
        actions = {deliver(i)};
        upd_idx = i;
        update = [&]() -> void {
          wells.at(upd_idx).quantity -= 1.0;
          if(wells.at(upd_idx).empty()) empty_wells.push(upd_idx);
        };
      }
    }
    rep(i,k) {
      double diff = calc_diff(colors.at(i),target);
      // 単色
      if(diff<min_diff) {
        min_diff = diff;
        actions = {add(0,i),deliver(0)};
        update = [&]() -> void {
        };
      }
      // 2 色
      if(empty_wells.size()) reps(j,i+1,k) {
        color mixed = mix(colors.at(i),colors.at(j),1,1);
        diff = calc_diff(mixed,target);
        if(diff<min_diff) {
          min_diff = diff;
          upd_idx = empty_wells.front();
          actions = {add(upd_idx,i),add(upd_idx,j),deliver(upd_idx)};
          upd_col = mixed;
          update = [&]() -> void {
            empty_wells.pop();
            wells.at(upd_idx).col = upd_col;
            wells.at(upd_idx).quantity = 1;
          };
        }
      }
      // 3 色
      if(empty_wells.size()) reps(j,i+1,k) reps(jj,j+1,k) {
        color mixed = mix(colors.at(i),colors.at(j),1,1);
        mixed = mix(mixed,colors.at(jj),2,1);
        diff = calc_diff(mixed,target);
        if(diff<min_diff) {
          min_diff = diff;
          upd_idx = empty_wells.front();
          actions = {add(upd_idx,i),add(upd_idx,j),add(upd_idx,jj),deliver(upd_idx)};
          upd_col = mixed;
          update = [&]() -> void {
            empty_wells.pop();
            wells.at(upd_idx).col = upd_col;
            wells.at(upd_idx).quantity = 2;
          };
        }
      }
      // ウェルに混ぜる
      rep(j,n) {
        if(wells.at(j).empty()) continue;
        color mixed = mix(wells.at(j).col,colors.at(i),wells.at(j).quantity,1);
        diff = calc_diff(mixed,target);
        if(diff<min_diff) {
          min_diff = diff;
          actions = {add(j,i),deliver(j)};
          upd_idx = j;
          upd_col = mixed;
          update = [&]() -> void {
            wells.at(upd_idx).col = upd_col;
          };
        }
      }
    }
    
    if(empty_wells.size()) {
      int well_i = empty_wells.front();
      int dep = 5;
      vector<action> cur_acts;
      auto dfs = [&](auto self,color cur_col,int cur_q,int cur_i) -> void {
        double diff = calc_diff(cur_col,target);
        if(cur_q>=1&&diff<min_diff) {
          min_diff = diff;
          cur_acts.push_back(deliver(well_i));
          actions = cur_acts;
          cur_acts.pop_back();
          upd_idx = well_i;
          upd_col = cur_col;
          update = [&]() -> void {
            empty_wells.pop();
            wells.at(upd_idx).col = upd_col;
            wells.at(upd_idx).quantity = cur_q-1;
          };
        }
        if(cur_q==dep) return;
        reps(ki,cur_i,k) {
          cur_acts.push_back(add(well_i,ki));
          self(self,mix(cur_col,colors.at(ki),cur_q,1),cur_q+1,ki);
          cur_acts.pop_back();
        }
      };
      dfs(dfs,{0,0,0},0,0);
    }
    
    ret.insert(ret.end(),actions.begin(),actions.end());
    update();
    score += min_diff*1e4;
  }
  return ret;
}

int main() {
  timer.start();
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  // receive input
  int n,k,h,t,d;cin>>n>>k>>h>>t>>d;
  vector<color> colors(k),targets(h);
  rep(i,k) {
    double c,m,y;cin>>c>>m>>y;
    colors.at(i) = {c,m,y};
  }
  rep(i,h) {
    double c,m,y;cin>>c>>m>>y;
    targets.at(i) = {c,m,y};
  }
  
  // decide pallet state
  rep(i,n-1) {
    rep(j,n) {
      if(j) cout << " ";
      cout << 0;
    }
    cout << endl;
  }
  rep(i,n) {
    rep(j,n-1) {
      if(j) cout << " ";
      cout << 1;
    }
    cout << endl;
  }
  
  // solve
  auto ans = solve(n,k,h,t,d,colors,targets);
  for(auto act : ans) act.print();
  
  int cnt = 0;
  for(auto act : ans) {
    if(act.type==1) cnt++;
  }
  score += d*(cnt-h);
  cerr << score << endl;
  
  cout.flush();

  return 0;
}
