#include <bits/stdc++.h>
using namespace std;
#define reps(i, a, n) for (int i = (a); i < (int) (n); ++i)
#define rep(i, n) reps(i, 0, n)
const int INF = (1<<30)-1;
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

std::random_device seed_gen;
std::mt19937 mt(seed_gen());
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

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
  while(from_i<to_i) from_i++,ret.push_back({3,'D'});
  while(from_i>to_i) from_i--,ret.push_back({3,'U'});
  while(from_j<to_j) from_j++,ret.push_back({3,'R'});
  while(from_j>to_j) from_j--,ret.push_back({3,'L'});
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
    auto moves = move(0,0,vi,vj);
    ret.insert(ret.end(),moves.begin(),moves.end());
    ret.push_back(take());
    taken.at(vi).at(vj) = true;
    int mid_i_double,mid_j_double;
    int mid_i,mid_j,mid_ii,mid_jj;
    int min_cost_double = INF;
    int min_cost_triple = INF;
    vector<tuple<int,int,int,int>> cand;
    rep(i,n) rep(j,n) {
      if(taken.at(i).at(j)) continue;
      if(d-ws.at(i).at(j)*(i+j) > 0 && min_cost_double > abs(vi-i)+abs(vj-j)) {
        min_cost_double = abs(vi-i)+abs(vj-j);
        mid_i_double = i;
        mid_j_double = j;
      }
      rep(ii,n) rep(jj,n) {
        if(taken.at(ii).at(jj)) continue;
        if(i==ii&&j==jj) continue;
        bool ok = true;
        ok &= d-ws.at(i).at(j)*(abs(i-ii)+abs(j-jj)+ii+jj)-ws.at(ii).at(jj)*(ii+jj)>0;
        ok &= ds.at(i).at(j)-ws.at(ii).at(jj)*(ii+jj)>0;
        if(ok && min_cost_triple >= abs(vi-i)+abs(vj-j)+abs(i-ii)+abs(j-jj)) {
          if(min_cost_triple == abs(vi-i)+abs(vj-j)+abs(i-ii)+abs(j-jj)) {
            cand.push_back(tuple(i,j,ii,jj));
          } else {
            cand = {{i,j,ii,jj}};
          }
          min_cost_triple = abs(vi-i)+abs(vj-j)+abs(i-ii)+abs(j-jj);
          mid_i = i;
          mid_j = j;
          mid_ii = ii;
          mid_jj = jj;
        }
      }
    }
    if(min_cost_triple!=INF) {
      auto idx = rand()%cand.size();
      auto [mi,mj,mii,mjj] = cand.at(idx);
      mid_i = mi;
      mid_j = mj;
      mid_ii = mii;
      mid_jj = mjj;
      moves = move(vi,vj,mid_i,mid_j);
      ret.insert(ret.end(),moves.begin(),moves.end());
      ret.push_back(take());
      moves = move(mid_i,mid_j,mid_ii,mid_jj);
      ret.insert(ret.end(),moves.begin(),moves.end());
      ret.push_back(take());
      moves = move(mid_ii,mid_jj,0,0);
      ret.insert(ret.end(),moves.begin(),moves.end());
      taken.at(mid_i).at(mid_j) = true;
      taken.at(mid_ii).at(mid_jj) = true;
    } else if(min_cost_double!=INF) {
      moves = move(vi,vj,mid_i_double,mid_j_double);
      ret.insert(ret.end(),moves.begin(),moves.end());
      ret.push_back(take());
      moves = move(mid_i_double,mid_j_double,0,0);
      ret.insert(ret.end(),moves.begin(),moves.end());
      taken.at(mid_i_double).at(mid_j_double) = true;
    } else {
      moves = move(vi,vj,0,0);
      ret.insert(ret.end(),moves.begin(),moves.end());
    }
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
  
  // solve
  int best_score = -INF;
  vector<action> best_answer;
  while(!is_timeover()) {
    auto answer = solve(n,weight,duration);
    int t = 0;
    for(auto act : answer) if(act.type==3) t++;
    int score = n*n + 2*n*n*n - t;
    cerr << n*n + 2*n*n*n - t << endl;
    if(score > best_score) best_score = score, best_answer = answer;
  }
  
  // output
  for(auto act : best_answer) act.print();
  cerr << best_score << endl;
  cout.flush();

  return 0;
}
