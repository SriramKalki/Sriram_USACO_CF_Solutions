#include <iostream>

using namespace std;


int main() {
    long long n=0;
    long long k=0;
    cin >> n;
    cin >> k;
    long long odd=0;
    long long even=0;
    if(n % 2 ==0){
        odd =n/2;
        even = n/2;
    }else{
        odd = (n+1)/2;
        even = (n-1)/2;

    }
    if(k <= odd){
        cout << 2*k-1;

    }else{
        cout << (k-odd)*2;
    }
}