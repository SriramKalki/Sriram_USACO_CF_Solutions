#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("cowsignal");
    int m,n,k;
    cin >> m >> n >> k;
    char array[m][n];
    string current;
    for(int i=0; i<m; i++){
        cin >> current;
        for(int j=0; j<n; j++){
            array[i][j] = current[j];
        }
    }

    for(int i=0; i<m; i++){
        //line
        for(int a = 0; a <k; a++){

            for(int j=0; j<n; j++){
                //character
                for(int p=0; p<k; p++){
                    cout << array[i][j];
                }

            }

            cout << endl;
        }
    }
    //each line



}