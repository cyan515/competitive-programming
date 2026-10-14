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
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

class Timer {
public:
  void start() {
    origin = rdtsc();
  }
  
  inline double get_time() {
    return (rdtsc() - origin) * SECONDS_PER_CLOCK;
  }
  
private:
  constexpr static double SECONDS_PER_CLOCK = 1 / 2.5e9;
  unsigned long long origin;
  
  inline static unsigned long long rdtsc() {
    unsigned long long lo, hi;
    __asm__ volatile ("rdtsc" : "=a" (lo), "=d" (hi));
    return (hi << 32) | lo;
  }
};

int main() {
  Timer timer;
  timer.start();
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;cin>>n;
  vector<ll>a(n);cin>>a;
  int m=200010;
  vector pf(m,vector<int>());
  reps(i,1,m){
    for(ll j=1;j*j<=i;j++){
      if(i%j==0){
        pf.at(i).push_back(j);
        if(i/j!=j)pf.at(i).push_back(i/j);
      }
    }
    sort(all(pf.at(i)));
  }
  // ll cnt=0;
  // rep(i,m)cnt+=pf.at(i).size();
  // cout<<cnt<<endl;
  
  ll ma=0;
  rep(i,n)chmax(ma,a.at(i));
  a.push_back(ma);
  while(timer.get_time()<1.9&&a.back()<LINF){
    auto b=a;
    ll ans=0;
    bool ok=true;
    for(int i=n;i>0;i--){
      ll d=a.at(i)-a.at(i-1);
      if(d<0){
        ok=false;
        break;
      }
      ans+=d;
      for(auto e:pf.at(i)){
        a.at(e-1)+=d;
        if(timer.get_time()>1.9){
          ok=false;
          break;
        }
      }
      if(timer.get_time()>1.9){
        ok=false;
        break;
      }
    }
    if(ok){
      cout<<ans<<endl;
      return 0;
    }
    swap(a,b);
    a.back()++;
  }
  cout<<-1<<endl;

  return 0;
}
