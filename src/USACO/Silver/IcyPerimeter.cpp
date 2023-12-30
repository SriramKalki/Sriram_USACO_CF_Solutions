#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;


void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}


const int MAX_N = 1000;

char grid[MAX_N][MAX_N];  // the grid itself

bool visited[MAX_N][MAX_N];  // keeps track of which nodes have been visited
int area = 0;  // reset to 0 each time we start a new component
int perimeter = 0;

struct Icy{
    int area,perimeter;
};

bool cmp(const Icy& x, const Icy& y) {

    if(x.area != y.area){
        return x.area > y.area;
    }else{
        return x.perimeter < y.perimeter;
    }

}

void floodfill(int r, int c, char color, int n){
    if (r < 0 || r >= n || c < 0 || c >= n){
        perimeter++;
        return;
    }
    if(visited[r][c]) return;
    if(grid[r][c] != '#') {
        perimeter++;
        return;
    }
    visited[r][c] = true; // mark current square as visited
    area++; // increment the size for each square we visit


    floodfill(r, c + 1, color,n);
    floodfill(r, c - 1, color,n);
    floodfill(r - 1, c, color,n);
    floodfill(r + 1, c, color,n);
}

int main() {
    setIO("perimeter");
    int n; cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
        }
    }
    vector<Icy> icy;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && grid[i][j] == '#') {
                area = 0;
                perimeter = 0;
                /*
                 * start a flood fill if the square hasn't already been visited,
                 * and then store or otherwise use the component size
                 * for whatever it's needed for
                 */
                floodfill(i, j, '#',n);
                icy.push_back({area,perimeter});
            }
        }
    }

    sort(begin(icy),end(icy),cmp);
    cout << icy[0].area << " " << icy[0].perimeter << endl;
}