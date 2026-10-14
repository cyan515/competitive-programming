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
  while(T--){
    ll n,m;cin>>n>>m;
    vector g(n,vector<int>());
    rep(i,m){
      int u,v;cin>>u>>v;u--;v--;
      g.at(u).push_back(v);
      g.at(v).push_back(u);
    }
    // https://qiita.com/kemkemG0/items/e9a39138ddb3afe22ec6
    vector<int> color(n,-1);//別途使うときに-1で初期化して、color[0]=0としてあげる必要がある
    bool ok=true;
    vector<int>cur,ans;
    auto dfs=[&](auto sel,int now) -> void {
      if(ans.size())return; 
    //二部グラフ判定
      for (auto next : g[now]) {
        if(ans.size())return;
        if (color[next] == color[now]) {
          ok=false;
          int base=0;
          rep(i,cur.size()){
            if(cur.at(i)==next){
              base=i;
              break;
            }
          }
          reps(i,base,cur.size())ans.push_back(cur.at(i));
          return ;
        }
        else if (color[next] == !color[now])continue;
        color[next] = !color[now];
        cur.push_back(next);
        sel(sel,next);
        cur.pop_back();
        if(ans.size())return;
      }
    };
    rep(i,n){
      if(color.at(i)!=-1)continue;
      color.at(i)=0;
      cur.push_back(i);
      dfs(dfs,(int)i);
      cur.pop_back();
      if(ans.size())break;
    }
    if(ans.empty())cout<<-1<<endl;
    else {
      cout<<ans.size()<<endl;
      rep(i,ans.size()){
        if(i)cout<<" ";
        cout<<ans.at(i)+1;
      }
      cout<<endl;
    }
  }

  return 0;
}
