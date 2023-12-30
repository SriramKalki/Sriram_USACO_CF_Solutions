#include <vector>
#include <string>
#include <iostream>

using namespace std;


bool connect[200][200];

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int dfs(int length, int curr, bool canHear[]){

    if(canHear[curr]){

        return 0;
    }
    int ret(1);
    canHear[curr] = true;

    for(int i=0; i< 200; i++){
        if(connect[curr][i]){
            ret += dfs(length,i,canHear);

        }
    }

    return ret;
}
int main(){
    setIO("moocast");
    fill(connect[0], connect[0] + 200 * 200, false);
    int n; cin >> n;

    int x[n],y[n],p[n];

    for(int i=0; i<n; i++) {
        cin >> x[i] >> y[i] >> p[i];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int squareDist = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            if(squareDist <= p[i] * p[i]) {
                connect[i][j] = true;
            }
        }
    }

    int ret(1);

    for(int i=0; i<n; i++){
        bool canHear[n];
        fill(canHear, canHear +n, false);
        ret = max(ret,dfs(n,i,canHear));


    }

    cout << ret;
}

