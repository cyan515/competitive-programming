#include <bits/stdc++.h>
using namespace std;
#define reps(i, a, n) for (int i = (a); i < (int) (n); ++i)
#define rep(i, n) reps(i, 0, n)
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}

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
mt19937 engine;
  
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("O3,unroll-loops,fast-math")
array<int,2> near[] = {{-2,0},{-1,-1},{-1,0},{-1,1},{0,-2},{0,-1},{0,0},{0,1},{0,2},{1,-1},{1,0},{1,1},{2,0},};
array<int,2> dir[] = {{0,1},{0,-1},{1,0},{-1,0},}; // RLDU
constexpr int R = 0;
constexpr int L = 1;
constexpr int D = 2;
constexpr int U = 3;
constexpr int INF = 1<<30;
struct Type {
  int num;
  char symbol;
  auto operator<=>(const Type&) const = default;
};
const Type STATION = {0,'#'};
const Type RAIL_HORIZONTAL = {1,'-'};
const Type RAIL_VERTICAL = {2,'|'};
const Type RAIL_LEFT_DOWN = {3,'\\'};
const Type RAIL_LEFT_UP = {4,'/'};
const Type RAIL_RIGHT_UP = {5,'\\'};
const Type RAIL_RIGHT_DOWN = {6,'/'};
const int COST_STATION = 5000;
const int COST_RAIL = 100;
double run_time;

class solver01 {
protected:
  // 直前と直後のレールとの位置関係から、今敷設しようとしているレールの形を決める。
  // 多分もういじらない。
  Type decide_rail(pair<int,int> prev,pair<int,int> cur,pair<int,int> nx) {
    auto [ci,cj] = cur;
    bool vec[] = {false,false,false,false};
    rep(i,4) {
      auto [di,dj] = dir[i];
      int ni = ci+di;
      int nj = cj+dj;
      if(pair(ni,nj)==prev||pair(ni,nj)==nx) vec[i] = true;
    }
    if(vec[L]&&vec[R]) return RAIL_HORIZONTAL;
    else if(vec[U]&&vec[D]) return RAIL_VERTICAL;
    else if(vec[L]&&vec[D]) return RAIL_LEFT_DOWN;
    else if(vec[L]&&vec[U]) return RAIL_LEFT_UP;
    else if(vec[R]&&vec[U]) return RAIL_RIGHT_UP;
    else if(vec[R]&&vec[D]) return RAIL_RIGHT_DOWN;
    else return {-1,'?'};
  }

  inline bool in(unsigned int n,unsigned int i, unsigned int j) {
    return i<n&&j<n;
  }

  // 最初、つまり、駅 2 つ建設する敷設計画を作成する。
  virtual queue<tuple<Type,int,int>> plan_first_construction(int n,string (&field)[],pair<int,int> station1,pair<int,int> station2) {
    queue<tuple<Type,int,int>> ret;
    queue<pair<int,int>> q;
    q.push(station1);
    bitset<50*50> seen;
    seen.set(station1.first*n+station1.second);
    pair<int,int> prev[n][n];
    rep(i,n) fill(prev[i],prev[i]+n,pair(-1,-1));
    while(q.size()) {
      if(timer.get_time()>2.7) return {};
      auto [vi,vj] = q.front();q.pop();
      int ord[] = {0,1,2,3};
      shuffle(ord, ord+4, engine);
      for(auto o : ord) {
        auto [di,dj] = dir[o];
        int ni = vi+di;
        int nj = vj+dj;
        if(!in(n,ni,nj)) continue;
        if(field[ni][nj]!='.') continue;
        if(seen.test(ni*n+nj)) continue;
        seen.set(ni*n+nj);
        q.push(pair(ni,nj));
        prev[ni][nj] = pair(vi,vj);
      }
    }
    auto [cur_i,cur_j] = station2;
    vector<pair<int,int>> rails;
    rails.reserve(abs(station1.first-station2.first)+abs(station1.second-station2.second));
    rails.push_back(station2);
    while(pair(cur_i,cur_j)!=station1) {
      auto [ni,nj] = prev[cur_i][cur_j];
      cur_i = ni;
      cur_j = nj;
      rails.push_back(pair(cur_i,cur_j));
    }
    reps(i,1,rails.size()-1) {
      ret.push(tuple(decide_rail(rails[i-1],rails[i],rails[i+1]),rails[i].first,rails[i].second));
    }
    ret.push(tuple(STATION,station1.first,station1.second));
    ret.push(tuple(STATION,station2.first,station2.second));
    return ret;
  }

