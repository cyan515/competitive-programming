#include <bits/stdc++.h>
using namespace std;
#define reps(i, a, n) for (int i = (a); i < (int) (n); ++i)
#define rep(i, n) reps(i, 0, n)
const int INF = (1<<30)-1;
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}

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
const vector<double> TIME_LIMITS = {TIME_LIMIT,0.8,};

bool is_timeover() {
  return timer.get_time() > TIME_LIMIT;
}

bool is_timeover(int x) {
  return timer.get_time() > TIME_LIMITS.at(x);
}

struct answer_asset {
  vector<vector<int>> assign;
  vector<int> operations;
};

struct point {
  int x,y;
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
const int STAY = 4;

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
  if(dir_i==STAY) return dir_i;
  else if(dir_i%2) return dir_i - 1;
  else return dir_i + 1;
}

void move_all(vector<point>& pos, const vector<int>& assign, vector<vector<bool>>& seen) {
  rep(i,m) {
    auto [cx,cy] = pos.at(i);
    int dir_i = assign.at(i);
    if(dir_i==STAY || !can_move(p.at(cx).at(cy),assign.at(i))) continue;
    auto [dx,dy] = dir.at(dir_i);
    int nx = cx + dx;
    int ny = cy + dy;
    pos.at(i) = {nx,ny};
    seen.at(nx).at(ny) = true;
  }
}

void move(int& cx, int& cy, int dir_i) {
  auto [dx,dy] = dir.at(dir_i);
  cx += dx;
  cy += dy;
}

tuple<point,int,vector<int>> find_white(const vector<vector<bool>>& seen, const vector<point>& pos) {
  queue<point> q;
  vector machine(n,vector<int>(n,-1));
  vector before(n,vector<int>(n,-1));
  rep(i,m) {
    auto [cx,cy] = pos.at(i);
    machine.at(cx).at(cy) = i;
    q.push(pos.at(i));
  }
  while(q.size()) {
    auto [cx,cy] = q.front();q.pop();
    rep(di,4) {
      if(!can_move(p.at(cx).at(cy),di)) continue;
      auto [dx,dy] = dir.at(di);
      int nx = cx + dx;
      int ny = cy + dy;
      if(machine.at(nx).at(ny)!=-1) continue;
      before.at(nx).at(ny) = di;
      machine.at(nx).at(ny) = machine.at(cx).at(cy);
      q.push({nx,ny});
      if(!seen.at(nx).at(ny)) {
        vector<int> ctrl;
        cx = nx;
        cy = ny;
        while(before.at(cx).at(cy)!=-1) {
          ctrl.push_back(before.at(cx).at(cy));
          move(cx,cy,reverse_direction(before.at(cx).at(cy)));
        }
        reverse(ctrl.begin(),ctrl.end());
        return {{nx,ny},machine.at(cx).at(cy),ctrl};
      }
    }
  }
  return {{-1,-1},-1,{}};
}

vector<vector<int>> permutations;
// buttons[i][j] = マシン i を方向 j に動かしたいとき に押せばよいボタンの配列
vector<vector<vector<int>>> buttons;

vector<vector<int>> gen_assign() {
  vector bs(m,vector(4,vector<int>()));
  vector assign(k,vector<int>(m,4));
  rep(j,m) {
    auto perm = permutations.at(mt()%permutations.size());
    rep(i,perm.size()) {
      assign.at(i).at(j) = perm.at(i);
      bs.at(j).at(perm.at(i)).push_back(i);
    }
  }
  buttons = move(bs);
  return assign;
}

answer_asset solve() {
  auto assign = gen_assign();
  vector<int> operations = {};
  vector<point> pos(m);
  rep(i,m) pos.at(i) = {x.at(i),y.at(i)};

  vector seen(n,vector<bool>(n,false));
  rep(i,m) seen.at(x.at(i)).at(y.at(i)) = true;
  auto [white_point,machine,nxt_operations] = find_white(seen,pos);
  while(machine!=-1) {
    rep(i,nxt_operations.size()) {
      nxt_operations.at(i) = buttons.at(machine).at(nxt_operations.at(i)).at(mt()%2);
    }
    operations.insert(operations.end(),nxt_operations.begin(),nxt_operations.end());
    for(auto ele : nxt_operations) move_all(pos,assign.at(ele),seen);
    auto [wp,mcn,nop] = find_white(seen,pos);
    white_point = wp;
    machine = mcn;
    nxt_operations = nop;
  }
  
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
  
  // calc assign permutations
  vector<int> vec = {0,0,1,1,2,2,3,3,};
  do {
    permutations.push_back(vec);
  } while(next_permutation(vec.begin(),vec.end()));
  
  // solve
  int loop_cnt = 0;
  auto ans = solve();
  int op_cnt = ans.operations.size();
  while(!is_timeover()) {
    loop_cnt++;
    auto nans = solve();
    int nop_cnt = nans.operations.size();
    if(chmin(op_cnt,nop_cnt)) swap(ans,nans);
  }
  print_answer(ans);
  cerr << op_cnt << '\n';
  cerr << loop_cnt << '\n';

  return 0;
}
