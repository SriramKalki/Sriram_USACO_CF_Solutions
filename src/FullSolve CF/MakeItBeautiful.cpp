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
    while(t--){
        int n;
        cin >> n;
        int array[n];
        for(int i=0; i<n; i++){
            cin >> array[i];
        }

        sort(array, array + n, greater<int>());

        if(array[0] == array[n-1]){
            cout << "NO" << endl;

        }else{
            cout << "YES" << endl;
            cout << array[n-1] << " ";
            for(int i=0; i<n-1; i++){
                cout << array[i] << " ";
            }
            cout << endl;
        }
    }
}