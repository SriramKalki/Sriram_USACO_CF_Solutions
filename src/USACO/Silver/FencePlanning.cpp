#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

vector<vector<int>> adj(100000);
vector<bool> vis(100000,false);
int answer(0);

void dfs(int currNode){
    vis[currNode] = true;

    answer += (currNode == 0) ? ceil(log2(adj[currNode].size()+1)) : ceil(log2(adj[currNode].size()));
    answer += (currNode == 0) ? adj[currNode].size() : adj[currNode].size() - 1;

    for(auto u : adj[currNode]){
        if(vis[u]) return;
        dfs(u);
    }
}
int main(){
    int n;

    cin >> n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0);
    cout << answer;
}