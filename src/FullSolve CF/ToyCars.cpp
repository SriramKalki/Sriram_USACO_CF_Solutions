#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int results[n];
    int goodCars[n];
    bool undefeat = true;
    int x=0;
    for(int i=0; i<n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> results[j];
            if (results[j] == 3 || results[j] == 1) {
                undefeat = false;
            }

        }
        if(undefeat){
            goodCars[x] = i+1;
            x++;
        }
        undefeat = true;
    }
    cout << x << endl;
    for(int i=0; i<x; i++){
        cout << goodCars[i] << " ";
    }



}