  // 最初に敷設した場合に一番稼げる駅の建て方とそのときの income を返す
  tuple<pair<int,int>,pair<int,int>,int> decide_first_construction(int n,int money,int m,vector<vector<pair<int,int>>> (&person_plot)[],vector<vector<pair<int,int>>> (&workplace_plot)[]) {
    pair<int,int> ma = pair(0,0);
    bool flg[m];
    fill(flg,flg+m,false);
    pair<pair<int,int>,pair<int,int>> best;
    rep(ai,n) rep(aj,n) {
      bool found = false;
      for(auto [di,dj] : near) {
        int ni = ai+di;
        int nj = aj+dj;
        if(!in(n,ni,nj)) continue;
        for(auto [idx,_] : person_plot[ni][nj]) flg[idx] = true, found = true;
        for(auto [idx,_] : workplace_plot[ni][nj]) flg[idx] = true , found = true;
      }
      if(!found) continue;
      reps(bi,ai,n) rep(bj,n) {
        if(bi==ai&&bj<=aj) continue;
        if(abs(ai-bi)+abs(aj-bj)<=4) continue;
        if(money < COST_STATION*2 + COST_RAIL*(abs(ai-bi)+abs(aj-bj)-1)) continue;
        int cnt = 0;
        int potential = 0;
        for(auto [di,dj] : near) {
          int ni = bi+di;
          int nj = bj+dj;
          if(!in(n,ni,nj)) continue;
          for(auto [idx,benefit] : person_plot[ni][nj]) cnt += flg[idx] * benefit, potential += benefit;
          for(auto [idx,benefit] : workplace_plot[ni][nj]) cnt += flg[idx] * benefit, potential += benefit;
        }
        if(chmax(ma,pair(cnt,potential))) best = pair(pair(ai,aj),pair(bi,bj));
      }
      for(auto [di,dj] : near) {
        int ni = ai+di;
        int nj = aj+dj;
        if(!in(n,ni,nj)) continue;
        for(auto [idx,_] : person_plot[ni][nj]) flg[idx] = false;
        for(auto [idx,_] : workplace_plot[ni][nj]) flg[idx] = false;
      }
    }
    return tuple(best.first,best.second,ma.first);
  }

  bool is_rail(char c) {
    return c==RAIL_HORIZONTAL.symbol||c==RAIL_VERTICAL.symbol||c==RAIL_LEFT_DOWN.symbol||c==RAIL_LEFT_UP.symbol||c==RAIL_RIGHT_DOWN.symbol||c==RAIL_RIGHT_UP.symbol;
  }

