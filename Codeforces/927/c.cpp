#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
template<typename T>
class segmenttree{
    // Copyright (c) 2023 0214sh7
    // https://github.com/0214sh7/library/
    private:
    int n;
    
    std::vector<T> dat;
    std::function<T(T,T)> calc;
    T identity;
    public:
    
    void init(int N,std::function<T(T,T)> func,T Identity){
        n=1;
        while(n<N)n*=2;
        dat.resize(2*n-1);
        for(int i=0;i<2*n-1;++i){
            dat[i]=Identity;
        }
        calc = func;
        identity = Identity;
    }
    
    segmenttree(int N,std::function<T(T,T)> func,T Identity){
        init(N,func,Identity);
    }
    
    void update(int k,T a){
        k+=n-1;
        dat[k]=a;
        while(k>0){
            k=(k-1)/2;
            dat[k]=calc(dat[2*k+1],dat[2*k+2]);
        }
    }
    
    T query(int a,int b){
        a+=n-1;
        b+=n-1;
        T L= identity,R = identity;
        while(a < b){
            if(a % 2 == 0){
                L = calc(L,dat[a]);
                a++;
            }
            a = (a-1)/2;
            if(b % 2 == 0){
                R = calc(dat[b-1],R);
                b--;
            }
            b = (b-1)/2;
        }
        R = calc(L,R);
        return R;
    }
    
};
int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T;cin>>T;
  while(T--) {
    ll n,m;cin>>n>>m;
    vector<ll> a(n);cin>>a;
    string s;cin>>s;
    auto f = [&m](ll a,ll b) -> ll {
      return a*b%m;
    };
    segmenttree<ll> st(n,f,1LL);
    rep(i,n) {
      st.update(i,a.at(i));
    }
    int l = 0;
    int r = n;
    rep(i,n) {
      if(l!=r) cout << st.query(l,r) << " ";
      else cout << a.at(l) << " ";
      if(s.at(i)=='L') {
        l++;
      } else {
        r--;
      }
    }
    cout << endl;
  }

  exit(0);
}
