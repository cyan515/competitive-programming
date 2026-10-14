#include <bits/stdc++.h>
#include <atcoder/dsu>
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

// https://zenn.dev/reputeless/books/standard-cpp-for-competitive-programming/viewer/weighted-union-find
template <class Type>
class weighted_union_find {
public:

	weighted_union_find() = default;

	explicit weighted_union_find(size_t n)
		: m_parents(n), m_sizes(n, 1), m_diffWeights(n) {
		iota(m_parents.begin(), m_parents.end(), 0);
	}

	int leader(int i) {
		if (m_parents[i] == i) {
			return i;
		}

		const int root = leader(m_parents[i]);

		m_diffWeights[i] += m_diffWeights[m_parents[i]];

		return (m_parents[i] = root);
	}

	void merge(int a, int b, Type w) {
		w += weight(a);
		w -= weight(b);

		a = leader(a);
		b = leader(b);

		if (a != b) {
			if (m_sizes[a] < m_sizes[b]) {
				swap(a, b);
				w = -w;
			}

			m_sizes[a] += m_sizes[b];
			m_parents[b] = a;
			m_diffWeights[b] = w;
		}
	}

	Type diff(int a, int b) {
		return (weight(b) - weight(a));
	}

	bool same(int a, int b) {
		return (leader(a) == leader(b));
	}

	int size(int i) {
		return m_sizes[leader(i)];
	}

private:

	vector<int> m_parents;
	vector<int> m_sizes;
	vector<Type> m_diffWeights;

	Type weight(int i) {
		leader(i);
		return m_diffWeights[i];
	}
};

int main() {
  int n,Q;cin>>n>>Q;
  vector<int>col(n,0);
  // white, black
  vector cnt(n,pair<int,int>(1,0));
  weighted_union_find<ll>uf(n);
  bool ok=true;
  int ans=0;
  while(Q--){
    int u,v;cin>>u>>v;u--;v--;
    if(!ok){
      cout<<-1<<endl;
      continue;
    }
    int ul=uf.leader(u);
    int vl=uf.leader(v);
    int uc=(col.at(ul)+abs(uf.diff(u,ul)))%2;
    int vc=(col.at(vl)+abs(uf.diff(v,vl)))%2;
    if(uf.same(u,v)){
      ok&=uc!=vc;
      if(ok)cout<<ans<<endl;
      else cout<<-1<<endl;
    }else{
      if(uc!=vc){
        auto ucnt=cnt.at(ul);
        auto vcnt=cnt.at(vl);
        auto ncnt=pair(ucnt.first+vcnt.first,ucnt.second+vcnt.second);
        uf.merge(u,v,1);
        int nl=uf.leader(u);
        cnt.at(nl)=ncnt;
      }else{
        auto ucnt=cnt.at(ul);
        auto vcnt=cnt.at(vl);
        int x=ucnt.first+vcnt.second;//uをひねったときの黒
        int y=ucnt.second+vcnt.first;//vをひねったときの黒
        if(x>y){
          //vひねる
          col.at(vl)=1-col.at(vl);
          vc=1-vc;
          ans-=vcnt.second;
          ans+=vcnt.first;
          swap(vcnt.first,vcnt.second);
        }else{
          //uひねる
          col.at(ul)=1-col.at(ul);
          uc=1-uc;
          ans-=ucnt.second;
          ans+=ucnt.first;
          swap(ucnt.first,ucnt.second);
        }
        auto ncnt=pair(ucnt.first+vcnt.first,ucnt.second+vcnt.second);
        uf.merge(u,v,1);
        int nl=uf.leader(u);
        cnt.at(nl)=ncnt;
      }
      cout<<ans<<endl;
    }
  }

  return 0;
}
