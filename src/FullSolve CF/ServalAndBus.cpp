#include <iostream>

using namespace std;

int main(){
    int n,t,x;
    cin >> n >> t;
    int firstArrival[n];
    int reoccur[n];
    int modulo[n];
    for(int i=0; i<n; i++){
        cin >> firstArrival[i];
        cin >> reoccur[i];
        modulo[i]= firstArrival[i] % reoccur[i];


    }
    bool on = false;

    while(!on){
        for(int i=0; i<n; i++){
            if(t>=firstArrival[i] && t % reoccur[i] == modulo[i]){
                cout << i+1 << endl;
                on = true;
                return 0;
            }
        }
        t++;
    }


}