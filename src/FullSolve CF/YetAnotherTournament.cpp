#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>

#define ll long long
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    int t; cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<pair<int,int>> prep(n);
        int ourWins(0);
        vector<int> wins(n);
        for(int i=0; i<n; i++){
            wins[i] = i;
            int x; cin >> x;
            prep[i] = {i,x};
        }
        sort(prep.begin(), prep.end(), [](auto &left, auto &right) {
            return left.second < right.second;
        });

        for(int i=0; i<n; i++){
            if(m - prep[i].second >= 0){
                ourWins++;
            }else{
                wins[i]++;
            }
        }

        int place = n+1;
        for(int i=0; i<n; i++){
            if(wins[i] <= ourWins){
                place--;
            }
        }
        cout << place << endl;




    }
}