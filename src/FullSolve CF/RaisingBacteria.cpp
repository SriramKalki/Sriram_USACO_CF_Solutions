#include <iostream>

using namespace std;
#define ll long long
int main(){
    ll x,z;

    cin >> x;
    z=x;
    ll y=1;
    ll bacteria =0;
    bool flag = true;
    while(flag){
        //find the max powers of 2 in a number
        while(x - y >= 0){
            y*=2;
        }
        y /= 2;
        x-=y;
        y=1;
        bacteria++;
        if(x == 1){
            bacteria++;
            flag = false;
        }
        if(x == 0){
            flag = false;
        }





    }
    cout << bacteria;

}