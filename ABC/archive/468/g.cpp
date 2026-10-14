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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

vector<int> longestNonDecreasingSubsequence(const vector<long long>& nums) {
    if (nums.empty()) return {};

    vector<int> tails;
    vector<int> previousIndex(nums.size(), -1);
    vector<int> index(nums.size(), -1);
    int length = 0;

    for (int i = 0; i < nums.size(); ++i) {
        auto it = lower_bound(tails.begin(), tails.end(), nums[i]);
        int pos = distance(tails.begin(), it);

        if (it == tails.end()) {
            tails.push_back(nums[i]);
        } else {
            *it = nums[i];
        }

        index[pos] = i;
        if (pos > 0) {
            previousIndex[i] = index[pos - 1];
        }

        if (pos + 1 > length) {
            length = pos + 1;
        }
    }

    vector<int> lnds(length);
    int k = index[length - 1];
    for (int j = length - 1; j >= 0; --j) {
        lnds[j] = nums[k];
        k = previousIndex[k];
    }

    return lnds;
}

int main(){
  int n;cin>>n;
  vector<ll>a(n);cin>>a;
  auto lis=longestNonDecreasingSubsequence(a);
  cout<<lis.size()<<endl;
  rep(i,lis.size()){
    if(i)cout<<" ";
    cout<<lis.at(i);
  }
  cout<<endl;
}