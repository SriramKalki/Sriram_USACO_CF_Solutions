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

    int unfilled(0);

    for(auto u : adj[currNode]){
        if(!vis[u]) unfilled++;
    }
    answer += ceil(log2(unfilled+1));

    for(auto u : adj[currNode]){
        if(!vis[u]) dfs(u);
    }
}
int main(){

    int n;

    cin >> n;
    for(int i=0;i<n-1;i++){
        int a,b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0);
    answer += n-1;
    cout << answer;
}