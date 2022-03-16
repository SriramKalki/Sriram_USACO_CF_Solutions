#include <iostream>
#include <cmath>

#define ll long long

using namespace std;


int main(){
    int t;
    cin >> t;

    for(int i=0; i<t; i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;

        int totalLanterns = floor(a/b);
        int blockedLanterns = floor((double)d/(double)b) - ceil((double)c/(double)b) + 1;
        cout << totalLanterns - blockedLanterns << endl;
    }


}