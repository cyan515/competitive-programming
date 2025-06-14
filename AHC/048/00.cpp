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

double calc_diff(const color &a, const color &b) {
  double dc = a.c-b.c;
  double dm = a.m-b.m;
  double dy = a.y-b.y;
  return dc*dc+dm*dm+dy*dy;
}

vector<action> solve(int n,int k,int h,int t,int d,vector<color> &colors,vector<color> &targets) {
  vector<action> ret;
  for(auto& target : targets) {
    double min_diff = INF;
    int idx = -1;
    rep(i,k) {
      double diff = calc_diff(colors.at(i),target);
      if(diff<min_diff) {
        min_diff = diff;
        idx = i;
      }
    }
    ret.push_back(add(0,idx));
    ret.push_back(deliver(0));
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
  rep(i,n-1) {
    rep(j,n) {
      if(j) cout << " ";
      cout << 1;
    }
    cout << endl;
  }
  rep(i,n) {
    rep(j,n-1) {
      if(j) cout << " ";
      cout << 0;
    }
    cout << endl;
  }
  auto ans = solve(n,k,h,t,d,colors,targets);
  for(auto act : ans) {
    act.print();
  }
  
  cout.flush();

  return 0;
}
