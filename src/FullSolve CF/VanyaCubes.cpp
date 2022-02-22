#include<iostream>

using namespace std;

int main(){
    int n=0;
    int i=1;
    cin >> n;
    while(n >= i*(i+1)*(i+2)/6 ){
        i++;

    }
    cout << i-1;

}