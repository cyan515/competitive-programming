// https://atcoder.jp/contests/abc445/tasks/abc445_e
#include <bits/stdc++.h>
#include <atcoder/modint>
using mint = atcoder::modint998244353;
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
// https://dekavit.net/algorithm/#%E9%AB%98%E9%80%9F%E7%B4%A0%E5%9B%A0%E6%95%B0%E5%88%86%E8%A7%A3
//最初にSPFを実行
vector<int> SPF(int N){
    vector<int> ans(N+1);
    for(int i=0;i<=N;i++){
        ans[i]=i;
    }
    for(int i=2;i*i<=N;i++){
        if(ans[i]==i){
            for(int j=i*i;j<=N;j+=i){
                ans[j]=i;
            }
        }
    }
    return ans;
}

map<int,int> FPF(int X,vector<int> &spf){
    map<int,int> ans;
    while(X!=1){
        ans[spf[X]]++;
        X/=spf[X];
    }
    return ans;
}

// //使用例
// int main(){
//     auto spf=SPF(200000);//入力の最大値まででSPF配列を作成
//     int N;
//     cin>>N;
//     auto ans=FPF(N,spf);
//     auto itr=ans.begin();
//     for(int i=0;i<ans.size();i++,itr++){
//         cout<<(*itr).first<<"^"<<(*itr).second<<endl;
//     }
//     return 0;
// }

int main() {
  int T;cin>>T;
  auto spf = SPF(10000100);
  while(T--) {
    int n;cin>>n;
    vector<int> a(n);cin>>a;
    // prime, top[count,idx], second[count,idx]
    map<int,pair<pair<int,int>,pair<int,int>>> top;
    rep(i,n) {
      auto p = FPF(a.at(i),spf);
      for(auto [k,v]:p) {
        auto it = top.find(k);
        if(it==top.end()) {
          top[k] = pair(pair(v,i),pair(0,-1));
        } else {
          auto& [_,x] = *it;
          auto& [t,s] = x;
          if(t.first<v) {
            s = t;
            t = pair(v,i);
          } else if(s.first<v) {
            s = pair(v,i);
          }
        }
      }
    }
    mint tot = 1;
    for(auto [k,v]:top) tot *= mint(k).pow(v.first.first);
    rep(i,n) {
      if(i)cout<<" ";
      auto p = FPF(a.at(i),spf);
      mint ans = tot;
      for(auto [k,v]:p) {
        if(top[k].first.second==i) {
          ans /= mint(k).pow(top[k].first.first);
          ans *= mint(k).pow(top[k].second.first);
        }
      }
      cout<<ans.val();
    }
    cout<<endl;
  }

  return 0;
}
