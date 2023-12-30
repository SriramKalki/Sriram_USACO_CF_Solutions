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

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int N,B, tile_depth[250],boot_depth[250],boot_size[250];
bool visited[250][250];
int best = 9999;
void solve(int i, int b){
    if(visited[i][b]) return;
    visited[i][b] = true;
    if(i == N-1){
        best = min(b,best);
        return;
    }

    for(int j = i+1; j<= boot_size[b] + i; j++ ){
        if(j == N) break;
        if(tile_depth[j] <= boot_depth[b]) solve(j,b);
    }
    for(int j = b+1; j < B; j++){
        if(tile_depth[i] <= boot_depth[j]) solve(i,j);
    }


}


int main(){
    setIO("snowboots");
    cin >> N >> B;
    for(int i=0; i<N; i++){
        cin >> tile_depth[i];
    }   
    for(int i=0; i<B; i++){
        cin >> boot_depth[i] >> boot_size[i];
    }
    solve(0,0);
    cout << best;

}