#include <iostream>

using namespace std;


void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}


int main(){
    setIO("shuffle");
    int n;
    cin >>  n;
    int swap[n],current[n],previous[n],posSwap[n];
    for(int i=0; i<n; i++){
        cin >> swap[i];

        swap[i]--;
        posSwap[swap[i]] = i;
    }
    for(int i=0; i<n; i++){
        cin >> current[i];
        previous[i] = current[i];

    }

    for(int i=0; i<3; i++){
        for(int j=0; j<n; j++){
            current[posSwap[j]] = previous[j];
        }
        for(int j=0; j<n; j++){
            previous[j] = current[j];

        }
    }
    for(int i=0; i<n; i++){
        cout << current[i] << endl;
    }


}