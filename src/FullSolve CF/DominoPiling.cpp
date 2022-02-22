#include <iostream>

using namespace std;
int main(){
    int M=0;
    int N=0;
    cin >> M;
    cin >> N;

    if(M*N %2 == 1){
        cout << (M*N+1)/(2) -1;

    }else{
        cout << (M*N)/2;
    }





}