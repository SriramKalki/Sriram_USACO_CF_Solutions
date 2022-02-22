#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    int n;
    int sum=0;
    int current;

    for(int i=0; i<t; i++){
        cin >> n;
        for(int j=0; j<n; j++){
            cin >> current;
            sum += current;


        }
        if(sum % n == 0){
            cout << 0 << endl;

        }else{
            cout << 1 << endl;
        }
        sum =0;


    }



}