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
        int n; cin >> n;

        if(n == 1){
            cout << "YES" << endl << 1 << endl;
            continue;
        }else if(n == 2){
            cout << "YES" << endl << "9 5" << endl;
            continue;
        }else if(n == 3){
            cout << "NO" << endl;
            continue;
        }else if(n % 2 == 0){
            cout << "YES" << endl;
            for(int j=0; j<n; j++){
                cout << (j %2 == 0? -1 : 1) << " ";
            }
            cout << endl;
            continue;
        }

        cout << "YES" << endl;
        int tot(1);
        int first = ((3-n)/2);
        int second = tot - first;

        for(int j=0; j<n; j++){

            if(j % 2 == 0){
                cout << first << " ";
            }else{
                cout << second << " ";
            }
        }

        cout << endl;


    }

}