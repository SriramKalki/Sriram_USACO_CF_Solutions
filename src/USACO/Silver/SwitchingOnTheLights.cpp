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

vector<pair<int,int>> link[100][100];
bool visited[100][100];
bool light[100][100];
int answer(1);

int dx[]= { 0, 1, -1,  0};
int dy[]= { 1, 0, 0,  -1};

void floodfill(int x,int y,int n){
    if (x < 0 || x >= n || y < 0 || y >= n) return; //out of bounds
    if(visited[x][y]) return; //visited
    if(!light[x][y]) return; //unlighted

    visited[x][y] = true;
    for(auto room : link[x][y]) {
        if (!light[room.first][room.second]){
            answer++;
            light[room.first][room.second] = true;
        }

        for(int k = 0; k<4; ++k){
            int nx = room.first + dx[k];
            int ny = room.second + dy[k];
            // checking whether p.first,p.second is adjacent to visited room
            if(nx >= 0 && nx < n && ny >= 0 && ny < n && visited[nx][ny]){
                floodfill( room.first, room.second,n);
            }
        }
    }

    floodfill(x, y + 1,n);
    floodfill(x, y - 1,n);
    floodfill(x - 1, y,n);
    floodfill(x + 1, y,n);

}
int main(){
    setIO("lightson");
    int n,m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a,b,x,y;
        cin >> a >> b >> x >> y;
        a--;b--;x--;y--;
        link[a][b].push_back({x,y});
    }
    light[0][0] = true;
    fill(visited[0],visited[0] + 100*100,false);
    floodfill(0,0,n);
    cout << answer;

}