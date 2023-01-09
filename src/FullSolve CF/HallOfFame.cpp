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
    int t;
    cin >> t;

    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        vector<char> a(n);
        int currR(INT32_MAX),currL(-1);
        for(int j=0; j<n; j++){
            cin >> a[j];
            if(a[j] == 'R'){
                currR = min(currR,j);
            }else if(a[j] == 'L'){
                currL = max(currL,j);
            }
        }

        if(currR > n || currL < 0){
            //no R or L, not possible
            cout << -1 << endl;
            continue;
        }else if(currR < currL){
            //already possible
            cout << 0 << endl;
            continue;
        }

        for(int j=0; j<n-1; j++){
            if(a[j] == 'L' && a[j+1] == 'R'){
                //swapping will work
                cout << (j+1) << endl;
                //account for one indexing
                break;
            }
        }

    }
}