#include <vector>
#include <string>
#include <iostream>

using namespace std;


 void setIO(string s) {
     freopen((s + ".in").c_str(), "r", stdin);
     freopen((s + ".out").c_str(), "w", stdout);
 }

struct Point{
    int x,y;
};

vector<bool> vis(1000);
int total = 0;

void dfs(vector<Point>& c, int node, int power){
    if(vis[node]){
        return;
    }
    total++;
    vis[node] = true;


    for(int i=0; i<c.size(); i++){
        int dx = (c[node].x - c[i].x);
        int dy = (c[node].y - c[i].y);
        if(dx*dx + dy*dy <= power){

            dfs(c,i,power);
        }
    }



}
int main(){
    setIO("moocast");

    int n; cin >> n;

    vector<Point> c(n);

    for(int i=0; i<n; i++) {
        cin >> c[i].x >> c[i].y;
    }


    int low = 1;
    int high = 1e9;
    int answer = -1;

    while(low <=high){
        int mid = (low + high) / 2;
        dfs(c,0,mid);

        if (total == n) {
            answer = mid;
            high = mid - 1;

        } else {
            low = mid + 1;

        }
        total = 0;
        fill(begin(vis),end(vis),false);
    }

    cout << answer;
}

