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

/**
 * @fn
 * n 以下の数が素数かどうかを判定して結果を長さ n+1 の vector で返す
 * 0, 1 は false
 * @brief エラトステネスのふるい
 */
vector<bool> eratosthenes(const int& n) {
  if (n < 0) return {};
  vector<bool> is_prime(n+1, true);
  is_prime[0] = false;
  if (n >= 1) is_prime[1] = false;
  for (int p = 2; p <= n; ++p) {
    if (!is_prime[p]) continue;
    for (int q = p * 2; q <= n; q += p) {
      is_prime[q] = false;
    }
  }
  return is_prime;
}

/**
 * @fn
 * n 以下の素数を列挙して結果を vector で返す
 * @brief 素数列挙
 */
vector<int> get_primes(int n) {
  auto is_prime = eratosthenes(n);
  vector<int> ret;
  for(int i=0;i<=n;i++) {
    if(is_prime.at(i)) ret.push_back(i);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;cin>>s;
  int n=s.size();
  auto ps=get_primes(9999999);
  for(auto p:ps){
    string t=to_string(p);
    if(t.size()!=s.size())continue;
    bool ok=true;
    rep(i,n)reps(j,i+1,n){
      ok&=(s.at(i)==s.at(j))==(t.at(i)==t.at(j));
    }
    if(ok){
      cout<<p<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;

  return 0;
}
