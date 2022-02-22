#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int array[n];
    int sorts[n];

    for(int i=0; i<n;i++){
        cin >> array[i];
        sorts[i] = array[i]; //duplicate
    }
    sort(sorts, sorts+n);
    if(sorts[0] == sorts[1]){
        cout << "Still Rozdil";
        return 0;
    }//c
    for(int i=0; i<n;i++){
        if (sorts[0] == array[i]) {
            cout << i+1;
            return 0;
        }
    }




}