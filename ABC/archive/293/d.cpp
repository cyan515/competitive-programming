#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 1000000007;

bool is_loop(int start, int before, int now, vector<vector<int>>& adj) {
    vector<int> linked = adj.at(now);
    bool skip = true;
    for(int link : linked) {
        if(link == -1) continue;
        if(link == before && skip) {
            skip = false;
            continue;
        }
        if(link == start) return true;
        return is_loop(start, now, link, adj);
    }
    return false;
}

int idx(char c) {
    if(c=='R') return 0;
    else return 1;
}

int main()
{
    int n,m;cin>>n>>m;
    vector<vector<int>> adj(n, vector<int>(2,-1));
    dsu D(n);
    for(int i=0;i<m;i++) {
        int a,c;char b,d;
        cin>>a>>b>>c>>d;
        a--;c--;
        adj.at(a).at(idx(b)) = c;
        adj.at(c).at(idx(d)) = a;
        D.merge(a,c);
    }
    vector<vector<int>> groups = D.groups();
    int ans = 0;
    for(vector<int> group : groups) {
        int s = group.at(0);
        if(is_loop(s, -1, s, adj)) ans++;
    }
    cout << ans << " " << groups.size() - ans << endl;

    exit(0);
}
