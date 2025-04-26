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

set<pair<int,int>> points;
vector<int> remain = {1,1,1,1,1,1,1,1,2};

int check(int i,int j) {
  if(points.count({i,j})) return -1;
  if(i>1&&i<18&&j>1&&j<18) {
    return 9;
  }
  int ret = -1;
  if(i==0&&8<=j&&j<=11) ret = 0;
  if(i==19&&8<=j&&j<=11) ret = 1;
  if(j==0&&8<=i&&i<=11) ret = 2;
  if(j==19&&8<=i&&i<=11) ret = 3;
  if(4<=i&&i<=5&&4<=j&&j<=5) ret = 4;
  if(4<=i&&i<=5&&14<=j&&j<=15) ret = 5;
  if(14<=i&&i<=15&&4<=j&&j<=5) ret = 6;
  if(14<=i&&i<=15&&14<=j&&j<=15) ret = 7;
  if(8<=i&&i<=11&&8<=j&&j<=11) ret = 8;
  if(ret==-1) return ret;
  if(remain.at(ret)==0) return -1;
  else {
    remain.at(ret)--;
    return ret;
  }
}

struct action {
  char type;
  char direction;
  action(char type, char direction) : type(type), direction(direction) {}
};

vector<action> move_to(int n, int from_i, int from_j, int to_i, int to_j, vector<vector<int>>& graph, vector<string>& grid) {
  vector<action> actions;
  queue<pair<int, int>> q;
  vector<vector<pair<int,int>>> prev(n, vector<pair<int,int>>(n, {-1,-1}));
  q.push({from_i, from_j});
  while(q.size()) {
    auto [i, j] = q.front();
    q.pop();
    for(auto nv : graph[i*n+j]) {
      int ni = nv/n;
      int nj = nv%n;
      if (prev[ni][nj].first != -1) continue;
      prev[ni][nj] = {i, j};
      q.push({ni, nj});
    }
  }
  int cur_i = to_i;
  int cur_j = to_j;
  set<pair<int,int>> visited;
  visited.insert({cur_i, cur_j});
  vector<pair<int,int>> path;
  path.push_back({cur_i, cur_j});
  while (cur_i != from_i || cur_j != from_j) {
    auto [prev_i, prev_j] = prev[cur_i][cur_j];
    if (prev_i == -1) break;
    if (prev_i == cur_i) {
      if (prev_j < cur_j) {
        if(abs(prev_j-cur_j)<=1) actions.push_back(action('M', 'R'));
        else actions.push_back(action('S', 'R'));
      } else {
        if(abs(prev_j-cur_j)<=1) actions.push_back(action('M', 'L'));
        else actions.push_back(action('S', 'L'));
      }
    } else {
      if (prev_i < cur_i) {
        if(abs(prev_i-cur_i)<=1) actions.push_back(action('M', 'D'));
        else actions.push_back(action('S', 'D'));
      } else {
        if(abs(prev_i-cur_i)<=1) actions.push_back(action('M', 'U'));
        else actions.push_back(action('S', 'U'));
      }
    }
    cur_i = prev_i;
    cur_j = prev_j;
    visited.insert({cur_i, cur_j});
    path.push_back({cur_i, cur_j});
  }
  reverse(actions.begin(), actions.end());
  reverse(path.begin(), path.end());
  vector<action> ret;
  auto reverse_dir = [&](char dir) {
    if (dir == 'U') return 'D';
    if (dir == 'D') return 'U';
    if (dir == 'L') return 'R';
    if (dir == 'R') return 'L';
    return dir;
  };
  int rot = 0;
  auto rot_to_dir = [&](int rot) {
    if (rot == 0) return 'R';
    if (rot == 1) return 'L';
    if (rot == 2) return 'D';
    if (rot == 3) return 'U';
    return ' ';
  };
  auto is_in = [&](int i, int j, int n) {
    return i >= 0 && i < n && j >= 0 && j < n;
  };
  rep(i,actions.size()) {
    ret.push_back(actions[i]);
    if(actions[i].type != 'M') continue;
    bool is_obstacle = false;
    for(int di = -1; di <= 1; di++) {
      for(int dj = -1; dj <= 1; dj++) {
        if (di == 0 && dj == 0) continue;
        int ni = path[i].first + di + dir[rot].first;
        int nj = path[i].second + dj + dir[rot].second;
        if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
        if (grid[ni][nj] == '#') {
          is_obstacle = true;
          break;
        }
      }
      if (is_obstacle) break;
    }
    if (is_obstacle) continue;
    if(points.count({path[i].first + dir[rot].first, path[i].second + dir[rot].second})) continue;
    if(visited.count({path[i].first + dir[rot].first, path[i].second + dir[rot].second})) continue;
    if(!is_in(path[i].first + dir[rot].first, path[i].second + dir[rot].second, n)) continue;
    int check_result = check(path[i].first + dir[rot].first, path[i].second + dir[rot].second);
    if(check_result != -1) {
      ret.push_back(action('A', rot_to_dir(rot)));
      grid[path[i].first + dir[rot].first][path[i].second + dir[rot].second] = '#';
    }
    rot++;
    if(rot == 4) rot = 0;
  }
  return ret;
}

vector<vector<int>> get_graph(int n, vector<string>& grid) {
  vector<vector<int>> graph(n*n, vector<int>());
  auto conv = [&](int i, int j) {
    return i*n+j;
  };
  auto is_in = [&](int i, int j, int n) {
    return i >= 0 && i < n && j >= 0 && j < n;
  };
  rep(i,n) rep(j,n) {
    if (grid[i][j] == '#') continue;
    for(auto [di, dj] : dir) {
      int ni = i + di;
      int nj = j + dj;
      if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
      if (grid[ni][nj] == '#') continue;
      graph[conv(i,j)].push_back(conv(ni,nj));
      while (1) {
        ni += di;
        nj += dj;
        if (!is_in(ni,nj,n) || grid[ni][nj] == '#') {
          ni -= di;
          nj -= dj;
          if(ni!=i+di || nj!=j+dj) graph[conv(i,j)].push_back(conv(ni,nj));
          break;
        }
      }
    }
  }
  return graph;
}

vector<action> solve(int n,int m, vector<int>& a, vector<int>& b) {
  vector<action> actions;
  vector<string> grid(n, string(n, '.'));
  int cur_i = a.front();
  int cur_j = b.front();
  reps(i,1,m) {
    int next_i = a[i];
    int next_j = b[i];
    auto g = get_graph(n, grid);
    auto acts = move_to(n, cur_i, cur_j, next_i, next_j, g, grid);
    actions.insert(actions.end(), acts.begin(), acts.end());
    cur_i = next_i;
    cur_j = next_j;
  }
  return actions;
}

int main() {
  timer.start();
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  // receive input
  int n, m;
  cin >> n >> m;
  vector<int> a(m), b(m);
  rep(i, m) {
    cin >> a[i] >> b[i];
    points.insert({a[i], b[i]});
  }

  auto ans = solve(n, m, a, b);
  for(auto [type, direction] : ans) {
    cout << type << " " << direction << "\n";
  }
  cout.flush();

  return 0;
}
