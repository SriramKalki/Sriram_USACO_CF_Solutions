#include <iostream>

using namespace std;
#define ll long long
int main(){
    ll n,t;
    cin >> n >> t;
    //goal array[t-1];
    ll array[n];
    for(int i=0; i<n; i++){
        cin >> array[i];
        array[i] +=i;
    }
    //when t is equal to n
    ll position(0);
    for(int i=0; i<n; i++){
        if(position == t-1){
            cout << "YES";
            return 0;
        }
        if(position < n-1){
            position = array[position];
        }

    }
    cout << "NO";





}