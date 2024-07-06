#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
const string Yes = "Yes";
const string No = "No";
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

vector<vector<ll>> tsp(vector<vector<ll>>& dist) {
  int n = dist.size();
  vector<vector<ll>> ret((1<<n),vector<ll>(n,LINF));
  rep(bit,1<<n) rep(from,n) {
    if(((bit&(1<<from))==0)&&(bit!=0)) continue;
    rep(to,n) {
        if(((bit&(1<<to))==0)&&(dist.at(from).at(to)<LINF)) {
            int v = (bit|(1<<to));
            ret.at(v).at(to) = min(ret.at(v).at(to),ret.at(bit).at(from)+dist.at(from).at(to));
        }
    }
  }
  return ret;
}

int main() {
  ll n;cin>>n;
  n += 2;
  string s,t;cin>>s>>t;
  s += "..";
  t += "..";
  map<string,vector<string>> g;
  string u = s;
  sort(all(u));
  do {
    int idx = -1;
    rep(i,n-1) {
      if(u.at(i)=='.'&&u.at(i+1)=='.') idx = i;
    }
    if(idx==-1) continue;
    rep(i,n-1) {
      if(u.at(i)=='.'||u.at(i+1)=='.') continue;
      string v = u;
      swap(v.at(i),v.at(idx));
      swap(v.at(i+1),v.at(idx+1));
      g[u].push_back(v);
    }
  } while(next_permutation(all(u)));
  map<string,int> dist;
  queue<string> q;
  q.push(s);
  while(q.size()) {
    string v = q.front();q.pop();
    for(auto nv : g[v]) {
      if(dist.count(nv)) continue;
      q.push(nv);
      dist[nv] = dist[v] + 1;
    }
  }
  auto it = dist.find(t);
  if(it==dist.end()) cout << -1 << endl;
  else cout << (*it).second << endl;

  return 0;
}