  virtual queue<tuple<Type,int,int>> plan_construction(int n,string (&field)[],pair<int,int> new_station) {
    queue<tuple<Type,int,int>> ret;

    if(is_rail(field[new_station.first][new_station.second])) {
      ret.push(tuple(STATION,new_station.first,new_station.second));
      return ret;
    }

    queue<pair<int,int>> q;
    q.push(new_station);
    bitset<50*50> seen;
    seen.set(new_station.first*n+new_station.second);
    pair<int,int> prev[n][n];
    rep(i,n) rep(j,n) prev[i][j] = pair(-1,-1);
    pair<int,int> conn_station = pair(-1,-1);
    while(q.size()&&conn_station==pair(-1,-1)) {
      if(timer.get_time()>2.7) return {};
      auto [vi,vj] = q.front();q.pop();
      deque<pair<int,int>> deq;
      for(auto [di,dj] : dir) {
        bool next_to_rail = false;
        for(auto [dii,djj] : dir) {
          int ni = vi+di+dii;
          int nj = vj+dj+djj;
          if(!in(n,ni,nj)) continue;
          next_to_rail |= is_rail(field[ni][nj]);
        }
        if(next_to_rail) deq.push_back(pair(di,dj));
        else deq.push_front(pair(di,dj));
      }
      while(deq.size()) {
        auto [di,dj] = deq.front();deq.pop_front();
        int ni = vi+di;
        int nj = vj+dj;
        if(!in(n,ni,nj)) continue;
        if(seen.test(ni*n+nj)) continue;
        if(field[ni][nj]==STATION.symbol) {
          conn_station = pair(ni,nj);
          prev[ni][nj] = pair(vi,vj);
          break;
        }
        if(field[ni][nj]!='.') continue;
        seen.set(ni*n+nj);
        q.push(pair(ni,nj));
        prev[ni][nj] = pair(vi,vj);
      }
    }
    if(conn_station==pair(-1,-1)) return {};
    auto [cur_i,cur_j] = conn_station;
    vector<pair<int,int>> rails;
    rails.reserve(abs(new_station.first-conn_station.first)+abs(new_station.second-conn_station.second));
    rails.push_back(conn_station);
    while(pair(cur_i,cur_j)!=pair(-1,-1)&&pair(cur_i,cur_j)!=new_station) {
      auto [ni,nj] = prev[cur_i][cur_j];
      cur_i = ni;
      cur_j = nj;
      rails.push_back(pair(cur_i,cur_j));
    }
    reps(i,1,rails.size()-1) {
      ret.push(tuple(decide_rail(rails[i-1],rails[i],rails[i+1]),rails[i].first,rails[i].second));
    }
    ret.push(tuple(STATION,new_station.first,new_station.second));
    return ret;
  }

