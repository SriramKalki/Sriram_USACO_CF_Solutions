#include <iostream>


using namespace std;

int main(){
    int n;
    cin >> n;
    int array[n];

    for(int i=0; i<n; i++){
        cin >> array[i];


    }
    int answer =0;
    for(int i=1; i<n-1; i++){
        if((array[i] > array[i-1] && array[i] > array[i+1]) || (array[i] < array[i-1] && array[i] < array[i+1])){
            answer++;
        }

    }
    cout << answer;


}