#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

struct Wormhole{
    int dest,width;
};
vector<vector<Wormhole>> adj(100000);
vector<int> comp(100000,-1);
int minWidth(0);

void dfs(int start, int id){
    if(comp[start] != -1){
        //visited
        return;
    }
    comp[start] = id;
    for(auto u : adj[start]){
        if(u.width >= minWidth){
            dfs(u.dest,id);
        }
    }
}
int main(){
    int maxWidth(-1);
    int id(0);

    bool pass = true;
    setIO("wormsort");
    int n,m;
    cin >> n >> m;
    vector<int> p(n);
    bool alreadySorted(true);
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        x--;
        p[i] = x;
        if(i != p[i]) alreadySorted = false;
    }

    if(alreadySorted){
        cout << -1;
        return 0;
    }
    for(int i=0; i<m; i++){
        int a,b,w;
        cin >> a >> b >> w;
        a--;b--;
        maxWidth = max(maxWidth,w);
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    int a = 0, b = maxWidth++;
    int answer(-1);
    while (a != b) {
        pass = true;
        int k = (a+b+1)/2;
        minWidth = k;
        id = 0;
        for(int i=0; i<n; i++) comp[i] = -1;

        for(int i=0; i<n; i++){
            dfs(i,id);
            id++;
        }

        for(int i=0; i<n; i++){
            if(comp[p[i]] != comp[i]){
                pass = false;
                break;
            }
        }

        if (pass) {
            a = k;
            answer = k;
        }else{
            b = k-1;
        }
    }

    cout << answer;



}