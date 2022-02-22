#include <iostream>

using namespace std;

int main(){
    double n,k,x;
    cin >> n;
    cin >> k;
    double sum=0;
    double average=0;
    int answer =0;
    for(int i=0; i<n; i++){
        cin >> x;
        sum += x;

    }
    average = sum/n;
    while(sum/n < k-0.5){
        sum += k;
        n++;
        answer++;
    }
    cout << answer;



}