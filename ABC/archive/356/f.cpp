#if !__INCLUDE_LEVEL__
#include __FILE__

#include <atcoder/modint>
using mint = atcoder::modint998244353;

// 当然、絶対mを超過はありえない
// popcountの値は高々60未満
// bit_ceil(m)周期で循環
// 1周期の和はbit_ceil(m)に等しい
// 割った数%2==0 なら0, ==1なら加算

int main(){
    ull n,m;
    cin >> n >> m;
    mint ans;
    
    // cout << bit_ceil(m) << el;
    // cout << m << ": " << bitset<8>(m) << el;
    // for(ull i = 0; i <= n; i++){
    //     cout << bitset<8>(i) << ": " << i << el;
    //     cout << (bitset<8>(i) & bitset<8>(m)) << el;
    //     ans += popcount((bitset<8>(i) & bitset<8>(m)).to_ullong());
    //     cout << ans.val() << el;cout<<el;
    // }

    ull M = bit_ceil(m);
    ans += M*(n/M);
    n %= M;
    rep(i,0,bit_width(m)){
        if((m&(1ull<<i))==0) continue;
        ull val = (1ull<<i);
        mint sum;
        sum += (n/val)/2 * mint(val);
        if((n/val)%2==1){
            sum += n%val+1;
        }
        ans += sum;
    }
    cout << ans.val() << el;
}

#else
#include <bits/stdc++.h>
using namespace std;
struct Init { Init() { ios::sync_with_stdio(0); cin.tie(0); cout << setprecision(13); } }init;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

#define rep(i, x, limit) for (ll i = (ll)x; i < (ll)limit; i++)
#define REP(i, x, limit) for (ll i = (ll)x; i <= (ll)limit; i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
#define spa ' '
#define Yes cout << "Yes" << el
#define No cout << "No" << el
#define YES cout << "YES" << el
#define NO cout << "NO" << el
#define eps (1e-10)
#define Equals(a,b) (fabs((a) - (b)) < eps )
#define debug(x) cerr << #x << " = " << x << el

const double pi = 3.141592653589793238;
const int inf = 1073741823;
const ll infl = 1LL << 60;
const string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string abc = "abcdefghijklmnopqrstuvwxyz";

template<typename T1, typename T2>
std::ostream &operator<< (std::ostream &os, std::pair<T1,T2> p){
    os << "{" << p.first << "," << p.second << "}";
    return os;
}

// 配列の要素を空白区切りで出力 第二引数をtrueにすると改行区切り
template<typename T> inline void print_vec(const vector<T> &v, bool split_line=false) {
    if(v.empty()){
        cout << "This vector is empty." << el;
        return;
    }
    bool isValue = (is_integral<T>::value);
    for (int i = 0; i < (int)v.size(); i++) {
        if(isValue && (v[i]==inf || v[i]==infl)) cout << 'x' << " \n"[split_line || i+1==(int)v.size()];
        else cout << v[i] << " \n"[split_line || i+1==(int)v.size()];
    }
}

template<typename T1, typename T2> inline void print_vec(const vector<pair<T1,T2>> &v, bool split_line=false){
    if(v.empty()){
        cout << "This vector is empty." << el;
        return;
    }
    for(int i = 0; i < (int)v.size(); i++){
        cout << '{';
        auto p = v[i];
        pair<bool,bool> isValue = {is_integral<T1>::value, is_integral<T2>::value};
        if(isValue.first && (p.first==inf || p.first==infl)) cout << "x,";
        else cout << p.first << ',';
        if(isValue.second && (p.second==inf || p.second==infl)) cout << 'x';
        else cout << p.second;
        cout << "}" << " \n"[split_line || i+1==(int)v.size()];
    }
}

template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) {
    bool compare = a < b;
    if(compare) a = b;
    return compare;
}
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) {
    bool compare = a > b;
    if(compare) a = b;
    return compare;
}

// std::chronoを利用した時間計測用クラス
class Timer{
    chrono::system_clock::time_point start;
    public:
        Timer() : start(chrono::system_clock::now()) {}
    
        double count(){
            chrono::duration<double> Time_ = chrono::system_clock::now() - start;
            return Time_.count();
        }

        bool is_under(double x){
            return (this -> count()) < x;
        }
};

#endif