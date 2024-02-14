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

int n;
vector<int> a;
set<int> seen;
set<int> dead;
set<int> vs;
vector<int> ansp;
vector<int> p;

void dfs(int v) {
  seen.insert(v);
  p.push_back(v);
  if(seen.count(a.at(v)) && !dead.count(a.at(v))) {
    set<int> st;
    while(!st.count(a.at(v))) {
      ansp.push_back(p.back());
      st.insert(p.back());
      p.pop_back();
    }
    cout << ansp.size() << endl;
    rep(i,ansp.size()) {
      cout << ansp.at(ansp.size()-1-i)+1 << " ";
    }
    cout << endl;
    exit(0);
  }
  if(seen.count(a.at(v))) return;
  dfs(a.at(v));
  p.pop_back();
}

int main() {
  cin>>n;
  a.resize(n);
  rep(i,n) cin>>a.at(i),a.at(i)--;
  rep(i,n) vs.insert(i);
  while(vs.size()) {
    int v = *vs.begin();
    vs.erase(v);
    dfs(v);
    for(int ele : seen) dead.insert(ele);
    seen.clear();
    p.clear();
  }

  exit(0);
}
