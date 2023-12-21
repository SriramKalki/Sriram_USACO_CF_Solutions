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
    int t; cin >> t;

    for(int i=0; i <t; i++){
        ll  int n,k; cin >> n >> k;
        ll int length = floor(log2(n)) + 1;

        if(k >= length){
            cout << n + 1 << endl;
        }else if ( k < length){

            cout << pow(2,k) << endl;
        }

    }
}