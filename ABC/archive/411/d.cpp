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
  ll n,Q;cin>>n>>Q;
  map<int,string> xmp;
  int cnt = 0;
  vector<tuple<int,int,int>> qs;
  while(Q--) {
    int op;cin>>op;
    if(op==1) {
      int p;cin>>p;p--;
      qs.push_back({op,p,-1});
    } else if(op==2) {
      int p;string s;cin>>p>>s;p--;
      qs.push_back({op,p,cnt});
      xmp[cnt] = s;
      cnt++;
    } else {
      int p;cin>>p;p--;
      qs.push_back({op,p,-1});
    }
  }
  vector<int> g(cnt,-1);
  vector<int> pc(n,-1);
  int server = -1;
  for(auto [op,p,s] : qs) {
    if(op==1) {
      pc.at(p) = server;
    } else if(op==2) {
      g.at(s) = pc.at(p);
      pc.at(p) = s;
    } else {
      server = pc.at(p);
    }
  }
  stack<string> st;
  if(server==-1) {
    cout << endl;
  } else {
    while(server!=-1) {
      st.push(xmp[server]);
      server = g.at(server);
    }
    while(st.size()) {
      cout << st.top();
      st.pop();
    }
    cout << endl;
  }

  return 0;
}
