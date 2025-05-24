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
int n,m,len;
vector<char> c;
vector<vector<int>> a;

void solve(vector<string> &s, vector<int> &p, vector<int> &rank) {
  rep(i,m) c.at(i) = 'a'+i%6;
  vector cnt(m,vector<int>(m,0));
  vector<int> ord(n);
  rep(i,n) ord.at(i) = i;
  sort(ord.begin(),ord.end(),[&](int ii,int jj) -> bool {
    return rank.at(ii) > rank.at(jj);
  });
  rep(ii,2) {
    int j = ord.at(ii);
    string str = s.at(j);
    rep(i,str.size()-1) {
      int from = mt()%2*6;
      int to = mt()%2*6;
      from = 0;to = 0;
      cnt.at(str.at(i)-'a'+from).at(str.at(i+1)-'a'+to) += rank.at(j);
    }
  }
  vector<int> sum(m,0);
  rep(i,m) rep(j,m) sum.at(i) += cnt.at(i).at(j);
  rep(i,m) rep(j,m) {
    if(sum.at(i)==0) continue;
    a.at(i).at(j) = cnt.at(i).at(j)*100/sum.at(i);
  }
  rep(i,m) {
    int x = 0;
    rep(j,m) x += a.at(i).at(j);
    x = 100 - x;
    int ma = -1;
    int idx = -1;
    rep(j,m) {
      if(a.at(i).at(j)>ma) {
        idx = j;
        ma = a.at(i).at(j);
      }
    }
    a.at(i).at(idx) += x;
  }
}

int main() {
  timer.start();
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  // receive input
  cin>>n>>m>>len;
  vector<string> s(n);
  vector<int> p(n);
  rep(i,n) cin>>s.at(i)>>p.at(i);
  c.resize(m);
  a.resize(m);
  rep(i,m) a.at(i).resize(m);
  vector<int> rank(n,-1);
  rep(i,n) {
    rep(j,17) {
      if(p.at(i)<(j+1)*1000) {
        rank.at(i) = j;
        break;
      }
    }
  }
  solve(s,p,rank);
  rep(i,m) {
    cout << c.at(i);
    rep(j,m) cout << " " << a.at(i).at(j);
    cout << "\n";
  }
  cout.flush();

  return 0;
}