  // そこに駅を建てたらどれぐらい income が増えるかシミュレーションする。update に true を渡すと実際に更新が走る。
  // 今すぐは増えないが巻き込んで将来の見込み利益になる potential も計算する。
  pair<int,int> simulate_station_construction(int n,bool (&is_person_involved)[],bool (&is_workplace_involved)[],vector<vector<pair<int,int>>> (&people)[],vector<vector<pair<int,int>>> (&workplaces)[],pair<int,int> point,bool update) {
    int ret = 0;
    int potential = 0;
    for(auto [di,dj] : near) {
      int ni = point.first+di;
      int nj = point.second+dj;
      if(!in(n,ni,nj)) continue;
      bool flg = false;
      for(auto [idx,benefit] : people[ni][nj]) {
        if(is_person_involved[idx]) {
          flg = true;
          break;
        }
        if(update) is_person_involved[idx] = true;
        if(is_workplace_involved[idx]) ret += benefit;
        else potential += benefit;
      }
      if(flg) continue;
      for(auto [idx,benefit] : workplaces[ni][nj]) {
        if(!is_workplace_involved[idx]) {
          if(update) is_workplace_involved[idx] = true;
          if(is_person_involved[idx]) ret += benefit;
          else potential += benefit;
        }
      }
    }
    return pair(ret,potential);
  }

public:
  tuple<int,vector<tuple<int,int,int>>,int> solve(int n,int m,int money,int turn,pair<int,int> (&people)[],pair<int,int> (&workplaces)[]) {
    vector<tuple<int,int,int>> ret(turn);
    string field[n];
    fill(field,field+n,string(n,'.'));
    int dist[n][n];
    rep(i,n) fill(dist[i],dist[i]+n,INF);
    int best_score = 0;
    int best_last_turn = 0;
    int income = 0;
    bool is_person_involved[m],is_workplace_involved[m];
    fill(is_person_involved,is_person_involved+m,false);
    fill(is_workplace_involved,is_workplace_involved+m,false);
    // pair(index, benefit)
    vector<vector<pair<int,int>>> person_plot[n],workplace_plot[n];
    fill(person_plot,person_plot+n,vector<vector<pair<int,int>>>(n));
    fill(workplace_plot,workplace_plot+n,vector<vector<pair<int,int>>>(n));
    int rest_potential = 0;
    double cur_potential = 0;
    int station_cnt = 0;
    int rail_cnt = 0;
    if(timer.get_time()>2.7) return tuple(best_score,ret,best_last_turn);
    
    rep(i,m) {
      auto [pi,pj] = people[i];
      auto [wi,wj] = workplaces[i];
      int ben = abs(pi-wi)+abs(pj-wj);
      person_plot[pi][pj].push_back(pair(i,ben));
      workplace_plot[wi][wj].push_back(pair(i,ben));
      rest_potential += ben;
    }
    set<pair<int,int>> black_list;
    if(timer.get_time()>2.7) return tuple(best_score,ret,best_last_turn);

    queue<tuple<Type,int,int>> plan;
    {
      auto [sa,sb,ben] = decide_first_construction(n,money,m,person_plot,workplace_plot);
      plan = plan_first_construction(n,field,sa,sb);
      if(plan.empty()) {
        return tuple(best_score,ret,0);
      }
      queue<pair<int,int>> q;
      q.push(sa);
      q.push(sb);
      dist[sa.first][sa.second] = 0;
      dist[sb.first][sb.second] = 0;
      while(q.size()) {
        auto [vi,vj] = q.front();q.pop();
        for(auto [di,dj] : dir) {
          int ni = vi+di;
          int nj = vj+dj;
          if(!in(n,ni,nj)) continue;
          if(dist[ni][nj]!=INF) continue;
          dist[ni][nj] = dist[vi][vj] + 1;
          q.push(pair(ni,nj));
        }
      }
    }
    unordered_set<int> st;
    rep(i,n) rep(j,n) st.insert(i*n+j);
    if(timer.get_time()>2.7) return tuple(best_score,ret,best_last_turn);
    rep(cur_turn,turn) {
      while(plan.empty()) {
        if(rest_potential==0) break;
        // eval, -distance
        pair<double,int> best_evaluation = pair(0.0,0);
        int best_benefit = 0;
        int best_potential = 0;
        pair<int,int> target = pair(-1,-1);
        vector<int> del;
        for(auto hash : st) {
          if(timer.get_time()>2.7) return tuple(best_score,ret,best_last_turn);
          int i = hash / n;
          int j = hash % n;
          if(field[i][j]=='#') continue;
          if(dist[i][j]==INF) continue;
          if(black_list.count(pair(i,j))) continue;
          auto [benefit,potential] = simulate_station_construction(n,is_person_involved,is_workplace_involved,person_plot,workplace_plot,pair(i,j),false);
          if(benefit==0&&potential==0) del.push_back(i*n+j);
          double evaluation = benefit;
          // 線路上は建設が楽なので加点
          // 回収猶予のない後半ほど加点を大きくする
          if(dist[i][j]<3) evaluation *= 1.0+2.0*cur_turn/(double)turn;
          evaluation += potential / 2.0 * cur_turn / (double) turn;
          if(chmax(best_evaluation,pair(evaluation, -dist[i][j]))) target = pair(i,j), best_benefit = benefit, best_potential = potential;
        }
        for(auto ele : del) st.erase(ele);
        if(target!=pair(-1,-1)) {
          plan = plan_construction(n,field,target);
          // 見つけたけど到達不可能な地点の場合、しょうがないのでブラックリストに入れて今後見ないことにする（かなしい）
          if(plan.empty()) {
            if(timer.get_time()>2.7) return tuple(best_score,ret,best_last_turn);
            black_list.insert(target);
          }
        } else break;
      }
      if(plan.size()) {
        auto [type,i,j] = plan.front();
        bool ok = false;
        if(type==STATION&&money>=COST_STATION) {
          ok = true;
          money -= COST_STATION;
          if(timer.get_time()>2.7) return tuple(best_score,ret,best_last_turn);
          auto [income_delta, potential_delta] = simulate_station_construction(n,is_person_involved,is_workplace_involved,person_plot,workplace_plot,pair(i,j),true);
          income += income_delta;
          cur_potential -= income_delta;
          cur_potential += potential_delta;
          rest_potential -= income_delta;
          station_cnt++;
        } else if(type!=STATION&&money>=COST_RAIL) {
          ok = true;
          money -= COST_RAIL;
          rail_cnt++;
        }
        if(ok) {
          ret[cur_turn] = tuple(type.num,i,j);
          plan.pop();
          field[i][j] = type.symbol;
          if(type==STATION) {
            queue<pair<int,int>> q;
            rep(ii,n) fill(dist[ii],dist[ii]+n,INF);
            rep(ii,n) rep(jj,n) {
              if(is_rail(field[ii][jj])) dist[ii][jj] = 1;
              else if(field[ii][jj]==STATION.symbol) dist[ii][jj] = 0, q.push(pair(ii,jj));
            }
            if(timer.get_time()>2.7) return tuple(best_score,ret,best_last_turn);
            while(q.size()) {
              auto [vi,vj] = q.front();q.pop();
              for(auto [di,dj] : dir) {
                int ni = vi+di;
                int nj = vj+dj;
                if(!in(n,ni,nj)) continue;
                if(dist[ni][nj]!=INF) continue;
                if(field[ni][nj]!='.') continue;
                dist[ni][nj] = dist[vi][vj] + 1;
                q.push(pair(ni,nj));
              }
            }
          }
        } else ret[cur_turn] = tuple(-1,-1,-1);
      } else {
        ret[cur_turn] = tuple(-1,-1,-1);
      }
      {
        int score = money + income * (turn - cur_turn);
        if(chmax(best_score, score)) best_last_turn = cur_turn;
      }
      money += income;
      if(timer.get_time()>2.7) return tuple(best_score,ret,best_last_turn);
    }
    return tuple(best_score,ret,best_last_turn);
  }
};

