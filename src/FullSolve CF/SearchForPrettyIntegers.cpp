#include <iostream>
#include <bits/stdc++.h>
//Sriram's 50th problem yay

using namespace std;

int main(){
    int n,m;

    cin >> n >> m;
    int first[n],second[m];

    for(int i=0; i<n; i++){
        cin >> first[i];

    }
    for(int i=0; i<m; i++){
        cin >> second[i];

    }
    sort(first,first + n);
    sort(second,second+m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(first[i] == second[j]){
                cout << first[i];
                return 0;
            }

        }

    }
    if(first[0] >= second[0]){
        cout << second[0] << first[0];
    }else{
        cout << first[0] << second[0];
    }



}