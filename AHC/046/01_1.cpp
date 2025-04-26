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

struct action {
  char type;
  char direction;
  action(char type, char direction) : type(type), direction(direction) {}
};

vector<action> move_to(int n, int from_i, int from_j, int to_i, int to_j, vector<vector<int>>& graph) {
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
  }
  reverse(actions.begin(), actions.end());
  return actions;
}

vector<action> solve(int n,int m, vector<int>& a, vector<int>& b) {
  vector<action> actions;
  vector graph(n*n, vector<int>());
  auto conv = [&](int i, int j) {
    return i*n+j;
  };
  rep(i,n) rep(j,n) {
    for(auto [di, dj] : dir) {
      int ni = i + di;
      int nj = j + dj;
      if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
      graph[conv(i,j)].push_back(conv(ni,nj));
    }
    if(i>1) graph[conv(i,j)].push_back(conv(0,j));
    if(j>1) graph[conv(i,j)].push_back(conv(i,0));
    if(i<n-2) graph[conv(i,j)].push_back(conv(n-1,j));
    if(j<n-2) graph[conv(i,j)].push_back(conv(i,n-1));
  }
  int cur_i = a.front();
  int cur_j = b.front();
  reps(i,1,m) {
    int next_i = a[i];
    int next_j = b[i];
    auto acts = move_to(n, cur_i, cur_j, next_i, next_j, graph);
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
  }

  auto ans = solve(n, m, a, b);
  for(auto [type, direction] : ans) {
    cout << type << " " << direction << "\n";
  }
  cout.flush();

  return 0;
}