class solver02 : public solver01 {
protected:
  virtual queue<tuple<Type,int,int>> plan_construction(int n,string (&field)[],pair<int,int> new_station) override {
    queue<tuple<Type,int,int>> ret;

    if(is_rail(field[new_station.first][new_station.second])) {
      ret.push(tuple(STATION,new_station.first,new_station.second));
      return ret;
    }

    queue<pair<int,int>> q;
    q.push(new_station);
    bitset<50*50> seen;
    seen.set(new_station.first*n+new_station.second);
    pair<int,int> prev[n][n];
    rep(i,n) rep(j,n) prev[i][j] = pair(-1,-1);
    pair<int,int> conn_station = pair(-1,-1);
    while(q.size()&&conn_station==pair(-1,-1)) {
      auto [vi,vj] = q.front();q.pop();
      for(auto [di,dj] : dir) {
        int ni = vi+di;
        int nj = vj+dj;
        if(!in(n,ni,nj)) continue;
        if(seen.test(ni*n+nj)) continue;
        if(field[ni][nj]==STATION.symbol) {
          conn_station = pair(ni,nj);
          prev[ni][nj] = pair(vi,vj);
          break;
        }
        if(field[ni][nj]!='.') continue;
        seen.set(ni*n+nj);
        q.push(pair(ni,nj));
        prev[ni][nj] = pair(vi,vj);
      }
    }
    if(conn_station==pair(-1,-1)) return {};
    auto [cur_i,cur_j] = conn_station;
    vector<pair<int,int>> rails;
    rails.reserve(abs(new_station.first-conn_station.first)+abs(new_station.second-conn_station.second));
    rails.push_back(conn_station);
    while(pair(cur_i,cur_j)!=pair(-1,-1)&&pair(cur_i,cur_j)!=new_station) {
      auto [ni,nj] = prev[cur_i][cur_j];
      cur_i = ni;
      cur_j = nj;
      rails.push_back(pair(cur_i,cur_j));
    }
    reps(i,1,rails.size()-1) {
      ret.push(tuple(decide_rail(rails[i-1],rails[i],rails[i+1]),rails[i].first,rails[i].second));
    }
    ret.push(tuple(STATION,new_station.first,new_station.second));
    return ret;
  }
};

