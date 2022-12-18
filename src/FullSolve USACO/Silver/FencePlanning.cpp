#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

 void setIO(string s) {
     freopen((s + ".in").c_str(), "r", stdin);
     freopen((s + ".out").c_str(), "w", stdout);
 }

struct Point{
    int x,y;
};

int MAX_SIZE(100000);
vector<vector<int>> adj(MAX_SIZE);
vector<Point> location(MAX_SIZE);
vector<int> vis(MAX_SIZE);
vector<Point> dfsnodes;

bool cmpA(const Point& x, const Point& y) {

    return x.x < y.x;

}

bool cmpB(const Point& x, const Point& y) {

    return x.y < y.y;

}

void dfs(int node){
    if(vis[node]){
        return;
    }
    vis[node] = true;
    dfsnodes.push_back({location[node].x,location[node].y});
    for(int u : adj[node]){
        if(!vis[u]) dfs(u);
    }

}
int main(){
    setIO("fenceplan");
    int n,m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        int x,y; cin >> x >> y;
        location[i].x=x;
        location[i].y=y;
    }

    for(int i=0; i<m; i++){
        int p,q; cin >> p >> q;
        adj[--p].push_back(--q);
        adj[q].push_back(p);
    }

    int perimeter(INT32_MAX);
    fill(vis.begin(),vis.end(),false);
    for(int i=0; i<n;i++){
        if(vis[i]) continue;
        dfs(i);
        sort(begin(dfsnodes), end(dfsnodes), cmpA);
        int xw = dfsnodes.back().x - dfsnodes.front().x;

        sort(begin(dfsnodes), end(dfsnodes), cmpB);
        int yw = dfsnodes.back().y - dfsnodes.front().y;

        perimeter = min(perimeter,2*(xw + yw));

        dfsnodes.clear();

    }
    cout << perimeter;
}