#include <bits/stdc++.h>
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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

// 2進数表現の string を受け取って10進数に変換して返す
// 1 以外は 0 とみなされる
long long binary_to_decimal(const string& s) {
  int len = s.length();
  long long ret = 0;
  for(int i=0;i<len;i++) {
    ret *= 2LL;
    if(s.at(i)=='1') ret++;
  }
  return ret;
}

/**
 * @brief 巡回セールスマン問題
 * @param graph 隣接行列表現によるグラフ。
 * @param dists dists[i][j] = 初期状態において訪問した集合が i で最後に訪問した頂点が j のときのコスト
 */
void tsp(const vector<vector<ll>>& graph, vector<vector<ll>>& dists, set<ll>& banned) {
  const ll LINF = 3001001001001001001;
  int n = graph.size();
  rep(bit,1<<n) rep(from,n) {
    if(((bit&(1<<from))==0)&&(bit!=0)) continue;
    rep(to,n) {
      if(((bit&(1<<to))==0)&&(graph.at(from).at(to)<LINF)) {
        ll v = (bit|(1<<to));
        if(banned.count(v)) continue;
        dists.at(v).at(to) = min(dists.at(v).at(to),dists.at(bit).at(from)+graph.at(from).at(to));
      }
    }
  }
}

int main() {
  int T;cin>>T;
  while(T--) {
    int n;cin>>n;
    string s;cin>>s;
    set<ll> banned;
    rep(i,s.size()) {
      if(s.at(i)=='1') banned.insert(i+1);
    }
    vector dists(1<<n,vector<ll>(n,INF));
    dists.at(0).at(0) = 0;
    vector g(n,vector<ll>(n,1));
    tsp(g,dists,banned);
    ll d = INF;
    rep(i,n) d = min(d,dists.at((1<<n)-1).at(i));
    cout << (d==INF?No:Yes) << endl;
  }

  return 0;
}