class solver03 : public solver01 {
protected:
  virtual queue<tuple<Type,int,int>> plan_construction(int n,string (&field)[],pair<int,int> new_station) override {
    queue<tuple<Type,int,int>> ret;

    if(is_rail(field[new_station.first][new_station.second])) {
      ret.push(tuple(STATION,new_station.first,new_station.second));
      return ret;
    }

    int ord[] = {0,1,2,3};
    queue<pair<int,int>> q;
    q.push(new_station);
    bitset<50*50> seen;
    seen.set(new_station.first*n+new_station.second);
    pair<int,int> prev[n][n];
    rep(i,n) rep(j,n) prev[i][j] = pair(-1,-1);
    pair<int,int> conn_station = pair(-1,-1);
    while(q.size()&&conn_station==pair(-1,-1)) {
      if(timer.get_time()>2.7) return {};
      auto [vi,vj] = q.front();q.pop();
      shuffle(ord, ord+4, engine);
      for(auto o : ord) {
        auto [di,dj] = dir[o];
        int ni = vi+di;
        int nj = vj+dj;
        if(!in(n,ni,nj)) continue;
        if(seen.test(ni*n+nj)) continue;
        if(field[ni][nj]==STATION.symbol) {
          conn_station = pair(ni,nj);
          prev[ni][nj] = pair(vi,vj);
          break;
        }
        if(field[ni][nj]!='.') continue;
        seen.set(ni*n+nj);
        q.push(pair(ni,nj));
        prev[ni][nj] = pair(vi,vj);
      }
    }
    if(conn_station==pair(-1,-1)) return {};
    auto [cur_i,cur_j] = conn_station;
    vector<pair<int,int>> rails;
    rails.reserve(abs(new_station.first-conn_station.first)+abs(new_station.second-conn_station.second));
    rails.push_back(conn_station);
    while(pair(cur_i,cur_j)!=pair(-1,-1)&&pair(cur_i,cur_j)!=new_station) {
      auto [ni,nj] = prev[cur_i][cur_j];
      cur_i = ni;
      cur_j = nj;
      rails.push_back(pair(cur_i,cur_j));
    }
    reps(i,1,rails.size()-1) {
      ret.push(tuple(decide_rail(rails[i-1],rails[i],rails[i+1]),rails[i].first,rails[i].second));
    }
    ret.push(tuple(STATION,new_station.first,new_station.second));
    return ret;
  }
};

int main() {
  timer.start();
  random_device seed_gen;
  engine = mt19937(seed_gen());
  // std::cin.tie(0); ios::sync_with_stdio(false);
  int n,m,money,turn;cin>>n>>m>>money>>turn;
  pair<int,int> people[m],workplaces[m];
  rep(i,m) {
    int x,y;cin>>x>>y;
    people[i] = pair(x,y);
    cin>>x>>y;
    workplaces[i] = pair(x,y);
  }
  int best_score = money;
  int best_last_turn = 800;
  vector<tuple<int,int,int>> best_ans(turn,tuple(-1,-1,-1));
  vector<solver01*> solvers = {new solver01(), new solver02(), new solver03()};
  run_time = (0.5 * m + 100.0) / 1000.0;
  for(auto s : solvers) {
    if(timer.get_time() + run_time > 2.7) break;
    auto [score, ans, last_trun] = s->solve(n,m,money,turn,people,workplaces);
    if(chmax(best_score, score)) best_ans = ans, best_last_turn = last_trun;
  }
  while(timer.get_time() + run_time < 2.7) {
    auto [score, ans, last_trun] = solvers.back()->solve(n,m,money,turn,people,workplaces);
    if(chmax(best_score, score)) swap(best_ans,ans), best_last_turn = last_trun;
  }
  rep(i,turn) {
    auto [a,b,c] = best_ans[i];
    if(a==-1 || i > best_last_turn) cout << -1 << '\n';
    else printf("%d %d %d\n",a,b,c);
  }
  cout << flush;
  cerr << best_score << endl;

  return 0;
}
