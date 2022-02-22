#include <iostream>

using namespace std;

#define ll unsigned long long int

int main(){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        ll answer=0;
        ll p=0;
        for(int j=1; j<=n; j= j+2){
            answer += (j*j - (j-2)*(j-2)) * p ;
            p++;
        }
        cout << answer << endl;

    }


}