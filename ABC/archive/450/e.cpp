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
  string x,y;cin>>x>>y;
  int n=x.size();
  int m=y.size();
  vector xc(n+1,vector<ll>(26,0));
  vector yc(m+1,vector<ll>(26,0));
  rep(i,n){
    xc.at(i+1).at(x.at(i)-'a')++;
    rep(j,26){
      xc.at(i+1).at(j)+=xc.at(i).at(j);
    }
  }
  rep(i,m){
    yc.at(i+1).at(y.at(i)-'a')++;
    rep(j,26){
      yc.at(i+1).at(j)+=yc.at(i).at(j);
    }
  }
  int Q;cin>>Q;
  vector<ll> fib;
  vector<ll> fa;
  vector<ll> fb;
  fa.push_back(1);
  fa.push_back(0);
  fb.push_back(0);
  fb.push_back(1);
  fib.push_back(n);
  fib.push_back(m);
  while(fib.at(fib.size()-1)+fib.at(fib.size()-2)<LINF){
    fib.push_back(fib.at(fib.size()-1)+fib.at(fib.size()-2));
    fa.push_back(fa.at(fa.size()-1)+fa.at(fa.size()-2));
    fb.push_back(fb.at(fb.size()-1)+fb.at(fb.size()-2));
  }
  vector<map<ll,vector<ll>>>memo(fib.size());
  auto solve=[&](auto self,int k,ll idx)->vector<ll>{
    vector<ll>ret(26,0);
    // {
    //   auto it=memo.at(k).find(idx);
    //   if(it!=memo.at(k).end()){
    //     return (*it).second;
    //   }
    // }
    if(k==0){
      rep(i,26)ret.at(i)+=xc.at(idx).at(i);
    }else if(k==1){
      rep(i,26)ret.at(i)+=yc.at(idx).at(i);
    }else{
      if(idx<=fib.at(k-1)){
        return self(self,k-1,idx);
      }else{
        // auto le=self(self,k-1,fib.at(k-1));
        vector<ll>le(26,0);
        rep(i,26)le.at(i)=fa.at(k-1)*xc.at(n).at(i)+fb.at(k-1)*yc.at(m).at(i);
        auto ri=self(self,k-2,idx-fib.at(k-1));
        rep(i,26)ret.at(i)=le.at(i)+ri.at(i);
      }
    }
    // return memo.at(k)[idx]=ret;
    return ret;
  };
  while(Q--){
    ll l,r;cin>>l>>r;l--;
    char c;cin>>c;
    cout<<solve(solve,fib.size()-1,r).at(c-'a')-solve(solve,fib.size()-1,l).at(c-'a')<<endl;
  }

  return 0;
}
