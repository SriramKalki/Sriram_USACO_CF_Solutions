#include <iostream>

using namespace std;
#define ll long long
int main() {
    ll n;
    cin >> n;
    ll k,x;
    for(int i=0; i<n; i++){
        cin >> k >> x;
        cout << x + 9*(k-1) << endl;

    }


}