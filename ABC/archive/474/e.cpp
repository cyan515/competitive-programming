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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;cin>>T;
  while(T--){
    ll n;cin>>n;
    vector<ll>a(n),b(n);
    rep(i,n)cin>>a.at(i)>>b.at(i);
    vector<int>ord(n);
    rep(i,n)ord.at(i)=i;
    sort(all(ord),[&](int i,int j)->bool{
      ll di=a.at(i)-b.at(i);
      ll dj=a.at(j)-b.at(j);
      return di<dj;
    });
    ll ans=0;
    ll ami=LINF;
    rep(i,n)chmin(ami,a.at(i));
    rep(i,n)ans+=a.at(i);
    reps(i,(n+1)/2,n)ans-=a.at(ord.at(i))-b.at(ord.at(i));
    for(int ii=(n+1)/2-1;ii>=0;ii--){
      int i=ord.at(ii);
      ll d=a.at(i)-b.at(i);
      ll cost;
      if(n%2!=0&&ii==(n+1)/2-1)cost=ami;
      else cost=ami*2;
      if(d<cost)break;
      ans+=cost;
      ans-=d;
    }
    cout<<ans<<endl;
  }

  return 0;
}
