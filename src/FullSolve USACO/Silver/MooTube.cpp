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

struct Connection{
    int to,power;
};
vector<bool> visited(5000,false);
int queryAnswer(0);
void dfs(vector<vector<Connection>>& v, int node, int minRel){
    visited[node] = true;

    for(auto c : v[node]){
        if(!visited[c.to] && c.power >= minRel){
            queryAnswer++;
            dfs(v,c.to,minRel);
        }
    }
}
int main(){
    setIO("mootube");
    int n;
    cin >> n;
    int q;
    cin >> q;
    vector<vector<Connection>> v(n);
    for(int i=0; i<n-1; i++){
        int p,q,r;
        cin >> p >> q >> r;
        p--; q--;
        v[p].push_back({q,r});
        v[q].push_back({p,r});
    }


    for(int i=0; i<q; i++){
        queryAnswer = 0;
        fill(begin(visited),end(visited), false);
        int a,b;
        cin >> a >> b;
        b--;
        dfs(v,b,a);
        cout << queryAnswer << endl;

    }


}