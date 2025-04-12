#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;
using namespace atcoder;
#define reps(i, a, n) for (int i = (a); i < (int) (n); ++i)
#define rep(i, n) reps(i, 0, n)
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
const int INF = (1<<30)-1;
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
const double TIME_LIMIT = 1.0;
  
struct city_group {
  city_group() = default;
  explicit city_group(vector<int>& c, vector<pair<int, int>>& e)
    : cities(move(c)), edges(move(e)) {
    }

  vector<int> cities;
  vector<pair<int, int>> edges;
};

struct oracle_query {
  oracle_query() = default;
  explicit oracle_query(vector<int>& c) 
    : cities(move(c)) {}
  
  vector<int> cities;
};

tuple<double, city_group, city_group> swap_city(city_group a, int ai, city_group b, int bi, vector<double>& x, vector<double>& y) { 
  // 既存の MST コストを計算するラムダ
  auto calc_cost = [&](const city_group& g) -> double {
    double ret = 0.0;
    for (auto [u, v] : g.edges)
      ret += hypot(x.at(u) - x.at(v), y.at(u) - y.at(v));
    return ret;
  };
  double a_cost = calc_cost(a);
  double b_cost = calc_cost(b);

  // 都市の入れ替え
  auto a_cities = a.cities;
  auto b_cities = b.cities;
  swap(a_cities.at(ai), b_cities.at(bi));

  // 入れ替え後のグループについて MST を再計算するラムダ
  auto compute_mst = [&](const vector<int> &cities) -> pair<double, vector<pair<int, int>>> {
    int n = cities.size();
    // 各都市ペア間の距離を辺としてリストアップ（辺の端点は都市集合内のインデックス）
    vector<tuple<double, int, int>> edges;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        double w = hypot(x.at(cities.at(i)) - x.at(cities.at(j)), y.at(cities.at(i)) - y.at(cities.at(j)));
        edges.push_back({w, i, j});
      }
    }
    sort(edges.begin(), edges.end());
    dsu uf(n);

    double total = 0.0;
    vector<pair<int, int>> mst_edges;
    // Kruskal で MST を構築
    for (auto &[w, i, j] : edges) {
      if(uf.same(i,j)) continue;
      uf.merge(i, j);
      total += w;
      // 辺は実際のグローバルな都市インデックスで記録する
      mst_edges.push_back({cities.at(i), cities.at(j)});
    }
    return pair(total, mst_edges);
  };

  auto [new_a_cost, new_a_edges] = compute_mst(a_cities);
  auto [new_b_cost, new_b_edges] = compute_mst(b_cities);

  double diff = (new_a_cost + new_b_cost) - (a_cost + b_cost);
  return {diff, city_group(a_cities, new_a_edges), city_group(b_cities, new_b_edges)};
}

vector<city_group> climbing(vector<city_group> ans, vector<double>& x, vector<double>& y) {
  double cur_score = 0.0;
  for(auto g : ans) for(auto [u,v] : g.edges) cur_score += hypot(x.at(u)-x.at(v),y.at(u)-y.at(v));
  auto cur_ans = ans;
  uniform_int_distribution<int> dist(0);
  int tot = 0;
  int upd = 0;
  while(1) {
    tot++;
    if(timer.get_time()>TIME_LIMIT) break;
    int i = dist(mt)%ans.size();
    int j = dist(mt)%ans.size();
    if(i==j) continue;
    auto [diff, a, b] = swap_city(cur_ans.at(i),dist(mt)%cur_ans.at(i).cities.size(),cur_ans.at(j),dist(mt)%cur_ans.at(j).cities.size(),x,y);
    if(chmin(cur_score, cur_score + diff)) {
      upd++;
      cur_ans.at(i) = a;
      cur_ans.at(j) = b;
    }
  }
  cerr << tot << endl << upd << endl;
  return cur_ans;
}

vector<city_group> solve(int n, int m, vector<int>& group_size, vector<double>& x, vector<double>& y) {
  vector<city_group> ret(m);
  vector dists(n,vector<double>(n));
  rep(i,n) rep(j,n) {
    dists.at(i).at(j) = hypot(x.at(i)-x.at(j),y.at(i)-y.at(j));
  }
  priority_queue<pair<int,int>> q;
  rep(i,m) q.push(pair(group_size.at(i),i));
  vector<bool> seen(n,false);
  while(q.size()) {
    auto [sz, idx] = q.top();q.pop();
    int s = -1;
    vector<double> cost(n,INF);
    vector<int> pv(n,-1);
    rep(i,n) {
      if(!seen.at(i)) {
        s = i;
        cost.at(s) = 0;
        break;
      }
    }
    vector<int> cities(sz);
    vector<pair<int,int>> edges(sz-1);
    while(sz--) {
      int v = -1;
      double mi = INF;
      rep(i,n) {
        if(seen.at(i)) continue;
        if(chmin(mi,cost.at(i))) v = i;
      }
      seen.at(v) = true;
      cities.at(sz) = v;
      if(pv.at(v)!=-1) edges.at(sz) = pair(v,pv.at(v));
      rep(i,n) if(chmin(cost.at(i),dists.at(v).at(i))) pv.at(i) = v;
    }
    ret.at(idx) = city_group(cities, edges);
  }
  return ret;
}

