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
    int row,col;
};
int diff(0);
int grid[500][500];
bool waypoints[500][500];
bool visited[500][500];

void floodfill(int r, int c, int m, int n, int prevHeight){

    if (r < 0 || r >= m || c < 0 || c >= n){ return; }
    if(visited[r][c]) { return;}
    if(abs(grid[r][c]-prevHeight) > diff) return;
    visited[r][c] = true; // mark current square as visited

    floodfill(r, c + 1, m,n,grid[r][c]);
    floodfill(r, c - 1, m,n,grid[r][c]);
    floodfill(r - 1, c, m,n,grid[r][c]);
    floodfill(r + 1, c, m,n,grid[r][c]);
}

bool check(int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(waypoints[i][j] && !visited[i][j]) return false;
        }
    }
    return true;
}
int main(){
    setIO("ccski");
    int m,n; cin >> m >> n;
    int maxh(INT32_MIN),minh(INT32_MAX);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
            maxh = max(maxh,grid[i][j]);
            minh = min(minh,grid[i][j]);
        }
    }
    Point point;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            int x;
            cin >> x;
            waypoints[i][j] = x==1;
            point.row = i;
            point.col = j;


        }
    }

    int low = 0;
    int high = maxh-minh;
    int answer = -1;

    while(low <=high){
        diff = (low + high) / 2;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                visited[i][j] = false;
            }
        }

        floodfill(point.row,point.col,m,n,grid[point.row][point.col]);

        if (check(m,n)) {
            answer = diff;
            high = diff - 1;

        } else {
            low = diff + 1;

        }
    }

    cout << answer;







}