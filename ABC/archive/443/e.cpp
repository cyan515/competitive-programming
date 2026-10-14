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
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int T;cin>>T;
  while(T--) {
    ll n,c;cin>>n>>c;c--;
    vector<string> s(n);cin>>s;
    rep(i,n) for(int j=n-1;j>=0;j--) {
      if(s.at(j).at(i)=='#') {
        s.at(j).at(i) = '$';
        break;
      }
    }
    vector seen(n,vector<bool>(n,false));
    seen.at(n-1).at(c) = true;
    queue<pair<int,int>> q;
    q.push(pair(n-1,c));
    auto in = [&](unsigned i,unsigned j) -> bool {
      return i<n&&j<n;
    };
    while(q.size()) {
      auto [vi,vj] = q.front();q.pop();
      if(vi==0) continue;
      reps(d,-1,2) {
        int ni = vi-1;
        int nj = vj+d;
        if(!in(ni,nj)) continue;
        if(seen.at(ni).at(nj)) continue;
        if(s.at(ni).at(nj)=='#') continue;
        seen.at(ni).at(nj) = true;
        q.push(pair(ni,nj));
        if(s.at(ni).at(nj)=='$') {
          while(ni) {
            ni--;
            seen.at(ni).at(nj) = true;
            q.push(pair(ni,nj));
          }
        }
      }
    }
    // rep(j,n) {
    //   bool ok = false;
    //   for(int i=n-1;i>=0;i--) {
    //     if(s.at(i).at(j)=='$' && seen.at(i).at(j)) ok = true;
    //     if(ok) seen.at(i).at(j) = true;
    //   }
    // }
    string ans = "";
    rep(i,n) {
      if(seen.at(0).at(i)) ans.push_back('1');
      else ans.push_back('0');
    }
    cout << ans << endl;
  }

  return 0;
}
