#include <bits/stdc++.h>

using namespace std;

int dp[1000][1001];
void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
int main() {
    setIO("paintbarn");
    int n, k;
    cin >> n >> k;
    while(n--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for(int j=b; j<d; j++){
            dp[j][a]++;
            dp[j][c]--;
        }

    }
    int ret = 0;
    for(int i = 1; i < 1000; i++) {
        for(int j = 1; j < 1000; j++) {

            dp[i][j] += dp[i][j-1];
            if(dp[i][j] == k) ret++;
        }
    }
    cout << ret << endl;
}