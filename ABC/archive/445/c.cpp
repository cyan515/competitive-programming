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
// https://qiita.com/tubo28/items/fa8ee013390184b0ba18
// 多倍長テンプレ
/* ---------------------- ここから ---------------------- */
# include <boost/multiprecision/cpp_dec_float.hpp>
# include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
// 任意長整数型
using Bint = mp::cpp_int;
// 仮数部が10進数で1024桁の浮動小数点数型(TLEしたら小さくする)
using Real = mp::number<mp::cpp_dec_float<1024>>;
/* ---------------------- ここまで ---------------------- */

vector<int> doubling(const vector<int>& graph,const vector<bool>& bit) {
  int n = graph.size();
  vector<vector<int>> doubling(400, vector<int>(n));
  
  for (int v = 0; v < n; v++) {
    doubling.at(0).at(v) = graph.at(v);
  }
  
  for (int i = 1; i < 400; ++i) for (int v = 0; v < n; v++) {
    doubling.at(i).at(v) = doubling.at(i-1).at(doubling.at(i-1).at(v));
  }
  
  vector<int> result(n);
  for (int v = 0; v < n; v++) {
    int current = v;
    for (int i = 0; i < 400; i++) {
      if (bit.at(i)) {
        current = doubling.at(i).at(current);
      }
    }
    result.at(v) = current;
  }
  
  return result;
}

int main() {
  int n;cin>>n;
  vector<int> a(n);cin>>a;
  rep(i,n) a.at(i)--;
  vector<bool> bit(400,false);
  Bint x = 1;
  rep(i,100) x *= 10;
  {
    int i = 0;
    while(x>0) {
      bit.at(i) = x%2==1;
      x /= 2;
      i++;
    }
  }
  
  auto ans = doubling(a,bit);
  rep(i,n){
    if(i)cout<<" ";
    cout<<ans.at(i)+1;
  }
  cout<<endl;

  return 0;
}
