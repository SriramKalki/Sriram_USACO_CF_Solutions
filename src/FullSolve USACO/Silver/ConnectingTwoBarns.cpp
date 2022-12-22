#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>

#define ll long long

using namespace std;


const int MAX_N = 1e5;
int comp[MAX_N];
vector<int> comps[MAX_N];
vector<int> adj[MAX_N];

void dfs(int cur, int c) {
    if (comp[cur] != -1) {
        return;
    }
    comp[cur] = c;
    for (int u : adj[cur]) {
        dfs(u, c);
    }
}
//copied from usaco guide

ll int cost(int a, int b) {
    int dist = MAX_N;
    for (int u : comps[a]) {
        /*
         * Finds the closest field in bs' connected
         * component to field u and updates the minimum
         * distance. The closest field is found by binary
         * searching on a sorted array (bs' connected
         * component).
         */
        int i = lower_bound(
                comps[b].begin(), comps[b].end(), u
        ) - comps[b].begin();
        if (i > 0) {
            dist = min(dist, abs(comps[b][i - 1] - u));
        }
        if (i < comps[b].size()) {
            dist = min(dist, abs(comps[b][i] - u));
        }
    }
    /*
     * Returns the minimum cost of building a path
     * between the two components (aka dist^2)
     */
    return (ll) dist * dist;
}
void solve(){
    int n, m;
    cin >> n >> m;


    for(int j=0; j<n; j++){
        comp[j] = -1;
        comps[j].clear();
        adj[j].clear();

    }

    //one index check
    for(int j=0; j<m; j++){
        int a,b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int cur = -1;
    for(int j=0; j<n; j++){
        if(comp[j] == -1){
            dfs(j,++cur);
        }
    }

    for(int j=0; j< n; j++){
        comps[comp[j]].push_back(j);
    }

    ll ans = cost(comp[0],comp[n-1]);
    for(int c=1; c<cur; c++){
        ans = min(ans,cost(comp[0],c) + cost(c, comp[n-1]));
    }
    cout << ans << endl;


}
int main(){
    int t; cin >> t;

    for(int i=0; i<t; i++){
        solve();
    }
}