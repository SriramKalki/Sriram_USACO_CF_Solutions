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
int n,m;
int s[500][50],p[500][50];
int A[64];

bool test(int a,int b,int c){
    bool good = true;
    for(int i=0; i<n; i++){
        A[16 * s[i][a] + 4 * s[i][b] + 1 * s[i][c]]++;
    }

    for(int i=0; i<n; i++){
        if(A[16 * p[i][a] + 4 * p[i][b] + 1 * p[i][c]] != 0) good = false;
    }

    for(int i=0; i<64; i++){
        A[i] = 0;
    }
    
    return good;
}

int main(){
    setIO("cownomics");
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char d; cin >> d;
            if(d == 'A') s[i][j] = 0;
            else if(d == 'T') s[i][j] = 1;
            else if(d == 'C') s[i][j] = 2;
            else if(d == 'G') s[i][j] = 3;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char d; cin >> d;
            if(d == 'A') p[i][j] = 0;
            else if(d == 'T') p[i][j] = 1;
            else if(d == 'C') p[i][j] = 2;
            else if(d == 'G') p[i][j] = 3;
        }
    }

    int ans = 0;

    for(int i=0; i<m; i++){
        for(int j=i+1; j<m; j++){
            for(int k=j+1; k<m; k++){
                if(test(i,j,k)) ans++;
            }
        }
    }
    cout << ans;
}