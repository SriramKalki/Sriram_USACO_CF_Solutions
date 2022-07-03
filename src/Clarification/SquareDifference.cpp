#include <iostream>
#include <cmath>

using namespace  std;
#define ll long long
int main(){
    int t;
    cin >>t;
    for(int i=0; i<t; i++){
        ll a,b;
        cin >> a >> b;
        if(a-b == 1){
            bool prime = true;
            //a+b now needs to be checked to be prime
            for(int j=2; j <= floor(sqrt(a+b)); j++){
                if((a+b) % j == 0){
                    prime = false;
                    break;
                }
            }
            if(prime){cout << "YES" << endl;}else{cout << "NO" << endl;}

        }else{
            cout << "NO" << endl;
        }

    }

}