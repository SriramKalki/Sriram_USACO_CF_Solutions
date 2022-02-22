#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int array[n];
    int sum=0;
    int minimalsum=0;
    int coins =0;
    for(int i=0; i<n; i++){
        cin >> array[i];
        sum += array[i];
    }
    sort(array, array +n,greater<int>());

    for(int i=0; i<n; i++){
        coins++;
        minimalsum+=array[i];
        if(minimalsum > sum-minimalsum){
            cout << coins;
            return 0;
        }
    }


}