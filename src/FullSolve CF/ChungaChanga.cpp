#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long long x,y,z;
    cin >> x >> y >> z;

    long long original = floor(x/z) + floor(y/z);
    long long maximum = floor((x+y)/z);
    long long a,b;
    if(original == maximum){
        cout << maximum << " " << 0;

    }else{
        if(x - (x % z) >= 0){
            a = min(x%z , z - (x%z));

        }

        if (y- (y%z) >= 0){

            b = min(y%z , z - (y%z));
        }

        cout << maximum << " " << min(a,b);
    }
}