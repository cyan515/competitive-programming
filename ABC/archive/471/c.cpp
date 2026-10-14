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

int main() {
  ll n;cin>>n;
  vector<ll>a(n);cin>>a;
  set<ll>st(all(a));
  ll cur=0;
  ll ans=0;
  while(st.size()){
    auto it=st.lower_bound(cur);
    ll d=LINF;
    if(it!=st.end()){
      d=abs(*it-cur);
    }
    if(it==st.begin()){
      cur=*it;
      ans+=d;
      st.erase(it);
      continue;
    }
    auto itt=it;
    itt--;
    ll dd=abs(*itt-cur);
    if(dd<=d){
      cur=*itt;
      ans+=dd;
      st.erase(itt);
    }else{
      cur=*it;
      ans+=d;
      st.erase(it);
    }
  }
  cout<<ans<<endl;

  return 0;
}
