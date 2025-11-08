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
// 左から、右から、上から、下から
// 右へ、　左へ、　下へ、　上へ
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int T;cin>>T;
  while(T--) {
    ll h,w;cin>>h>>w;
    vector<string> s(h);cin>>s;
    vector dists(h,vector(w,vector<int>(4,INF)));
    dists.at(0).at(0).at(0) = 0;
    vector<vector<char>> x = {
      {'A','-','B','C',},
      {'-','A','C','B',},
      {'B','C','A','-',},
      {'C','B','-','A',},
    };
    auto ref = [&](int from,char mir) -> int {
      if(mir=='A') return from;
      else if(mir=='B') {
        if(from==0) return 2;
        else if(from==1) return 3;
        else if(from==2) return 0;
        else return 1;
      } else {
        if(from==0) return 3;
        else if(from==1) return 2;
        else if(from==3) return 0;
        else return 1;
      }
    };
    // i,j,dir
    deque<tuple<int,int,int>> q;
    q.push_back({0,0,0});
    int ans = INF;
    auto in = [&](unsigned i,unsigned j) -> bool {
      return i<h&&j<w;
    };
    while(q.size()) {
      auto [vi,vj,vd] = q.front();q.pop_front();
      for(auto c : "ABC") {
        int cost = c==s.at(vi).at(vj)?0:1;
        int nd = ref(vd,c);
        auto [di,dj] = dir.at(nd);
        int ni = vi+di;
        int nj = vj+dj;
        if(!in(ni,nj)) {
          if(vi==h-1&&vj==w-1&&nd==0) chmin(ans,dists.at(vi).at(vj).at(vd)+cost);
          continue;
        }
        if(chmin(dists.at(ni).at(nj).at(nd),dists.at(vi).at(vj).at(vd)+cost)) {
          if(cost) q.push_back({ni,nj,nd});
          else q.push_front({ni,nj,nd});
        }
      }
    }
    if(ans==INF) ans = -1;
    cout<<ans<<endl;
  }

  return 0;
}
