#include <iostream>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;

    for(int i=0;i<t; i++){
        ll n;
        cin >> n;
        ll array[n];
        for(int j=0; j<n; j++){
            cin >> array[j];
        }
        bool pass = true;
        for(int j=0; j<n-1; j++){

            if(array[j+1] < array[j]){
                cout << "YES" << endl;

                pass = false;
                break;
            }
        }
        if(pass){
            cout << "NO" << endl;
        }

    }


}