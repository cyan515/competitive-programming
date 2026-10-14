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
  string s,t;cin>>s>>t;
  int n=s.size();
  int m=t.size();
  int si=0;
  int ti=0;
  int ans=0;
  while(si<n||ti<m){
    if(ti==m){
      bool ok=true;
      while(si<n){
        ok&=s.at(si)=='A';
        si++;
        ans++;
      }
      if(ok)break;
      cout<<-1<<endl;
      return 0;
    }
    if(si==n){
      bool ok=true;
      while(ti<m){
        ok&=t.at(ti)=='A';
        ti++;
        ans++;
      }
      if(ok)break;
      cout<<-1<<endl;
      return 0;
    }
    if(s.at(si)==t.at(ti)){
      si++;
      ti++;
    }else{
      if(s.at(si)=='A'){
        ans++;
        si++;
      } else if(t.at(ti)=='A'){
        ans++;
        ti++;
      } else {
        cout<<-1<<endl;
        return 0;
      }
    }
  }
  cout<<ans<<endl;

  return 0;
}
