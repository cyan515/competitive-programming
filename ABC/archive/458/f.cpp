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
#include <atcoder/modint>
using mint=atcoder::modint998244353;

int main() {
  ll n,k;cin>>n>>k;
  vector<string>s(k);cin>>s;
  {
    set<string>st(all(s));
    s=vector(all(st));
    k=s.size();
  }
  sort(all(s),[&](string a,string b)->bool{
    return a.size()<b.size();
  });
  {
    vector<bool>ok(k,true);
    rep(i,k)reps(j,i+1,k){
      rep(ii,s.at(j).size()){
        if(ii+s.at(i).size()>s.at(j).size())break;
        string t=s.at(j).substr(ii,s.at(i).size());
        if(s.at(i)==t){
          ok.at(j)=false;
          break;
        }
      }
    }
    vector<string>ns;
    rep(i,k)if(ok.at(i))ns.push_back(s.at(i));
    swap(s,ns);
    k=s.size();
  }
  mint cnt=0;
  reps(bit,1,1<<k){
    ll sig=__popcount(bit)%2==0?-1:1;
    vector<string>x;
    rep(i,k){
      if((bit&(1<<i))!=0)x.push_back(s.at(i));
    }
    sort(all(x));
    do{
      
    }while(next_permutation(all(x)));
  }
  mint ans=mint(26).pow(n);
  ans-=cnt;
  cout<<ans.val()<<endl;

  return 0;
}
