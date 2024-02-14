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

int main() {
  int n;cin>>n;
  string s;cin>>s;
  int sum = 0;
  set<int> start;
  map<int,int> end;
  stack<int> tmps;
  rep(i,n) {
    if(s.at(i)=='(') {
      start.insert(i);
      tmps.push(i);
      sum++;
    }
    if(s.at(i)==')') {
      if(sum==0) continue;
      sum--;
      int tmp = tmps.top();
      tmps.pop();
      end.insert(make_pair(tmp,i));
    }
  }
  while(!tmps.empty()) {
    int tmp = tmps.top();
    tmps.pop();
    start.erase(tmp);
  }
  rep(i,n) {
    if(start.find(i)!=start.end()) {
      i = end.at(i);
      continue;
    }
    if(i>=n) continue;
    cout << s.at(i);
  }
  cout << endl;

  exit(0);
}