vector<pair<int,int>> consult_oracle(oracle_query& q) {
  cout << "? " << q.cities.size();
  for(auto ele : q.cities) cout << " " << ele;
  cout << endl;
  vector<pair<int,int>> ret(q.cities.size()-1);
  rep(i,q.cities.size()-1) {
    int u,v;cin>>u>>v;
    ret.at(i) = pair(u,v);
  }
  return ret;
}

pair<int, int> normalize_edge(int a, int b) {
  return {min(a, b), max(a, b)};
}

void update_edges(vector<pair<int, int>>& edges, const vector<pair<int, int>>& edges_to_delete, const vector<pair<int, int>>& new_edges) {
  set<pair<int, int>> delete_set;
  for (auto e : edges_to_delete) {
    delete_set.insert(normalize_edge(e.first, e.second));
  }
  vector<pair<int, int>> updated_edges;
  for (auto e : edges) {
    if (delete_set.count(normalize_edge(e.first, e.second)) == 0) {
      updated_edges.push_back(e);
    }
  }
  for (auto e : new_edges) {
    updated_edges.push_back(e);
  }

  edges = move(updated_edges);
}

void adjust_answer(vector<city_group>& ans, vector<double>& x, vector<double>& y, int Q, int q_lim) {
  vector<int> ord(ans.size());
  rep(i,ans.size()) ord.at(i) = i;
  sort(ord.begin(), ord.end(), [&](int ii,int jj) -> bool {
    return ans.at(ii).cities.size() > ans.at(jj).cities.size();
  });
  int n = x.size();
  vector graph(n, set<int>());
  for(auto [_,edges] : ans) {
    for(auto [u,v] : edges) {
      graph.at(u).insert(v);
      graph.at(v).insert(u);
    }
  }
  for(auto i : ord) {
    auto [cities, edges] = ans.at(i);
    if(cities.size()<=2) break;
    if((int)cities.size()<=q_lim) {
      oracle_query query(cities);
      ans.at(i).edges = consult_oracle(query);
      if(--Q==0) return;
      continue;
    }
    int time = cities.size() / 2;
    uniform_int_distribution<int> dist(0, cities.size()-1);
    while(time--) {
      vector<pair<int,int>> edges_to_delete;
      set<int> st;
      auto dfs = [&](auto self, int pv, int v) -> void {
        if ((int)st.size() == q_lim) return;
        st.insert(v);
        if(pv!=-1) edges_to_delete.push_back(pair(pv,v));
        for (auto nv : graph.at(v)) {
          if (st.count(nv)) continue;
          if ((int)st.size() == q_lim) return;
          self(self, v, nv);
        }
      };
      int target = cities.at(time*2);
      dfs(dfs, -1, target);
      vector<int> vec(st.begin(), st.end());
      oracle_query query(vec);
      // delete edges
      for(auto [u,v] : edges_to_delete) {
        graph.at(u).erase(v);
        graph.at(v).erase(u);
      }
      auto new_edges = consult_oracle(query);
      // add edges
      for(auto [u,v] : new_edges) {
        graph.at(u).insert(v);
        graph.at(v).insert(u);
      }
      update_edges(edges, edges_to_delete, new_edges);
      ans.at(i).edges = edges;
      if(--Q==0) return;
    }
  }
}

void print_answer(vector<city_group>& ans) {
  cout << "!" << endl;
  for(auto [cities,edges] : ans) {
    rep(i,cities.size()) {
      if(i) cout << " ";
      cout << cities.at(i);
    }
    cout << endl;
    for(auto [u,v] : edges) {
      cout << u << " " << v << endl;
    }
  }
}

int main() {
  timer.start();
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  // receive input
  int n,m,query_cnt,query_size_lim,width_lim;
  cin>>n>>m>>query_cnt>>query_size_lim>>width_lim;
  vector<int> group_size(m);
  rep(i,m) cin>>group_size.at(i);
  vector<tuple<int,int,int,int>> city_rect(n);
  rep(i,n) {
    int a,b,c,d;cin>>a>>b>>c>>d;
    city_rect.at(i) = tuple(a,b,c,d);
  }
  // process input
  vector<double> x(n), y(n);
  rep(i,n) {
    auto [a,b,c,d] = city_rect.at(i);
    x.at(i) = double(a + b) / 2.0;
    y.at(i) = double(c + d) / 2.0;
  }
  auto ans = solve(n, m, group_size, x, y);
  ans = climbing(ans, x, y);
  adjust_answer(ans, x, y, query_cnt, query_size_lim);
  print_answer(ans);

  return 0;
}
