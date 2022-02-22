#include <iostream>

using namespace std;
#define ll long long
int main(){
    ll t;
    cin >> t;

    for(int i=0; i<t; i++){
        ll x,y,a,b;
        cin >> x >> y >> a >> b;
        ll maximum(max(x,y)),minimum(min(x,y));
        cout << min(b*(minimum) + a*(maximum-minimum),a*(maximum + minimum)) << endl;


    }




}