#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>

#define ll long long
using namespace std;

vector<ll int> gold(1);
vector<vector<int>> adj(1);

int main(){
    ll int n,m;
    cin >> n >> m;

    gold.resize(n);
    adj.resize(n);

    for(int i=0; i<n; i++){
        cin >> gold[i];
    }

    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ll int total(0);
    ll int currMin(INT32_MAX);
    vector<bool> visited(n,false);

    for(int i=0; i<n; i++){
        if(visited[i]) continue;
        currMin = INT32_MAX;
        vector<int> frontier;

        frontier.push_back(i);

        while(!frontier.empty()){
            int curr = frontier.back();
            frontier.pop_back();

            visited[curr] = true;
            currMin = min(gold[curr],currMin);
            for(auto c : adj[curr]){
                if(!visited[c]){
                    frontier.push_back(c);
                }
            }
        }

        total += currMin;
    }
    cout << total;
}