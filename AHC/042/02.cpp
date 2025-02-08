#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
#define reps(i, a, n) for (int i = (a); i < (n); ++i)
#define rep(i, n) reps(i, 0, n)
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};
constexpr string_view DIRECTION = "RLDU";
constexpr int R = 0;
constexpr int L = 1;
constexpr int D = 2;
constexpr int U = 3;
constexpr int INF = 1<<30;

int rev(int& i) {
  return i%2?i-1:i+1;
};

bool is_vertical(const int& i) {
  return i>=2;
};

void print_ans(const vector<tuple<int,int,int>>& drop, const bool& need_rev = true) {
  int n = drop.size();
  rep(i,n) {
    auto [direction,distance,num] = drop.at(i);
    rep(_,distance) cout << DIRECTION.at(direction) << " " << num << endl;
  }
  if(!need_rev) return;
  rep(i,n) {
    auto [direction,distance,num] = drop.at(n-1-i);
    rep(_,distance) cout << DIRECTION.at(rev(direction)) << " " << num << endl;
  }
}

pair<bool,vector<string>> is_valid(const int& n,vector<string> s,const vector<tuple<int,int,int>>& movement) {
  auto in = [&](const unsigned int& i, const unsigned int& j) -> bool {
    return i<n && j<n;
  };
  for(const auto& [direction,distance,num] : movement) {
    auto [di,dj] = dir.at(direction);
    if(is_vertical(direction)) {
      if(direction==U) {
        rep(i,n) {
          if(i+distance<n) s.at(i).at(num) = s.at(i+distance).at(num);
          else s.at(i).at(num) = '.';
        }
      } else { // when Down
        for(int i=n-1;i>=0;i--) {
          if(i-distance>=0) s.at(i).at(num) = s.at(i-distance).at(num);
          else s.at(i).at(num) = '.';
        }
      }
    } else { // when horizonal
      if(direction==L) {
        rep(j,n) {
          if(j+distance<n) s.at(num).at(j) = s.at(num).at(j+distance);
          else s.at(num).at(j) = '.';
        }
      } else { // when Right
        for(int j=n-1;j>=0;j--) {
          if(j-distance>=0) s.at(num).at(j) = s.at(num).at(j-distance);
          else s.at(num).at(j) = '.';
        }
      }
    }
  }
  rep(i,n) rep(j,n) {
    if(s.at(i).at(j)!='x') continue;
    bool ok = false;
    rep(d,4) {
      int ci = i;
      int cj = j;
      auto [di,dj] = dir.at(d);
      while(in(ci,cj)&&s.at(ci).at(cj)!='o') ci+=di,cj+=dj;
      ok |= !in(ci,cj);
    }
    if(!ok) return pair(false,vector<string>());
  }
  return pair(true,s);
}

void solve(const int& n, vector<string>& s, vector<vector<pair<int,int>>>& beacon) {
  
  auto in = [&](unsigned int i, unsigned int j) -> bool {
    return i<n && j<n;
  };
  
  rep(i,n) rep(j,n) {
    if(s.at(i).at(j)!='x') continue;
    s.at(i).at(j) = '.';
    int c = INF;
    // tuple(direction, distance, row/column num)
    vector<tuple<int,int,int>> mv;
    int dir_i = -1;
    rep(d,4) {
      auto [di,dj] = dir.at(d);
      int ci = i;
      int cj = j;
      while(in(ci,cj)&&s.at(ci).at(cj)!='o') {
        ci += di;
        cj += dj;
      }
      if(!in(ci,cj)) {
        if(chmin(c,abs(ci-i)+abs(cj-j))) mv = {tuple(d,abs(ci-i)+abs(cj-j),is_vertical(d)?j:i)};
        ci = i;
        cj = j;
        while(in(ci,cj)&&s.at(ci).at(cj)!='o') {
          auto [beacon_dir,beacon_dist] = beacon.at(ci).at(cj);
          if(beacon_dir!=-1) {
            if(chmin(c,abs(ci-i)+abs(cj-j)+beacon_dist)) {
              mv = {tuple(d,abs(ci-i)+abs(cj-j),is_vertical(d)?j:i),tuple(beacon_dir,beacon_dist,is_vertical(beacon_dir)?cj:ci)};
            }
          }
          ci += di;
          cj += dj;
        }
      }
    }
    int ci = i;
    int cj = j;
    auto [di,dj] = dir.at(rev(get<0>(mv.back())));
    ci += di;
    cj += dj;
    if(is_vertical(get<0>(mv.back()))) cj = get<2>(mv.back());
    else ci = get<2>(mv.back());
    int a = 0;
    while(in(ci,cj)&&s.at(ci).at(cj)!='o') {
      if(s.at(ci).at(cj)=='x') {
        a = is_vertical(get<0>(mv.back()))?abs(ci-i):abs(cj-j);
        s.at(ci).at(cj) = '.';
      }
      ci += di;
      cj += dj;
    }
    get<1>(mv.back()) += a;
    auto [valid,next_s] = is_valid(n,s,mv);
    if(valid) swap(s,next_s);
    print_ans(mv, !valid);
  }
}

vector<vector<pair<int,int>>> calc_beacon(int& n,vector<string>& s) {
  auto in = [&](unsigned int i, unsigned int j) -> bool {
    return i<n && j<n;
  };
  // pair(direction, distance)
  vector ret(n,vector(n,pair<int,int>()));
  
  rep(i,n) rep(j,n) {
    if(s.at(i).at(j)=='o') continue;
    int c = INF;
    int dir_i = -1;
    rep(d,4) {
      auto [di,dj] = dir.at(d);
      int ci = i;
      int cj = j;
      while(in(ci,cj)&&s.at(ci).at(cj)!='o') {
        ci += di;
        cj += dj;
      }
      if(!in(ci,cj)) if(chmin(c,abs(ci-i)+abs(cj-j))) dir_i = d;
    }
    ret.at(i).at(j) = pair(dir_i,c);
  }
  
  return ret;
}

int main() {
  int n;cin>>n;
  vector<string> s(n);cin>>s;
  auto beacon = calc_beacon(n,s);
  solve(n,s,beacon);

  return 0;
}
