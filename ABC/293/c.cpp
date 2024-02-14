#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 1000000007;

int h,w;
vector<vector<int>> a;

int dfs(int x,int y,set<int> visited) {
    int ret = 0;
    if(x==w-1 && y==h-1 && visited.find(a.at(y).at(x))!=visited.end()) {
        return 1;
    }
    if(x<w-1 && visited.find(a.at(y).at(x+1))==visited.end()) {
        visited.insert(a.at(y).at(x+1));
        ret += dfs(x+1,y,visited);
        visited.erase(a.at(y).at(x+1));3 3
3 2 2
2 1 3
1 5 4

    }
    if(y<h-1 && visited.find(a.at(y+1).at(x))==visited.end()) {
        visited.insert(a.at(y+1).at(x));
        ret += dfs(x,y+1,visited);
        visited.erase(a.at(y+1).at(x));
    }
    return ret;
}

int main()
{
    cin>>h>>w;
    a.resize(h);
    for(int i=0;i<h;i++) a.at(i).resize(w);
    for(int i=0;i<h;i++) for(int j=0;j<w;j++) cin>>a.at(i).at(j);
    set<int> st;
    st.insert(a.at(0).at(0));
    int cnt = dfs(0,0,st);
    cout << cnt << endl;

    exit(0);
}
