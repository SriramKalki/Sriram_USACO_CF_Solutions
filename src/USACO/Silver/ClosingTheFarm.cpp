#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<vector<int>> adj(3000);
vector<int> vis(3000);
vector<int> closed(3000);

int nodes(0);

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

void dfs(int node){
    if(vis[node] || closed[node]){
        return;
    }

    nodes++;
    vis[node] = true;

    for(int u : adj[node]){
        if(!vis[u]) dfs(u);
    }
}

int main(){
    setIO("closing");
    int n,m;
    cin >> n >> m;



    for(int i = 0; i<m; i++){
        int p,q; cin >> p >> q; p--; q--;
        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    vector<int> ord(n);

    for(int i=0; i<n; i++){
        int bruh;
        cin >> bruh;
        bruh--;
        ord[i] = bruh;
    }

    dfs(0);
    if (nodes == n) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    for(int i=0; i<n-1; i++){
        nodes=0;
        closed[ord[i]]=true;
        fill(vis.begin(),vis.end(),false);

        dfs(ord[n-1]);

        if(nodes == n-i-1){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}