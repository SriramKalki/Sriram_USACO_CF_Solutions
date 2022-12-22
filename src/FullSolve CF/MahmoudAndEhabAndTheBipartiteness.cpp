#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>

#define ll long long
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

vector<int> color(100000,-1);
void dfs(vector<vector<int>>& adj, int node, int currColor){
    if(color[node] != -1) return;

    if(currColor == -1) currColor = 0;
    color[node] = currColor;

    for(auto c : adj[node]){
        if(color[c] == -1){
            if(currColor == 0){
                dfs(adj,c,1);
            }else{
                dfs(adj,c,0);
            }
        }
    }

}
int main(){
    int n; cin >> n;
    vector<vector<int>> adj(n);


    for(int i=0;i<n-1;i++){
        int a,b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);

    }
    dfs(adj,0,-1);

    vector<int> set1; vector<int> set2;
    for(int i=0; i<n; i++){
        if(color[i] == 0){
            set1.push_back(i);
        }else{
            set2.push_back(i);
        }
    }

    ll int answer(set1.size() * set2.size());


    cout << (answer - (n-1));
}