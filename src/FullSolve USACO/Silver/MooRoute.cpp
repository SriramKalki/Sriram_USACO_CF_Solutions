#include <vector>
#include <string>
#include <iostream>
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

int main(){
    int n;
    cin >> n;
    int array[n];
    int fmin = INT32_MAX;
    int total = 0;
    for(int i=0; i<n; i++){
        cin >> array[i];
        total += array[i];
        fmin = min(array[i],fmin);
    }
    for(int i=0; i<fmin-1; i++){
        string curr = i % 2 == 0 ? "R" : "L";

        for(int j=0; j<n; j++){
            array[j]--;
            total--;
            cout << curr;
        }
    }

    bool right = true;
    for(int i=n-1; i>=0; i--){
        if(array[i] == 1) continue;
        fmin = array[i];

        int j = i;
        while(array[j] >= fmin && j >= 0){
            array[j] -= (fmin - 1);
            j--;
        }

        for(int k=0; k < fmin-1; k++){
            right = !right;
            string curr = right ? "R" : "L";
            for(int p1 = i; p1 > j; p1--) {
                cout << curr;
                total--;
            }

        }
        while(total--){cout << "L";}


    }
}