#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using vvi = vector<vector<int>>;
using rpqi = priority_queue<int, vector<int>, greater<int>>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

bool is_snuke(char c,char d) {
  return c=='s'&&d=='n'
  || c=='n'&&d=='u'
  || c=='u'&&d=='k'
  || c=='k'&&d=='e'
  || c=='e'&&d=='s';
}

int h,w;
vector<vector<int>> g;
bool ans = false;
vector<bool> seen;

void dfs(int v) {
  if(v==h*w-1) ans=true;
  if(seen.at(v)) return;
  seen.at(v) = true;
  for(int ele : g.at(v)) {
    dfs(ele);
  }
}

int main() {
  cin>>h>>w;
  g.resize(h*w);
  seen.resize(h*w);
  vector<string> s(h);
  rep(i,h) cin>>s.at(i);
  rep(i,h) rep(j,w) {
    if(i!=0) {
      if(is_snuke(s.at(i).at(j),s.at(i-1).at(j))) g.at(i*w+j).push_back((i-1)*w+j);
    }
    if(i!=h-1) {
      if(is_snuke(s.at(i).at(j),s.at(i+1).at(j))) g.at(i*w+j).push_back((i+1)*w+j);
    }
    if(j!=0) {
      if(is_snuke(s.at(i).at(j),s.at(i).at(j-1))) g.at(i*w+j).push_back(i*w+j-1);
    }
    if(j!=w-1) {
      if(is_snuke(s.at(i).at(j),s.at(i).at(j+1))) g.at(i*w+j).push_back(i*w+j+1);
    }
  }
  dfs(0);
  if(s.at(0).at(0)=='s' && ans) cout << "Yes" << endl;
  else cout << "No" << endl;

  exit(0);
}
