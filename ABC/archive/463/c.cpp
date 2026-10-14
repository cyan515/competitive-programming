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

int main() {
  ll n;cin>>n;
  vector<ll>h(n),l(n);
  rep(i,n)cin>>h.at(i)>>l.at(i);
  int Q;cin>>Q;
  vector<ll>t(Q);cin>>t;
  vector<ll>ans(Q);
  vector<int>ord(Q);
  rep(i,Q)ord.at(i)=i;
  sort(all(ord),[&](int i,int j)->bool {
    return t.at(i)<t.at(j);
  });
  multiset<ll>st;
  rep(i,n)st.insert(h.at(i));
  priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>>q;
  rep(i,n)q.push(pair(l.at(i),i));
  q.push(pair(LINF,-1));
  for(auto i:ord){
    ll tt=t.at(i);
    while(q.top().first<=tt)st.erase(st.find(h.at(q.top().second))),q.pop();
    ans.at(i)=*st.rbegin();
  }
  rep(i,Q)cout<<ans.at(i)<<endl;

  return 0;
}
