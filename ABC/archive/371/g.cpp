#include <bits/stdc++.h>
#include <atcoder/dsu>
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
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

// 座標圧縮
class coordinate_compression {
public:
  coordinate_compression(const vector<long long>& data) {
    _sorted = data;
    sort(_sorted.begin(),_sorted.end());
    _sorted.erase(unique(_sorted.begin(),_sorted.end()),_sorted.end());
  }
  
  /**
   * @fn
   * 受け取った値を座標圧縮した場合いくつになるかを返す。
   * 計算量 O(logN)
   * 
   * @param val 圧縮前の値
   */
  long long compress(const long long& val) const {
    long long ret = lower_bound(_sorted.begin(),_sorted.end(),val) - _sorted.begin();
    return ret;
  }
  
private:
  vector<long long> _sorted;
};

int main() {
  int n;cin>>n;
  vector<int> p(n),a(n);cin>>p>>a;
  rep(i,n) p.at(i)--,a.at(i)--;
  vector<int> g(n);
  dsu uf(n);
  rep(i,n) {
    g.at(a.at(i)) = a.at(p.at(i));
    uf.merge(i,p.at(i));
  }
  map<int,int> mi;
  map<int,vector<int>> mp;
  for(auto vec : uf.groups()) {
    int l = uf.leader(vec.front());
    int tmp = INF;
    for(auto ele : vec) {
      chmin(tmp,a.at(ele));
    }
    mi[l] = tmp;
    mp[l] = vec;
  }
  set<int> seen;
  vector<int> memo(n+1,-1);
  rep(i,n) {
    int leader = uf.leader(i);
    if(seen.count(leader)) continue;
    auto vec = mp[leader];
    if(memo.at(uf.size(leader)) != -1) {
      rep(j,memo.at(uf.size(leader))) {
        map<int,int> m;
        for(auto ele : vec) {
          m[ele] = a.at(p.at(ele));
        }
        for(auto [k,v] : m) {
          a.at(k) = v;
        }
      }
      continue;
    }
    seen.insert(leader);
    int tmp = mi[leader];
    int cnt = 0;
    while(a.at(i)!=tmp) {
      cnt++;
      map<int,int> m;
      for(auto ele : vec) {
        m[ele] = a.at(p.at(ele));
      }
      for(auto [k,v] : m) {
        a.at(k) = v;
      }
    }
    memo.at(uf.size(leader)) = cnt;
    for(int i=uf.size(leader);i<n;i+=uf.size(leader)) {
      memo.at(i) = cnt;
    }
    for(int i=1;i<leader;i++) {
      
    }
  }
  
  rep(i,n) {
    if(i) cout << " ";
    cout << a.at(i)+1;
  }
  cout << endl;

  return 0;
}
