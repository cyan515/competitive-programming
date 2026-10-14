#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using mint = modint;
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const ll MOD = 10007;
const string Yes = "Yes";
const string No = "No";
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};
// https://atcoder.jp/contests/past202203-open/submissions/32816945
template<typename T,unsigned int N>
struct Matrix{
	array<array<T,N>,N>dat;
	array<T,N>&operator[](int i){return dat[i];}
	const array<T,N>&operator[](int i)const{return dat[i];}
	Matrix(){for(int i=0;i<N;i++)dat[i].fill(T(0));}
	static Matrix eye(){
		Matrix res;
		for(int i=0;i<N;i++)res[i][i]=1;
		return res;
	}
	Matrix operator+(const Matrix&A)const{
		Matrix res;
		for(int i=0;i<N;i++)for(int j=0;j<N;j++)
			res[i][j]=dat[i][j]+A[i][j];
		return res;
	}
	Matrix operator*(const Matrix&A)const{
		Matrix res;
		for(int i=0;i<N;i++)for(int k=0;k<N;k++)for(int j=0;j<N;j++)
			res[i][j]+=dat[i][k]*A[k][j];
		return res;
	}
	Matrix pow(long long n)const{
		Matrix a=*this,res=eye();
		for(;n;a=a*a,n>>=1)if(n&1)res=res*a;
		return res;
	}
};
mint f(ll K,ll M,vector<int>&cs,vector<ll>&ds)
{
	mint::set_mod(M);
	mint S=0;
	for(int i=0;i<K;i++)
	{
		int c;long d;
    c=cs.at(i);
    d=ds.at(i);
		S*=mint(10).pow(d);
		Matrix<mint,2>A;
		A[0][0]=10;
		A[0][1]=1;
		A[1][1]=1;
		A=A.pow(d-1);
		S+=(A[0][0]+A[0][1])*c;
	}
  return S;
}

int main() {
  ll k,m;cin>>k>>m;
  vector<int>c(k);
  vector<ll>l(k);
  rep(i,k)cin>>c.at(i)>>l.at(i);
  mint::set_mod(MOD);
  mint x = f(k,MOD*m,c,l);
  cout<<x.val()/m<<endl;

  return 0;
}
