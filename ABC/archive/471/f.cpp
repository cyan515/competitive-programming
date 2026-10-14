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
  int n,k;cin>>n>>k;
  vector<string>s(n);cin>>s;
  sort(all(s),[&](string& a,string& b)->bool{
    if(a.size()!=b.size())return a.size()>b.size();
    else return a>b;
  });
  string ans1="";
  {
    vector<string>x(k);
    rep(i,k)x.at(i)=s.at(i);
    sort(rall(x));
    rep(i,k){
      if(i)ans1+=x.at(i);
      else{
        int j=0;
        while(j<x.at(i).size()&&x.at(i).at(j)=='0')j++;
        while(j<x.at(i).size())ans1.push_back(x.at(i).at(j)),j++;
      }
    }
  }
  string ans2="";
  {
    vector<string>b;
    reps(i,k,n){
      string str="";
      int j=0;
      while(j<s.at(i).size()&&s.at(i).at(j)=='0')j++;
      while(j<s.at(i).size())str.push_back(s.at(i).at(j)),j++;
      if(str=="")continue;
      b.push_back(str);
    }
    sort(all(b),[&](string& a,string& b)->bool{
      // 普通に逆だからか。
      return a+b>b+a;
    });
    vector<string>x(k-1);
    rep(i,k-1)x.at(i)=s.at(i);
    sort(rall(x));
    if(b.size()){
      ans2=b.front();
      rep(i,k-1)ans2+=x.at(i);
    }
  }
  string ans3="";
  vector<string> anss={ans1,ans2,ans3};
  sort(all(anss),[&](string& a,string& b)->bool{
    if(a.size()!=b.size())return a.size()>b.size();
    else return a>b;
  });
  cout<<anss.front()<<endl;

  return 0;
}
