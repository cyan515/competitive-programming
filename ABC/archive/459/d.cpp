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
  int T;cin>>T;
  while(T--){
    string s;cin>>s;
    int n=s.size();
    vector<int>cnt(26,0);
    rep(i,n)cnt.at(s.at(i)-'a')++;
    priority_queue<pair<int,char>>q;
    int ma=0;
    rep(i,26)ma=max(ma,cnt.at(i));
    rep(i,26)if(cnt.at(i)>=1)q.push(pair(cnt.at(i),'a'+i));
    if(n%2){
      if(ma>n/2+1)cout<<No<<endl;
      else {
        bool ok=true;
        string ans="";
        while(q.size()>1){
          auto a=q.top();q.pop();
          if(q.empty()){
            ok=false;
            break;
          }
          auto b=q.top();q.pop();
          if(ans.size()>0&&ans.back()==a.second)swap(a,b);
          ans.push_back(a.second);
          ans.push_back(b.second);
          if(a.first>1)q.push(pair(a.first-1,a.second));
          if(b.first>1)q.push(pair(b.first-1,b.second));
        }
        ok&=q.top().first==1;
        if(ok)ans.push_back(q.top().second);
        rep(i,ans.size()-1){
          ok&=ans.at(i)!=ans.at(i+1);
        }
        ok&=ans.size()==n;
        if(ok){
          cout<<Yes<<endl;
          cout<<ans<<endl;
        }else{
          cout<<No<<endl;
        }
      }
    }else{
      if(ma>n/2)cout<<No<<endl;
      else {
        string ans="";
        bool ok=true;
        while(q.size()){
          auto a=q.top();q.pop();
          if(q.empty()){
            ok=false;
            break;
          }
          auto b=q.top();q.pop();
          if(ans.size()>0&&ans.back()==a.second)swap(a,b);
          ans.push_back(a.second);
          ans.push_back(b.second);
          if(a.first>1)q.push(pair(a.first-1,a.second));
          if(b.first>1)q.push(pair(b.first-1,b.second));
        }
        rep(i,ans.size()-1){
          ok&=ans.at(i)!=ans.at(i+1);
        }
        ok&=ans.size()==n;
        if(ok){
          cout<<Yes<<endl;
          cout<<ans<<endl;
        }else{
          cout<<No<<endl;
        }
      }
    }
  }

  return 0;
}
