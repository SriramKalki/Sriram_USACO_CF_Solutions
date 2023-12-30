#include <vector>
#include <string>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <math.h>
#include <queue>
#include <map>
#define ll long long
using namespace std;

struct Flight{
    int c,r,d,s;
};

const int mx = 2*1e5 + 1;
int n,m;
vector<int> layovers(mx,1e9);
vector<int> guard(mx,0);
vector<int> ans(mx,1e9);
vector<vector<Flight>> adj(mx);

bool srt(Flight a, Flight b){
    return a.r > b.r;
}


void DFS(int curr, int time){
    int lay = layovers[curr];
    ans[curr] = min(time,ans[curr]);
    for(int i = guard[curr]; i < adj[curr].size(); i++){
        if(time + lay > adj[curr][i].r && curr != 0) break;
        //curr != 0 because layover doesnt apply at starting node

        guard[curr] = i+1; //next possible index to start at
        DFS(adj[curr][i].d,adj[curr][i].s);
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        //make sure to index
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        a--; c--;
        adj[a].push_back({a,b,c,d});

    }   
    
    for(int i=0; i<n; i++){
        cin >> layovers[i];
    } 
    
    
    for(int i=0; i<n; i++){
        sort(adj[i].begin(), adj[i].end(),srt);
    }

    DFS(0,0);

    for(int i=0; i<n; i++){
        cout << (ans[i] == 1e9? -1 : ans[i]) << endl;
    }

}