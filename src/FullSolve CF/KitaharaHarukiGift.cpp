#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int sum=0;
    int current;
    int twohundred =0;
    int onehundred =0;
    for(int i=0; i<n; i++){
        cin >> current;
        sum += current;
        if(current == 200){
            twohundred++;
        }else{
            onehundred++;
        }
    }
    int average = sum /2;

    if(sum % 200 != 0){
        cout << "NO";
        return 0;
    }else{
        for(int i=0; i<=twohundred; i++){
            for(int j=0; j<= onehundred; j++){
                if(200*i + 100*j == average){

                    cout << "YES";
                    return 0;
                }
            }
        }
        cout << "NO";
        return 0;
    }



}