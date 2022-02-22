#include <iostream>

using namespace std;

int main(){
    int n;
    cin >>n;
    int p[n],d[n],t[n];
    for(int i=0; i<n; i++){
        cin >> p[i];
    }
    for(int i=0; i<n; i++){
        cin >> t[i];
        d[i] = p[i]-t[i];
    }
    int answer(0);
    bool assumeDone(true);
    int counter(0);
    while(counter < n){
        assumeDone = true;
        if(d[counter] > 0){
            while(counter < n && d[counter] > 0){
                d[counter]--;
                counter++;

            }
            answer++;
            assumeDone = false;
        }else if(d[counter] <0){
            while(counter < n && d[counter] <0){
                d[counter]++;
                counter++;

            }
            answer++;
            assumeDone = false;
        }
        if(assumeDone && counter == n-1){
            break;
        }else if(assumeDone){
            counter++;
        }else{
            counter = 0;
        }
    }
    cout << answer;

}